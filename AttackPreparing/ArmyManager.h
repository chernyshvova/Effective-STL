#pragma once
#include "stdafx.h"


using Rank = std::list<char>;
using Squad = std::list<Rank>;
using Army = std::list<Squad>;
using Column = std::vector<char>;

using Cruiser = std::stack<Squad>;


Rank CreateRank();
Squad CreateSquad();
Army CreateArmy(const size_t size);
Column CreateColumnFromArmy(Army& army, const size_t columnVolume);
Column CreateColumnFromSquad(Army& army, const size_t columnVolume);
Army GetArmyFromColumn(Column& column, const size_t rancCountInSquad);
void FillShips(Army& army, Cruiser& cruiser);
void EmptyShips(Army& column, Cruiser& cruiser);

namespace details
{
    const size_t g_solderInRank = 10;
    const size_t g_rankInSquad = 20;
    const size_t g_solderInSquad = 200;
    const size_t g_squadCountInArmy = 200;
    const size_t g_rankCountInArmy = 4000;
    const size_t g_solderInCruiser = 4000;
    const size_t g_squadCountInCruiser = 20;
}