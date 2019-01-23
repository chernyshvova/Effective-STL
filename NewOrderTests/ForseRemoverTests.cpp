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
    std::string test = s_testsData;

    force::ForceRemover remover(test.begin());

    //test.erase(std::remove(*remover.get(), test.end(), ' '),
        //test.end());
    std::cout << test << '\n';
    //auto res = std::remove(test.begin(), test.end(), 'f');
    auto res2 = std::remove<ForceIterator>(remover, test.end(), '1');
    //test.erase(force::ForceRemover(test.begin()), test.end());
    
    EXPECT_EQ("n  but ki", test);
}
