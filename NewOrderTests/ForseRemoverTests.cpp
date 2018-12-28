#include "stdafx.h"
#include "ForseRemover.h"

class ForseRemoverTests : public ::testing::Test
{
public:
    ForseRemoverTests() {}
    void SetUp()
    {
        m_remover = force::ForceRemover(std::string("testText").begin());
    }

protected:
    force::ForceRemover m_remover;
};

TEST_F(ForseRemoverTests, CreateRemoveIteratorInstanceIsnoNull)
{
    EXPECT_NE(nullptr, &m_remover);
}

TEST_F(ForseRemoverTests, ForseRemoverIteratorBeginIsEQBegin)
{
    force::ForceRemover removeIter = force::ForceRemover(std::string("testText").begin());

    EXPECT_FALSE(true);
}