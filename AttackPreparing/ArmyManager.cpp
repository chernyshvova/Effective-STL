#include "stdafx.h"
#include "ArmyManager.h"
#include "Clones.h"

namespace
{
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
    initialSoldiersSquad = CreateClones(initialSoldiersSquad, details::g_solderInRank);
    return initialSoldiersSquad;
}

Squad CreateSquad()
{
    Squad squad(details::g_rankInSquad);

    std::transform(squad.begin(), squad.end(), squad.begin(), FillCreateSquad);
    return squad;
}

Army CreateArmy(const size_t size)
{
    Army army(size);

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
        count--;

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
    
    Column col = CreateColumnFromArmy(army, details::g_rankCountInCruiser);
    Army armyForCruiser = GetArmyFromColumn(col, 2);

    for (int i = 0; i < details::g_squadCountInCruiser; ++i)
    {
        cruiser.push(*armyForCruiser.begin());
    }
}

Army GetArmyFromColumn(Column& column, const size_t rancCountInSquad)
{
    Army army;

    for (int i = 0; i < rancCountInSquad; ++i)
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

void EmptyShips(Army& army, Cruiser& cruiser)
{
    for (int i = 0; i < details::g_rankInSquad; ++i)
    {
        army.push_back(cruiser.top());
        cruiser.pop();
    }
}