#include "stdafx.h"
#include <list>

std::list<char> CreateClones(const std::list<char>& initialSoldiersSquad, size_t requestedArmySize)
{
    if (requestedArmySize < initialSoldiersSquad.size())
    {
        throw std::exception("The soldier is more than necessary");
    }

    return initialSoldiersSquad;
}