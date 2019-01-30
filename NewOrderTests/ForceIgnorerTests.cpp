#include "stdafx.h"
#include "ForceIgnorer.h"

namespace
{
    std::string s_testsData = "no force but cookie";
}

class ForseIngnorerTests : public ::testing::Test
{
public:
    ForseIngnorerTests() {}
    void SetUp()
    {
        m_ignorer = force::ForceIgnorer(s_testsData.begin());
    }

protected:
    force::ForceIgnorer m_ignorer;
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
    res.resize(expect.size());
    std::string noforce_text(force::ForceIgnorer(s_testsData.begin()), force::ForceIgnorer(s_testsData.end()));
    EXPECT_EQ(expect, noforce_text);
}

