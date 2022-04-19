#include <iostream>
//#include "Monster.h" if it demands a header then go ahead and impliment it.
#include <string>
#include <tuple>
#include <random>


class Monster
{
	//string methods
	std::string MonsterCombat(); // the method that combat calls to run the monsters turn
	std::string ChooseSpell(); // method used for desiding the spell if any that monster uses
	std::string UseSpell(); // process and uses spell based on name

	//int methods
	int MagicAttack();
	int Attack(); //method used for monsters basic attack
	int GetHealth(); // gets the enemyHealth

	//void methods
	void TakeDamage(int); // method for reducing monster health when player attacks
	void SpellAttack(std::string); // contain the damage value of the spells...
	void Buff(std::string);
	void Heal();//method that heals the monster based on heal variable (also changes heal variable based on spell
	
	//private variables
private:
	int enemyHealth = 20; // monsters health pool, when this hits 0 the monster object should be destroyed as it has been defeated
	int enemyMana = 0; // monster mana pool, used for when the monster casts a spell, reducing the pool, when it hits 0 or spell cost is > the mana pool the monster cannot cast a spell and defualts to attack
	int damageBonus = 0; // used when the monster is buffed via magic to increase its damageValue for the damage it deals.
	int damageValue = 4; // bases monster damage value.
	bool isMonsterAlive = true; // identifies if the monster is alive or not, if false then combat should destroy the object and reward player
	std::string spellsKnown[3] = { "Heal", "FireBolt", "Attack-Up" };
	std::string spellChoice = "";// sets the name of the spell that the monster has chosen
	int heal = 0;
	int magicDam = 0;

	//public variables
public:
	std::string monsterName = "Monster"; // identifier of the monster

	//public methods
public:
	std::string MonsterCombat()
	{
		if (enemyMana >0)
		{
			float choice = rand() % 100 + 1;
			if (choice >=1 and choice <50)
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

	void TakeDamage(int playerdamage)
	{
		enemyHealth -= playerdamage;
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

	//private methods
private:
	
	void SpellAttack(std::string spellName)//damageValue for monster
	{
		magicDam = 20; // set damage equal to value found in method spellDamage in spellIndex class
	}


	void Buff(std::string spellName)// changes a damage value for monster
	{
		damageBonus += 5;// set damage bonus equal to the value found in method spellBuff from spellIndex class

	}


	void Heal()//heals monster
	{
		heal = 5;// set heal value based on method in spellIndex spellHeal
		enemyHealth += heal;
	}

	/*std::tuple<int, std::string> MergeOutput()
	{
		return std::make_tuple(damageValue, monsterName);
	}
 */
};
	