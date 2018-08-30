#include "stdafx.h"
#include <list>
#include <iterator>

std::list<char> CreateClones( std::list<char>& initialSoldiersSquad, size_t requestedArmySize)
{
    size_t size = initialSoldiersSquad.size();
    size_t centralSoldierPos = size / 2;

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

    initialSoldiersSquad.push_back(*centralSoldier);
    initialSoldiersSquad.push_front(*centralSoldier);

    return initialSoldiersSquad;
}