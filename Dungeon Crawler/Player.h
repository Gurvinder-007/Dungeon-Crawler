#pragma once
#include "Header.h"

class Player
{

private:
    int totalhealth;
    int totalmana;
    int totalstamina;

public:
    Player();

    std::string name, gender, weaponequipped;
    int weapondamage, potion, level, exp;
    std::vector<std::string> playerClass;
    std::string PlayerClass;

    int gold;

    void settotalhealth(int health)
    {
        totalhealth = health;
    }

    void damagetotalhealth(int damage)
    {
        totalhealth = totalhealth - damage;
    }

    int gettotalhealth()
    {
        return totalhealth;
    }

    void increasetotalhealth(int heal)
    {
        totalhealth = totalhealth + heal;
    }

    void settotalmana(int mana)
    {
        totalmana = mana;
    }

    void addmana(int manaincrease)
    {
        totalmana = totalmana + manaincrease;
    }

    void usemana(int manause)
    {
        totalmana = totalmana - manause;
    }

    void setstamina(int stamina)
    {
        totalstamina = stamina;
    }

    void decreasestamina(int staminadecrease)
    {
        totalstamina = totalstamina - staminadecrease;
    }

    void increasestamina(int staminaincr)
    {
        totalstamina = totalstamina + staminaincr;
    }

    int getstamina()
    {
        return totalstamina;
    }

    int gettotalmana()
    {
        return totalmana;
    }

    void playerCreation();

};

