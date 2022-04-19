#pragma once

#include "Header.h"

class Monster
{

	//private variables
protected:
	int enemyHealth = 0; // monsters health pool, when this hits 0 the monster object should be destroyed as it has been defeated
	int enemyMana = 0; // monster mana pool, used for when the monster casts a spell, reducing the pool, when it hits 0 or spell cost is > the mana pool the monster cannot cast a spell and defualts to attack
	int damageBonus = 0; // used when the monster is buffed via magic to increase its damageValue for the damage it deals.
	int damageValue = 10; // bases monster damage value.
	//bool isMonsterAlive = true; // identifies if the monster is alive or not, if false then combat should destroy the object and reward player
	std::string spellsKnown[3] = { "Heal", "FireBolt", "Attack-Up" };
	std::string spellChoice = "";// sets the name of the spell that the monster has chosen
	int heal = 0;
	int magicDam = 0;
	int manaCost = 0;
	int totalMana = 0;

	//public variables
public:
	std::string monsterName = "Monster"; // identifier of the monster

	//public methods
public:
	std::string MonsterCombat()
	{
		if (enemyMana > 0)
		{
			int choice = rand() % 100 + 1;
			if (choice >= 1 && choice < 50)
			{
				return "attack";
			}
			else
			{
				return "spell";
			}
		}
		else
		{
			return "attack";
		}


	}

	std::string ChooseSpell()
	{
		int spellSelector = rand() % 3; // generates random number between 0 and 2
		spellChoice = spellsKnown[spellSelector]; // sets spellChoice to a spell found in spellKnown
		return spellChoice; // returns spellChoice
	}

	std::string UseSpell()
	{
		if (spellChoice == "Heal") // run heal method with a heal variable used for heal spell form spell index.
		{

			Heal();
			// int heal = spellHeal(spellChoice);

			return ("Enemy Restored by " + std::to_string(heal) + " amount.");

		}
		else if (spellChoice == "Attack-Up")
		{
			//damageBonus = spellBuff(spellChoice); // Takes the spell choice and goes into a spell buff method in soon to be class spellIndex to get the buff amount
			Buff(spellChoice);

			return ("Enemy buffed with " + spellChoice + " by " + std::to_string(damageBonus) + "."); // changed for a more specified one if a future buff method in enemy
		}
		else if (spellChoice == "FireBolt")
		{
			//int magicDam gets set by method spellDamage from spellIndex class
			SpellAttack(spellChoice);
			return ("Enemey Attacks with " + spellChoice + " dealing " + std::to_string(magicDam) + ".");
		}

	}

	int MagicAttack()
	{
		return (magicDam);
	}

	int Attack()
	{
		int dealDamage = damageBonus + damageValue;
		damageBonus = 0;
		return (dealDamage);
	}

	int GetHealth()
	{
		return(enemyHealth);
	}

	void SetHealth(int health)
	{
		enemyHealth = health;
	}

	int SetMana(int mana)
	{
		enemyMana = mana;
	}

	int SetDamageVal(int damageVal)
	{
		damageValue = damageVal;
	}

	int TakeDamage(int damage)
	{
		enemyHealth -= damage;
	}

	//private methods
protected:

	void SpellAttack(std::string spellName)//damageValue for monster
	{
		manaCost = 10;
		enemyMana -= manaCost;
		magicDam = 10; // set damage equal to value found in method spellDamage in spellIndex class
	}


	void Buff(std::string spellName)// changes a damage value for monster
	{
		manaCost = 5;
		enemyMana -= manaCost;
		damageBonus += 5;// set damage bonus equal to the value found in method spellBuff from spellIndex class

	}


	void Heal()//heals monster
	{
		manaCost = 5;
		enemyMana -= manaCost;
		heal = 5;// set heal value based on method in spellIndex spellHeal
		enemyHealth += heal;
	}

	/*std::tuple<int, std::string> MergeOutput()
	{
		return std::make_tuple(damageValue, monsterName);
	}
 */

public:
	void CreateMonster();
};

class Grunt : public Monster
{
protected:
	int enemyHealth = 30;
	int enemyMana = 20;


public:
	std::string monsterName = "Grunt";



};

class Tank : public Monster
{
protected:
	int enemyHealth = 50;
	int enemyMana = 10;
	int damageValue = 10;
	std::string spellsKnown[1] = { "Greater_Heal" };

public:
	std::string monsterName = "Tank";

public:
	std::string MonsterCombat()
	{
		if (enemyMana > 0)
		{
			int choice = rand() % 100 + 1;
			if (choice >= 1 && choice < 76)
			{
				return "attack";
			}
			else
			{
				return "spell";
			}
		}
		else
		{
			return "attack";
		}


	}

	std::string ChooseSpell()
	{
		spellChoice = "Greater_Heal"; // sets spellChoice to a spell found in spellKnown
		return spellChoice; // returns spellChoice
	}

	std::string UseSpell()
	{
		if (spellChoice == "Greater_Heal") // run heal method with a heal variable used for heal spell form spell index.
		{

			Heal();
			// int heal = spellHeal(spellChoice);

			return ("Enemy Restored by " + std::to_string(heal) + " amount.");

		}
	}

protected:
	void Heal()//heals monster
	{
		manaCost = 10;
		enemyMana -= manaCost;
		heal = 10;// set heal value based on method in spellIndex spellHeal
		enemyHealth += heal;
	}
};

class Mage : public Monster
{
protected:
	int enemyHealth = 20;
	//int enemyMana = 100;
	int damageValue = 3;
	std::string spellsKnown[5] = { "Firebolt", "Fireball", "Attack-Up", "StaminaDrain", "ManaDrain" };
	std::string attributeType = "";

public:
	std::string monsterName = "Mage";

public:
	std::string MonsterCombat()
	{
		if (enemyMana > 0)
		{
			int choice = rand() % 100 + 1;
			if (choice >= 1 && choice < 11)
			{
				return "attack";
			}
			else
			{
				return "spell";
			}
		}
		else
		{
			return "attack";
		}


	}

	std::string ChooseSpell()
	{
		int spellSelector = rand() % 5; // generates random number between 0 and 4.
		spellChoice = spellsKnown[spellSelector]; // sets spellChoice to a spell found in spellKnown
		return spellChoice; // returns spellChoice
	}

	std::string UseSpell()
	{
		if (spellChoice == "StaminaDrain" || "ManaDrain") // run heal method with a heal variable used for heal spell form spell index.
		{
			AttributeDrain(spellChoice);

			return ("Enemy Drains your strength by  " + std::to_string(heal) + " amount.");

		}
		else if (spellChoice == "Attack-Up")
		{
			//damageBonus = spellBuff(spellChoice); // Takes the spell choice and goes into a spell buff method in soon to be class spellIndex to get the buff amount
			Buff(spellChoice);

			return ("Enemy buffed with " + spellChoice + " by " + std::to_string(damageBonus) + "."); // changed for a more specified one if a future buff method in enemy
		}
		else if (spellChoice == "Firebolt" || "Fireball")
		{
			//int magicDam gets set by method spellDamage from spellIndex class
			SpellAttack(spellChoice);
			return ("Enemey Attacks with " + spellChoice + " dealing " + std::to_string(magicDam) + ".");
		}

	}

protected:
	void SpellAttack(std::string spellName)//damageValue for monster
	{
		if (spellName == "Firebolt")
		{
			if (enemyMana >= 10)
			{
				manaCost = 10;
				enemyMana -= manaCost;
				magicDam = 10;

			}
			else
			{
				magicDam = 0;
			}

		}
		else if (spellName == "Fireball")
		{
			if (enemyMana >= 20)
			{
				manaCost = 20;
				enemyMana -= manaCost;
				magicDam = 25;

			}
			else
			{
				magicDam = 0;
			}

		}

		// set damage equal to value found in method spellDamage in spellIndex class
	}
	void AttributeDrain(std::string spellName)
	{
		if (spellName == "StaminaDrain")
		{
			if (enemyMana >= 20)
			{
				manaCost = 20;
				enemyMana -= manaCost;
				magicDam = 20;
			}
			else
			{
				magicDam = 0;
			}

		}
		else if ("ManaDrain")
		{
			magicDam = 20;
			enemyMana += magicDam;
			if (enemyMana > totalMana)
			{
				enemyMana = totalMana;
			}

		}
	}

public:
	std::string AttributeTarget(std::string spellName)
	{
		if (spellName == "StaminaDrain")
		{
			return("Stamina");

		}
		else if ("ManaDrain")
		{
			return("Mana");

		}
	}

};