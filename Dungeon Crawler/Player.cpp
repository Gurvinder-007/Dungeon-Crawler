#include "Player.h"

Player::Player()
{
    name = ""; PlayerClass = ""; gender = ""; weaponequipped = "basic sword";
    playerClass = { "tank", "balanced", "mage" };
    gold = 0; exp = 0; potion = 0; level = 0; weapondamage = 5;

    settotalhealth(0);
    settotalmana(0);
    setstamina(0);
}

void Player::playerCreation() {
    int count = 5;

    std::cout << "What is your player name?" << std::endl;
    std::cin >> name;

    std::cout << "What class do you want to pick for " << name << "?" << std::endl;
    std::cin >> PlayerClass;

    std::for_each(PlayerClass.begin(), PlayerClass.end(), [](char& c) {
        c = ::tolower(c);
        });

        if (PlayerClass == "tank")
        {
            settotalhealth(100);
            settotalmana(50);
            setstamina(40);
        }
        else if (PlayerClass == "balanced")
        {
            settotalhealth(60);
            settotalmana(70);
            setstamina(65);
        }
        else if (PlayerClass == "mage")
        {
            settotalhealth(30);
            settotalmana(100);
            setstamina(90);
        }
        else {
            settotalhealth(50);
            settotalmana(50);
            setstamina(50);
        }
  

    std::cout << "What gender is " << name << "?" << std::endl;
    std::cin >> gender;

    for (int i = 0; i < count; i++)
    {
        std::cout << "Please wait while your character is being created.... Time elapsed " << i <<std::endl;
        Sleep(350);
        system("cls");
    }


    name[0] = toupper(name[0]);
    PlayerClass[0] = toupper(PlayerClass[0]);
    gender[0] = toupper(gender[0]);
}






