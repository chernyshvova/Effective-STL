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

//void PopRank(Column& col, Army& arm)
//{
//
//}

Column CreateColumn(Army& army, const size_t rankCount)
{
    if (army.empty())
    {
        throw std::exception();
    }

    size_t count = rankCount;
    Column result;

    //while (count)
    //{
    //    count --;
    //    result.insert(result.begin(), std::make_move_iterator(std::begin(army.begin()->pop_back())),
    //        std::make_move_iterator(std::end(army[0][0])));
    //    army[0].erase(army[0].begin());

    //    if (army[0].empty())
    //    {
    //        army.erase(army.begin());
    //    }
    //}
    

/*
    for (int i = 0, j=0; i*10 +j < rankCount; ++j)
    {

        result.insert(result.begin(),std::make_move_iterator(std::begin(army[i][j])),
            std::make_move_iterator(std::end(army[i][j])));
        
        army[i].erase(army[i].begin());

        if (army[i].empty())
        {
            army.erase(army.begin());
        }
        if (j >= army[i].size() - 1)
        {
            j = 0;
            i++;
        }

    }*/
    return result;
}
