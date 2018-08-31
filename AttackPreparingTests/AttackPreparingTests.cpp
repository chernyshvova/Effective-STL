#include "stdafx.h"
#include "ArmyManager.h"


TEST(ArmyManager, CreateRank)
{
    Rank rank =  CreateRank();
    EXPECT_EQ(rank.size(), 20);
}

TEST(ArmyManager, CreateSquad)
{
    Squad squad = CreateSquad();
    EXPECT_EQ(squad.size(), 10);
}

TEST(ArmyManager, CreateArmy)
{
    Army army = CreateArmy();
    EXPECT_EQ(army.size(), 200);
}