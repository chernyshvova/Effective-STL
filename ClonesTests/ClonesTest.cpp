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
    std::list<char> expectSoldierSquad{ 'B', 'A', 'B', 'C', 'B' };//BABCB

    EXPECT_EQ(expectSoldierSquad, CreateClones(initialSoldiersSquad, 5));
}
