#pragma once
#include "stdafx.h"


using Rank = std::list<char>;
using Squad = std::list<Rank>;
using Army = std::list<Squad>;
using Column = std::vector<char>;

Rank CreateRank();
Squad CreateSquad();
Army CreateArmy();
Column CreateColumn(Army& army, const size_t columnVolume);

namespace details
{
    const size_t g_rankCount = 10;
    const size_t g_squadCount = 200;
    const size_t g_rankCountInArmy = 4000;
}