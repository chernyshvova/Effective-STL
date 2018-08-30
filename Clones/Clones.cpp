#include "stdafx.h"
#include <list>
#include <iterator>

std::list<char> CreateClones( std::list<char>& initialSoldiersSquad, size_t requestedArmySize)
{
    size_t size = initialSoldiersSquad.size();
    size_t centralSoldierPos = size / 2;
    size_t armyDiff = requestedArmySize - size;

    if (requestedArmySize < size)
    {
        throw std::exception("The soldier is more than necessary");
    }
    if (requestedArmySize == size)
    {
        return initialSoldiersSquad;
    }

    std::list<char>::const_iterator centralSoldier = initialSoldiersSquad.begin();

    for (size_t i = 0; i < centralSoldierPos; centralSoldier++, ++i) {}

    std::list<char>::const_iterator leftSoldier;
    std::list<char>::const_iterator rightSoldier;

    leftSoldier = centralSoldier;
    rightSoldier = centralSoldier;

    if (size % 2)
    {
        initialSoldiersSquad.push_back(*centralSoldier);
        initialSoldiersSquad.push_front(*centralSoldier);
        rightSoldier++;
        armyDiff-=2;
    }

    leftSoldier--;

    bool rightFlag = true;
    for (int i = 0; i < armyDiff; ++i)
    {
        if (rightFlag)
        {
            initialSoldiersSquad.push_back(*rightSoldier);
            rightSoldier++;
        }
        else
        {
            initialSoldiersSquad.push_front(*leftSoldier);
            leftSoldier--;
        }

        rightFlag = !rightFlag;
    }

    return initialSoldiersSquad;
}