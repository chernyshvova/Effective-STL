#include "stdafx.h"
#include "Securities.h"
#include <iostream>
//containers
//vector, list, map, stack, deque

template<typename pair1, typename pair2>
void InstertInContainer(std::map<pair1, pair2>& cont, const size_t countTimes)
{
    static int g_guid = 0;
    for (int i = 0; i < countTimes; ++i)
    {
        Securities newSecurities;
        newSecurities.m_guid = g_guid++;
        cont[i] = newSecurities;
    }
}

template<typename pair1>
void InstertInContainer(std::stack<pair1>& cont, const size_t countTimes)
{
    static int g_guid = 0;
    for (int i = 0; i < countTimes; ++i)
    {
        Securities newSecurities;
        newSecurities.m_guid = g_guid++;
        cont.push(newSecurities);
    }
}

template<typename Container>
void InstertInContainer(Container& cont, const size_t countTimes)
{
    static int g_guid = 0;
    for (int i = 0; i < countTimes; ++i)
    {
        Securities newSecurities;
        newSecurities.m_guid = g_guid++;
        cont.insert(cont.end(), newSecurities);
    }
}


TEST(TrampSecurities, InsertInVectorManyTimes)
{
    std::vector<Securities> target;
    InstertInContainer(target, 1000);
    EXPECT_EQ(1000, target.size());
}

TEST(TrampSecurities, InsertInListManyTimes)
{
    std::list<Securities> target;
    InstertInContainer(target, 1000);
    EXPECT_EQ(1000, target.size());
}

TEST(TrampSecurities, InsertInMapManyTimes)
{
    std::map<int, Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 1000);
    EXPECT_EQ(1000, target.size());
}

TEST(TrampSecurities, InsertInStackManyTimes)
{
    std::stack<Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 1000);
    EXPECT_EQ(1000, target.size());
}
TEST(TrampSecurities, InsertInDequeManyTimes)
{
    std::deque<Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 1000);
    EXPECT_EQ(1000, target.size());
}
