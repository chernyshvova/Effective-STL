#include "stdafx.h"
#include "ArmyManager.h"
#include "Clones.h"

namespace
{
    const size_t g_rankSize = 10;
    const size_t g_solderSize = 20;
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

Column CreateColumnFromArmy(Army& army, const size_t rankCount)
{
    if (army.empty())
    {
        throw std::exception();
    }

    size_t count = rankCount;
    Column result;

    while (count)
    {
        count --;

        auto squadIterator = army.begin();
        auto rankIterator = squadIterator->begin();


        result.insert(result.begin(), std::make_move_iterator(rankIterator->begin()),
            std::make_move_iterator(rankIterator->end()));

        squadIterator->erase(rankIterator);

        if (squadIterator->empty())
        {
            army.erase(squadIterator);
        }
    }
    
    return result;
}

Column CreateColumnFromSquad(Army& army, const size_t columnVolume)
{
    if (army.empty())
    {
        throw std::exception();
    }

    return CreateColumnFromArmy(army, details::g_rankInSquad * columnVolume);
}

void FillShips(Army& army, Cruiser& cruiser)
{
    if (!cruiser.empty())
    {
        throw std::exception();
    }

    Column col = CreateColumnFromArmy(army, details::g_rankCountInArmy);
    Army armyForCruiser = GetArmyFromColumn(col);

    for (int i = 0; i < details::g_squadCountInCruiser; ++i)
    {
        cruiser.push(*armyForCruiser.begin());
    }
}

Army GetArmyFromColumn(Column& column)
{
    Army army;

    for(int i=0; i< details::g_rankInSquad; ++i)
    {
        Squad newSquad;
        for (int n = 0; n < details::g_squadCountInCruiser; ++n)
        {
            Rank newRank;
            newRank.insert(newRank.begin(), column.begin(), column.begin() + details::g_solderInRank);
            newSquad.push_back(newRank);
            column.erase(column.begin(), column.begin() + details::g_solderInRank);
        }
        army.push_back(newSquad);

    }
    return army;
}