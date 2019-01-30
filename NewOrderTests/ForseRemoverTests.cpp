#include "stdafx.h"
#include "ForseRemover.h"
#include "TestData.h"

class ForseRemoverTests : public ::testing::Test
{
public:
    ForseRemoverTests() {}
    void SetUp()
    {
        m_testData = testData::GetWithForce();
        m_remover = force::ForceRemover(m_testData.begin());
    }

protected:
    force::ForceRemover m_remover;
    std::string m_testData;
};

TEST_F(ForseRemoverTests, GetValueAndReturnChar)
{
    EXPECT_EQ('n', *m_remover);
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndReturnTrue)
{
    EXPECT_TRUE(m_remover == m_testData.begin());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndReturnFalse)
{
    force::ForceRemover remover(testData::GetWithForce().begin());
    EXPECT_FALSE(remover == testData::GetWithForce().end());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndNotEQuealsAndReturnFalse)
{
    EXPECT_FALSE(m_remover != testData::GetWithForce().begin());
}

TEST_F(ForseRemoverTests, CompareWithIteratorAndNotEQuealsAndReturnTrue)
{
    force::ForceRemover remover(testData::GetWithForce().begin());
    EXPECT_TRUE(remover != testData::GetWithForce().end());
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
    EXPECT_TRUE(m_remover < m_testData.end());
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
    std::string testData = testData::GetWithForce();
    res.resize(expect.size());
    std::copy<force::ForceRemover>(force::ForceRemover(testData.begin()), testData.end(),
        (force::ForceRemover)res.begin());

    EXPECT_EQ(expect, res);
}