#pragma once

#include  "Header.h"

class Shop {

private:
	int shopFunds = 100;


	int magicSwordDamage = 7, magicSwordPrice = 30;
	int bigBladeDamage = 10, bigBladePrice = 35;
	int manaEStaffDamage = 9, manaEStaffPrice = 5;
	int manaBStaffDamage = 30, manaBstaffPrice = 65;

public:

	std::string swordsInStock[3] = { "Magic Sword", "Big blade" };
	std::string staffsInStock[3] = { "Mana Efficient Staff", "Mana Boom Staff" };

	int ShopFunds() {
		return(shopFunds);
	}

	int MagicSwordDamage() {
		return(magicSwordDamage);
	}

	int MagicSwordPrice() {
		return(magicSwordPrice);
	}

	int BigBladeDamage() {
		return(bigBladeDamage);
	}

	int BigBladePrice() {
		return(bigBladePrice);
	}

	int ManaEStaffDamage() {
		return(manaEStaffDamage);
	}

	int ManaEStaffPrice() {
		return (manaEStaffPrice);
	}

	int ManaBStaffDamage() {
		return(manaBStaffDamage);

	}

	int ManaBStaffPrice() {
		return(manaEStaffPrice);
	}

	void DungeonShop();
	void Purchase();
};