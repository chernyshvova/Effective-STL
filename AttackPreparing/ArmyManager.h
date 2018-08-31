#pragma once
#include "stdafx.h"


using Rank = std::list<char>;
using Squad = std::vector<Rank>;
using Army = std::vector<Squad>;

Rank CreateRank();
Squad CreateSquad();
Army CreateArmy();