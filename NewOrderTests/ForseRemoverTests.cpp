#include "stdafx.h"
#include "ForseRemover.h"
#include <algorithm>
#include <string>
#include <iostream>

namespace {
    std::string s_testsData = "no force but cookie";
    std::string s_skepedText = "force";
}

class ForseRemoverTests : public ::testing::Test
{
public:
    ForseRemoverTests() {}
    void SetUp()
    {
        m_remover = force::ForceRemover(s_testsData.begin(), s_skepedText);
    }

protected:
    force::ForceRemover m_remover;
};

TEST_F(ForseRemoverTests, CreateRemoveIteratorInstanceIsnoNull)
{
    EXPECT_NE(nullptr, &m_remover);
}

TEST_F(ForseRemoverTests, CursorReturnsChar)
{
    EXPECT_EQ('n', *m_remover);
}

TEST_F(ForseRemoverTests, CursorMovedForward)
{
    m_remover++;
    EXPECT_EQ(' ', *m_remover);
}

TEST_F(ForseRemoverTests, RemoverskipsOneCharO)
{
    m_remover++;
    EXPECT_NE('o', *m_remover);
}

TEST_F(ForseRemoverTests, RemoverskipsSeveralSkipedChars)
{
    m_remover++;
    EXPECT_EQ(' ', *m_remover);
    m_remover++;
    EXPECT_EQ(' ', *m_remover);
}

TEST(ForseRemoverTest, RemoverskipsSeveralSkipedChars)
{
    force::ForceRemover remover(s_testsData.begin(), "force");
    std::remove((std::string::iterator)remover, s_testsData.end(), '#');
    
}
