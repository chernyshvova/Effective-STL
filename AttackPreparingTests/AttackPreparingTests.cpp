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

TEST(ArmyManager, CreateColumnWithoutArmy)
{
    Army army;

    EXPECT_THROW(CreateColumn(army, details::g_rankCount), std::exception);
}

TEST(ArmyManager, CreateColumnWithCorrectArmy)
{
    Army army = CreateArmy();
    std::string expectStr = { "BABABCBCBC" };
    std::vector<char> expect(expectStr.begin(), expectStr.end());
    Column result = CreateColumn(army, 1);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(9, army.begin()->size());
}

TEST(ArmyManager, CreateColumnWuth10SquadsWithCorrectArmy)
{
    Army army = CreateArmy();
    Column result = CreateColumn(army, 11);
    EXPECT_EQ(details::g_rankCount * 11, result.size());
    EXPECT_EQ(199, army.size());
}

TEST(ArmyManager, CreateColumnManyTimes)
{
    Army army = CreateArmy();

    CreateColumn(army, details::g_rankCountInArmy);
    
    EXPECT_EQ(0, army.size());
}