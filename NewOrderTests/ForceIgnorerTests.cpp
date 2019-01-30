#include "stdafx.h"
#include "ForceIgnorer.h"
#include "TestData.h"

class ForseIngnorerTests : public ::testing::Test
{
public:
    ForseIngnorerTests() {}
    void SetUp()
    {
        m_testData = testData::GetWithForce();
        m_ignorer = force::ForceIgnorer(m_testData.begin());
    }

protected:
    force::ForceIgnorer m_ignorer;
    std::string m_testData;
};

TEST_F(ForseIngnorerTests, CreateRemoveIteratorInstanceIsnoNull)
{
    EXPECT_NE(nullptr, &m_ignorer);
}

TEST_F(ForseIngnorerTests, GetValueAndReturnChar)
{
    EXPECT_EQ('n', *m_ignorer);
}

TEST_F(ForseIngnorerTests, CursorMovedForward)
{
    m_ignorer++;
    EXPECT_EQ('o', *m_ignorer);
}

TEST_F(ForseIngnorerTests, IgnorerskipsSeveralSkipedChars)
{
    m_ignorer++;
    EXPECT_EQ('o', *m_ignorer);
    m_ignorer++;
    EXPECT_EQ(' ', *m_ignorer);
}

TEST(ForseRemoverTest, IgnorerskipsSeveralSkipedChars)
{
    std::string expect = "n  but ki";
    std::string res;
    std::string testData = testData::GetWithForce();
    res.resize(expect.size());
    std::string noforce_text(force::ForceIgnorer(testData.begin()), force::ForceIgnorer(testData.end()));
    EXPECT_EQ(expect, noforce_text);
}

