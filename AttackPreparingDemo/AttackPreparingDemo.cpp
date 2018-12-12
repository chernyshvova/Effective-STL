// AttackPreparingDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ArmyManager.h"

int main()
{

    std::cout << "creating army...." << std::endl;
    Army army = CreateArmy(200);
    std::cout << "creating army is done!\nArmy size is " << army.size() << " squads" << std::endl;
    std::vector<Cruiser> Ships(10);
    std::cout << "filling ship..." << std::endl;
    for (auto& cruiser : Ships)
    {
        FillShips(army, cruiser);
    }
    std::cout << "filling ship is done" << std::endl;
    std::cout << "getiing army from ship..." << std::endl;
    for (auto& cruiser : Ships)
    {
        Army resultArmy;
        
        EmptyShips(resultArmy, cruiser);
    }
    std::cout << "getiing army from ship is done" << std::endl;
   
    return 0;
}

