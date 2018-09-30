// AttackPreparingDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ArmyManager.h"

int main()
{
    std::cout << "creating army" << std::endl;
    Army army = CreateArmy(200);
    std::cout << "creating army is done\narmy size is " << army.size() << " squads" << std::endl;
    Cruiser armyForShip;
    std::cout << "filling ship" << std::endl;
    FillShips(army, armyForShip);
    Army resultArmy;
    std::cout << "getiing army from ship is done" << std::endl;
    EmptyShips(resultArmy, armyForShip);
   
    return 0;
}

