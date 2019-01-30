#include "stdafx.h"
#include "ForseRemover.h"

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
        m_remover = force::ForceRemover(s_testsData.begin());
    }

protected:
    force::ForceRemover m_remover;
};

TEST_F(ForseRemoverTests, GetValueAndReturnChar)
{
    EXPECT_EQ('n', *m_remover);
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndReturnTrue)
{
    EXPECT_TRUE(m_remover == s_testsData.begin());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndReturnFalse)
{
    force::ForceRemover remover(s_testsData.begin());
    EXPECT_FALSE(remover == s_testsData.end());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndNotEQuealsAndReturnFalse)
{
    EXPECT_FALSE(m_remover != s_testsData.begin());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndNotEQuealsAndReturnTrue)
{
    force::ForceRemover remover(s_testsData.begin());
    EXPECT_TRUE(remover != s_testsData.end());
}

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
    EXPECT_EQ('o', *m_remover);
}

TEST_F(ForseRemoverTests, CompareWithLessStringIteratorAndReturnTrue)
{
    EXPECT_TRUE(m_remover < s_testsData.end());
}

TEST_F(ForseRemoverTests, RemoverskipsSeveralSkipedChars)
{
    m_remover++;
    EXPECT_EQ('o', *m_remover);
    m_remover++;
    EXPECT_EQ(' ', *m_remover);
}

TEST(ForseRemoverTest, RemoverskipsSeveralSkipedChars)
{
    std::string expect = "n  but ki";
    std::string res;
    res.resize(expect.size());
    std::copy<force::ForceRemover>(force::ForceRemover(s_testsData.begin()), s_testsData.end(),
        (force::ForceRemover)res.begin());

    EXPECT_EQ(expect, res);
}