#include "stdafx.h"
#include "Clones.h"


TEST(CLONES, RETURN_THE_SAME_COUNT)
{
    std::list<char> initialSoldiersSquad  { 'A', 'B', 'C' };
    EXPECT_EQ(initialSoldiersSquad, CreateClones(initialSoldiersSquad, initialSoldiersSquad.size()));
}

TEST(CLONES, INPUTWRONGSIZEANDRETURNEXEPTION)
{
    std::list<char> initialSoldiersSquad{ 'A', 'B', 'C' };
    EXPECT_THROW(CreateClones(initialSoldiersSquad, 1), std::exception);
}

TEST(CLONES, CLONE_UNEVEN_ONE_TIME)
{
    std::list<char> initialSoldiersSquad{ 'A', 'B', 'C' };      //ABC 
    std::list<char> expectSoldierSquad{ 'A','B', 'A', 'B', 'C', 'B', 'C' };//ABABCBC 

    EXPECT_EQ(expectSoldierSquad, CreateClones(initialSoldiersSquad, 5));
}

TEST(CLONES, CLONE_EVEN_ONE_TIME)
{
    std::list<char> initialSoldiersSquad{ 'A', 'B' };      //AB
    std::list<char> expectSoldierSquad{ 'A', 'A', 'B', 'B' };//AABB

    EXPECT_EQ(expectSoldierSquad, CreateClones(initialSoldiersSquad, 4));
}

TEST(CLONES, CLONE_EVEN_MANY_TIMES)
{
    std::list<char> initialSoldiersSquad{ 'A', 'B' };      //AB
    std::list<char> expectSoldierSquad{ 'A','B','A','B','A','B','C','B','C','B','C' };//ABABABCBCBC 
    EXPECT_EQ(expectSoldierSquad, CreateClones(initialSoldiersSquad, 10));
}