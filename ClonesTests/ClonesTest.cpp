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
