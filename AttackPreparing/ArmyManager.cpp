#include "stdafx.h"
#include "ArmyManager.h"
#include "Clones.h"

namespace
{
    const size_t g_rankSize = 20;
    const size_t g_solderSize = 10;
    const size_t g_squadSize = 200;

    const Rank& FillCreateSquad(Rank& rank)
    {
        rank = CreateRank();
        return rank;
    }
    const Squad& FillCreateArmy(Squad& squad)
    {
        squad = CreateSquad();
        return squad;
    }
}

Rank CreateRank()
{
    Rank initialSoldiersSquad{ 'A', 'B', 'C' };
    initialSoldiersSquad = CreateClones(initialSoldiersSquad, g_rankSize);
    return initialSoldiersSquad;
}
Squad CreateSquad()
{
    Squad squad(g_solderSize);
    
    std::transform(squad.begin(), squad.end(), squad.begin(), FillCreateSquad);
    return squad;
}

Army CreateArmy()
{
    Army army(g_squadSize);

    std::transform(army.begin(), army.end(), army.begin(), FillCreateArmy);
    return army;
}