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
    Army army = CreateArmy();
    EXPECT_EQ(army.size(), 200);
}

TEST(ArmyManager, CreateColumnWithoutArmy)
{
    Army army;

    EXPECT_THROW(CreateColumnFromArmy(army, details::g_solderInRank), std::exception);
}

TEST(ArmyManager, CreateColumnWithCorrectArmy)
{
    Army army = CreateArmy();
    std::string expectStr = { "BABABCBCBC" };
    std::vector<char> expect(expectStr.begin(), expectStr.end());
    Column result = CreateColumnFromArmy(army, 1);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(19, army.begin()->size());
}

TEST(ArmyManager, CreateColumnWuth10SquadsWithCorrectArmy)
{
    Army army = CreateArmy();
    Column result = CreateColumnFromArmy(army, 21);
    EXPECT_EQ(details::g_solderInRank * 21, result.size());
    EXPECT_EQ(199, army.size());
}

TEST(ArmyManager, CreateColumnManyTimes)
{
    Army army = CreateArmy();

    CreateColumnFromArmy(army, details::g_rankCountInArmy);
    
    EXPECT_EQ(0, army.size());
}

TEST(ArmyManager, CreateColumnFromSquadCount)
{
    Army army = CreateArmy();
    Column result = CreateColumnFromSquad(army, 20);//20 Squads
    EXPECT_EQ(details::g_squadCountInArmy * 20, result.size());
}

TEST(ArmyManager, GetArmyFromColumn)
{
    Army army = CreateArmy();
    Column solders = CreateColumnFromSquad(army, details::g_squadCountInCruiser);

    Army result = GetArmyFromColumn(solders);
    EXPECT_EQ(20, result.size());
    EXPECT_EQ(20, result.begin()->size());
    EXPECT_EQ(10, result.begin()->begin()->size());
    EXPECT_EQ(0, solders.size());
}

TEST(ArmyManager, FillShips)
{
    Army army = CreateArmy();
    Cruiser result; 
    FillShips(army, result);
    EXPECT_EQ(20, result.size());
    EXPECT_EQ(0, army.size());
}

TEST(ArmyManager, EmptyShips)
{
    Army resultArmy;
    Army fullArmy = CreateArmy();
    Cruiser cruiser;
    FillShips(fullArmy, cruiser);

    EmptyShips(resultArmy, cruiser);
    EXPECT_EQ(20, resultArmy.size());
    EXPECT_EQ(0, cruiser.size());
}