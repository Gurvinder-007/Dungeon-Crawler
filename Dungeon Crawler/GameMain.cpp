#include "Player.h"
#include "Enemy.h"
#include "Shop.h"

void Combat();
void BattleHUD();
void Movement();
void FloorOne();
//void EndGame();
void IntroScreen();
void Leveling();
void CreateMonster();
void UsePotion();
void gamemenu();

int counter = 0;
int counterTwo = 0;
int counterThree = 0;
int MonsterHealthPoints = 0;
int MonsterCounter = 0;

Player player;

Grunt monster;

Shop shop;

int main() {

	IntroScreen();

	gamemenu();

	FloorOne();

	system("pause");

	return 0;
}

void gamemenu()
{
	int gselection;
	std::cout << "Game Menu" << std::endl << "Please choose an option by writing a number and pressing enter" << std::endl;
	std::cout << "1. Start" << std::endl << "2. Instructions" << std::endl << "3. Exit" << std::endl;
	std::cin >> gselection;
	if (gselection == 1)
	{
		player.playerCreation();
	}
	else if (gselection == 2)
	{
		int nzz;
		std::cout << "To play this game, you must choose an option 1. Start; Then you will have to choose your character name, class(we have 3 classes available! tank, balanced, mage, later after you dip into dungeon floor you will engage in combat with various monsters, as you progress you will earn experience which will make you level up your character which makes your character stronger, gold that you can spend on weapons or potions that will make your character strongeralso the monsters will become stronger" << std::endl;
		std::cout << "Input 1 to return to main menu" << std::endl;
		std::cin >> nzz;
		if (nzz == 1)
		{
			gamemenu();
		}
	}
	else if (gselection==3)
	{
		exit(0);
	}
}


void IntroScreen() {

	int counterTwo = 0;

	for (int i = 0; i <= counterTwo; i++) {
		if (i == 0) {
			std::cout << "Welcome ";
		}
		if (i == 1) {
			std::cout << "to ";
		}
		if (i == 2) {
			std::cout << "Dungeon Crawler";
		}
		if (i == 3) {
			std::cout << "\n\n";
			break;
		}
		counterTwo++;
		Sleep(1000);
	}
}

void GameHUD() {
	Sleep(500);
	system("cls");
	std::cout << "Name:" << player.name << "\nHealth: " << player.gettotalhealth() << "		Mana: " << player.gettotalmana() << "		Stamina: " << player.getstamina() << "\nClass: "  << player.PlayerClass
		<< "		Gender: " << player.gender << "\nXP: " << player.exp << "		Level: " << player.level << "\nGold: " << player.gold << "			Equipped weapon:" << player.weaponequipped <<  "\nMonster Counter: " << MonsterCounter << "		Potions: "<< player.potion <<std::endl;
	Movement();
}

void BattleHUD() {
	Sleep(500);
	system("cls");
	std::cout << "Name: " << player.name << "		|		Monster Name: " << monster.monsterName << "\nHealth: " << player.gettotalhealth() << "		|		Monster Health: " <<
		MonsterHealthPoints << "\nMana: " << player.gettotalmana() << std::endl;
}

std::string movementline1[4] = { "Throughout the movement in floor one you see many dead adventurers lying on the ground", "Thoughout the movement in floor one you start getting tired", "Throughout the movement in floor one you kill a few basic rats", "You wonder why you came in as the dungeon's horrible stench begins getting to you"};

std::string movementline2[4] = { "Upon getting further in you find an all use potion", "Upon getting further in you find a bit of gold", "Upon getting in you find a more corpses and some maps to help you navigate", "Upon getting further in you mind a few sleeping goblins and stab them all, giving you some bonus XP" };

std::string movementline3[4] = { "You see a dark passage lit by a single dim torch you use to vencher deeper", "You being hearing noises further into the dungeon", "You decide to sit down for a while but then", "You chicken out and decide to head back" };


void Movement() {

	int choice;
	int counterThree = 0;

	int Random = (rand() % 3);

	Leveling();

	std::cout << "\n\n";
	std::cout << "1. Move Through the dungeon floor ";
	std::cout << "\n2. Relax a bit";
	std::cout << "\n3. Go back";
	std::cout << "\n4. Shop";
	std::cout << "\n\n";

	std::cin >> choice;

	if (choice == 1) {
		
		for (int i = 0; i <= counterThree; i++) {
			if (i == 0) {
				std::cout << "\nAs you begin moving you find nothing worth noticing. But you keep moving.\n";
				Sleep(1000);
			}
			if (i == 1) {
				std::cout << movementline1[Random];
				Sleep(1000);
			}
			if (i == 3) {
				std::cout << movementline2[Random];
				if (Random == 1) {
					player.potion += 1;
				}
				if (Random == 2) {
					player.gold += 15;
				}
				if (Random == 3) {
					player.exp += 15;
				}
				Sleep(1000);
			}
			if (i == 3) {
				std::cout << "\nAs you keep moving ahead through the dungeon...\n";
				std::cout << movementline3[Random];
				std::cout << "you find it is time to fight!";
				Sleep(2000);
				if (MonsterCounter < 3) {
					CreateMonster();
					Combat();
					break;
				}
				if (MonsterCounter == 3) {
					EndGame();
					break;
				}
			}
		 counterThree++;
		}
	}
	else if (choice == 2) {
		std::cout << "You find a safe area and set up camp for the evening";
		if (player.gettotalhealth() <= 99) {
			player.increasetotalhealth(10);
			player.addmana(10);
			player.increasestamina(10);
		}
		std::cout << "After a rest your stats have now been slightly restored" << std::endl;
		Sleep(1000);
		GameHUD();
	}
	else if (choice == 3) {
		std::cout << "You decided to lose some progress by heading back for some reason";
		Sleep(1000);
		GameHUD();
	}
	else if (choice == 4) {
		shop.DungeonShop();
	}
	else {
		std::cout << "You entered wrong";
		Sleep(500);
		GameHUD();
	}
}

void Shop::DungeonShop() {
	do {
		std::cout << "Welcome to the shop" << std::endl;

		int counter = 0;

		for (int i = 0; i <= counter; i++) {
			if (i == 0) {
				std::cout << "Here are the available swords for purchase\n";
			}
			if (i == 1) {
				std::cout << "1." << swordsInStock[0] << std::endl;
				std::cout << "\nDamage: " << MagicSwordDamage() << "\nPrice: " << MagicSwordPrice() << std::endl;
			}
			if (i == 2) {
				std::cout << "\n2." << swordsInStock[1] << std::endl;
				std::cout << "\nDamage: " << BigBladeDamage() << "\nPrice: " << BigBladePrice() << std::endl;
			}
			if (i == 3) {
				std::cout << "\n3." << staffsInStock[0] << std::endl;
				std::cout << "\nDamage: " << ManaEStaffDamage() << "\nPrice: " << ManaEStaffPrice() << std::endl;
			}
			if (i == 4) {
				std::cout << "\n4." << staffsInStock[1] << std::endl;
				std::cout << "\nDamage: " << ManaBStaffDamage() << "\nPrice: " << ManaBStaffPrice() << std::endl;
			}
			if (i == 5) {
				std::cout << "\n5.All use potion" << std::endl;
				std::cout << "\Heals wounds, restores stamina and more magic. Price: 25" << std::endl;
			}
			if (i == 6) {
				Purchase();
				break;
			}
			counter++;
			Sleep(1000);
		}
	} while (player.gold >= 10);

	do {
		std::cout << "Sorry you cannot enter the shop since you have insufficient funds" << std::endl;
	} while (player.gold < 10);
}

void Shop::Purchase() {
	std::string purchase;
	std::cout << "So what would you like to purchase?\n";
	std::cin >> purchase;

	if (purchase == "1") {
		player.weapondamage=MagicSwordDamage();
		player.gold = player.gold - MagicSwordPrice();
		player.weaponequipped = shop.swordsInStock[0];
		std::cout << "\nThank your for your purchase";
		GameHUD();
	}
	if (purchase == "2") {
		player.weapondamage = BigBladeDamage();
		player.gold = player.gold - BigBladePrice();
		player.weaponequipped = shop.swordsInStock[1];
		std::cout << "\nThank your for your purchase";
		GameHUD();
	}
	if (purchase == "3") {
		player.weapondamage = ManaEStaffDamage();
		player.gold = player.gold - ManaEStaffPrice();
		player.weaponequipped = shop.staffsInStock[0];
		std::cout << "\nThank your for your purchase";
		GameHUD();
	}
	if (purchase == "4") {
		player.weapondamage = ManaBStaffDamage();
		player.gold = player.gold - ManaBStaffPrice();
		player.weaponequipped = shop.staffsInStock[1];
		std::cout << "\nThank your for your purchase";
		GameHUD();
	}
	if (purchase == "5") {
		player.potion += 1;
		player.gold = player.gold - 25;
	}
	else {
		GameHUD();
	}
}

void UsePotion() {
	player.increasetotalhealth(20);
	player.addmana(20);
	player.increasestamina(20);
}

 void CreateMonster() {
	 monster.SetHealth(20);
	 MonsterHealthPoints= monster.GetHealth();
}

void Combat() {

	BattleHUD();
	int playerAttack;
	int playerDamageValue = player.weapondamage;
	int playerSpellDamageValue = 8;


	while (player.gettotalhealth() >= 1 && MonsterHealthPoints >= 1 ) {
		std::cout << "" << std::endl;
		std::cout << "1. Melee Attack" << std::endl;
		std::cout << "2. Spell Attack" << std::endl;
		std::cout << "3. Drink Potion" << std::endl;
		//will do block later on when armor etc. are introduced
		std::cout << "" << std::endl;
		std::cin >> playerAttack;

		if (playerAttack == 1) {
			std::cout << player.name << " is attacking" << std::endl;
			std::cout << playerDamageValue << " was done to the monster" << std::endl;
			MonsterHealthPoints -= playerDamageValue;
			player.decreasestamina(10);
			Sleep(3000);
			if (MonsterHealthPoints >= 1) {
				std::cout << "" << std::endl;
				std::cout << "The monster is attacking..." << std::endl;
				if (monster.MonsterCombat() == "attack") {
					player.damagetotalhealth(monster.Attack());
					BattleHUD();
					Combat();
				}
				
			}
			if (player.gettotalhealth() <= 0) {
				player.settotalhealth(0); 
				system("cls");
				std::cout << "Game over!" << std::endl;
				Sleep(4000);
				exit(0);
			}
			else if (MonsterHealthPoints <= 0) {
				std::cout << "" << std::endl;
				std::cout << "You defeated the enemy monster" << std::endl;
				player.exp = player.exp + 100;
				MonsterCounter = MonsterCounter + 1;
				FloorOne();
			}
		}
		if (playerAttack == 2) {
			std::cout << player.name << " is casting a spell" << std::endl;
			std::cout << playerSpellDamageValue << " magic damage was done to the monster" << std::endl;
			MonsterHealthPoints -= playerSpellDamageValue;
			player.usemana(10);
			Sleep(3000);
			if (MonsterHealthPoints >= 1) {
				std::cout << "" << std::endl;
				std::cout << "The monster is attacking..." << std::endl;
				if (monster.MonsterCombat() == "attack") {
					player.damagetotalhealth(monster.Attack());
					BattleHUD();
					Combat();
				}
			}
			if (player.gettotalhealth() <= 0) {
				player.settotalhealth(0); 
					system("cls");
					std::cout << "Game over!" << std::endl;
					Sleep(4000);
					exit(0);
			}
			else if (MonsterHealthPoints <= 0) {
					std::cout << "" << std::endl;
					std::cout << "You defeated the enemy monster" << std::endl;
					player.exp = player.exp + 100;
					MonsterCounter = MonsterCounter +  1;
					FloorOne();
			}
		}
		if (playerAttack == 3) {
			if (player.potion >= 1) {
				UsePotion();
				player.potion -= 1;
				std::cout << "You have used the potion to restore some health" << std::endl;
				Sleep(500);
				BattleHUD();
				Combat();
			}
			else {
				std::cout << "Sorry you dont have any potions to use" << std::endl;
			}
		}
		else {
			std::cout << "Invalid input" << std::endl;
			Combat();
		}
	} 
}

void Leveling(){
	static const int needed_exp[] =
	{
	  0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000
	};
	//setup the numbers however u want, I did them so every 100 exp to be equal to 1 level

	while (player.exp >= needed_exp[player.level])
		++player.level;
	player.increasetotalhealth(25);
}

void FloorOne(){
	GameHUD();
	Movement();
}

void EndGame() {
	std::cout << "You won" << std::endl;
	exit(0);
}

