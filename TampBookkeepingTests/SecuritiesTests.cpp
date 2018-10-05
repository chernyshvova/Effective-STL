#include "stdafx.h"
#include "Securities.h"
#include <iostream>
//containers
//vector, list, map, stack, deque

template<typename Container, typename Value>
void Insert(Container& cont, Value value)
{
    cont.insert(cont.end(), value);
}

template<typename KeyType, typename ValueType>
void Insert(std::map<KeyType, ValueType>& cont, ValueType value)
{
    static int g_key = 0;
    cont[g_key++]= value;
}

template<typename Value, typename ValueType>
void Insert(std::stack<ValueType>& cont, Value value)
{
    cont.push(value);
}

template<typename Container>
void InstertInContainer(Container& cont, const size_t countTimes)
{
    static int g_guid = 0;
    for (int i = 0; i < countTimes; ++i)
    {
        Securities newSecurities;
        newSecurities.m_guid = g_guid++;
        Insert(cont, newSecurities);
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