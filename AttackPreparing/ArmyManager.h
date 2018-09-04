#pragma once
#include "stdafx.h"


using Rank = std::list<char>;
using Squad = std::vector<Rank>;
using Army = std::vector<Squad>;
using Column = std::vector<char>;


Rank CreateRank();
Squad CreateSquad();
Army CreateArmy();
Column CreateColumn(Army& army, const size_t columnVolume);

namespace details
{
    const size_t g_rankCount = 20;
}