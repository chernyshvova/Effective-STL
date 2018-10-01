#include "stdafx.h"
#include "ArmyManager.h"


TEST(ArmyManager, CreateRank)
{
    Rank rank =  CreateRank();
    EXPECT_EQ(rank.size(), 10);
}

TEST(ArmyManager, CreateSquad)
{
    Squad squad = CreateSquad();
    EXPECT_EQ(squad.size(), 20);
}

TEST(ArmyManager, CreateArmy)
{
    Army army = CreateArmy(5);
    EXPECT_EQ(army.size(), 5);
}

TEST(ArmyManager, CreateColumnWithoutArmy)
{
    Army army;

    EXPECT_THROW(CreateColumnFromArmy(army, details::g_solderInRank), std::exception);
}

TEST(ArmyManager, CreateColumnWithCorrectArmy)
{
    Army army = CreateArmy(5);
    std::string expectStr = { "BABABCBCBC" };
    std::vector<char> expect(expectStr.begin(), expectStr.end());
    Column result = CreateColumnFromArmy(army, 1);
    EXPECT_EQ(expect, result);
}

TEST(ArmyManager, CreateColumnWuth10SquadsWithCorrectArmy)
{
    Army army = CreateArmy(5);
    Column result = CreateColumnFromArmy(army, 21);
    EXPECT_EQ(details::g_solderInRank * 21, result.size());
}

TEST(ArmyManager, CreateColumnManyTimes)
{
    Army army = CreateArmy(200);

    CreateColumnFromArmy(army, details::g_rankCountInArmy);
    
    EXPECT_EQ(0, army.size());
}

TEST(ArmyManager, CreateColumnFromSquadCount)
{
    Army army = CreateArmy(5);
    Column result = CreateColumnFromSquad(army, 1);
    EXPECT_EQ(details::g_squadCountInArmy * 1, result.size());
}

TEST(ArmyManager, GetArmyFromColumn)
{
    Army army = CreateArmy(20);
    Column solders = CreateColumnFromSquad(army, 2);

    Army result = GetArmyFromColumn(solders, 2);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(20, result.begin()->size());
    EXPECT_EQ(10, result.begin()->begin()->size());
    EXPECT_EQ(0, solders.size());
}

TEST(ArmyManager, FillShips)
{
    Army army = CreateArmy(200);
    Cruiser result; 
    FillShips(army, result);
    EXPECT_EQ(20, result.size());
    EXPECT_EQ(180, army.size());
}

TEST(ArmyManager, EmptyShips)
{
    Army resultArmy;
    Army fullArmy = CreateArmy(200);
    Cruiser cruiser;
    FillShips(fullArmy, cruiser);

    EmptyShips(resultArmy, cruiser);
    EXPECT_EQ(20, resultArmy.size());
    EXPECT_EQ(0, cruiser.size());
}