#include <iostream>
using namespace std;


void Combat() {

	BattleHUD();
	int playerAttack;
	int playerDamageValue = player.weapondamage;
	int playerSpellDamageValue = 8;


	while (player.gettotalhealth() >= 1 && MonsterHealthPoints >= 1 ) {
		cout << "" << std::endl;
		cout << "1. Melee Attack" << endl;
		cout << "2. Spell Attack" << endl;
		cout << "3. Drink Potion" << endl;
		//will do block later on when armor etc. are introduced
		cout << "" << std::endl;
		cin >> playerAttack;

		if (playerAttack == 1) {
			cout << player.name << " is attacking" << endl;
			cout << playerDamageValue << " was done to the monster" << endl;
			MonsterHealthPoints -= playerDamageValue;
			player.decreasestamina(10);
			Sleep(3000);
			if (MonsterHealthPoints >= 1) {
				cout << "" << endl;
				cout << "The monster is attacking..." << endl;
				if (monster.MonsterCombat() == "attack") {
					player.damagetotalhealth(monster.Attack());
					BattleHUD();
					Combat();
				}
				
			}
			if (player.gettotalhealth() <= 0) {
				player.settotalhealth(0); 
				system("cls");
				cout << "Game over!" << endl;
				Sleep(4000);
				exit(0);
			}
			else if (MonsterHealthPoints <= 0) {
				cout << "" << std::endl;
				cout << "You defeated the enemy monster" << endl;
				player.exp = player.exp + 100;
				MonsterCounter = MonsterCounter + 1;
				FloorOne();
			}
		}
		if (playerAttack == 2) {
			cout << player.name << " is casting a spell" << endl;
			cout << playerSpellDamageValue << " magic damage was done to the monster" << endl;
			MonsterHealthPoints -= playerSpellDamageValue;
			player.usemana(10);
			Sleep(3000);
			if (MonsterHealthPoints >= 1) {
				cout << "" << std::endl;
				cout << "The monster is attacking..." << endl;
				if (monster.MonsterCombat() == "attack") {
					player.damagetotalhealth(monster.Attack());
					BattleHUD();
					Combat();
				}
			}
			if (player.gettotalhealth() <= 0) {
				player.settotalhealth(0); 
					system("cls");
					cout << "Game over!" << endl;
					Sleep(4000);
					exit(0);
			}
			else if (MonsterHealthPoints <= 0) {
					cout << "" << std::endl;
					cout << "You defeated the enemy monster" << endl;
					player.exp = player.exp + 100;
					MonsterCounter = MonsterCounter +  1;
					FloorOne();
			}
		}
		if (playerAttack == 3) {
			if (player.potion >= 1) {
				UsePotion();
				player.potion -= 1;
				cout << "You have used the potion to restore some health" << endl;
				Sleep(500);
				BattleHUD();
				Combat();
			}
			else {
				cout << "Sorry you dont have any potions to use" << endl;
			}
		}
		else {
			cout << "Invalid input" << endl;
			Combat();
		}
	} 
}