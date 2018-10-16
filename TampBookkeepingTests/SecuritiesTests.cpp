#include "stdafx.h"
#include "Securities.h"
#include "Operation.h"
#include <iostream>
using namespace trampOperation;

//containers
//vector, list, map, stack, deque


TEST(TrampSecurities, InsertInVectorManyTimes)
{
    std::vector<Securities> target;
    InstertInContainer(target, 100);
    EXPECT_EQ(100, target.size());
}

TEST(TrampSecurities, InsertInListManyTimes)
{
    std::list<Securities> target;
    InstertInContainer(target, 100);
    EXPECT_EQ(100, target.size());
}

TEST(TrampSecurities, InsertInMapManyTimes)
{
    std::map<int, Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 100);
    EXPECT_EQ(100, target.size());
}

TEST(TrampSecurities, InsertInStackManyTimes)
{
    std::stack<Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 100);
    EXPECT_EQ(100, target.size());
}

TEST(TrampSecurities, InsertInDequeManyTimes)
{
    std::deque<Securities> target;
    Securities newSecurities;
    InstertInContainer(target, 100);
    EXPECT_EQ(100, target.size());
}

TEST(TrampSecurities, RemoveFromVectorManyTimes)
{
    std::vector<Securities> target;
    InstertInContainer(target, 100);
    RemoveFromContainer(target, 50);
    EXPECT_EQ(50, target.size());
}

TEST(TrampSecurities, RemoveFromListManyTimes)
{
    std::list<Securities> target;
    InstertInContainer(target, 100);
    RemoveFromContainer(target, 50);
    EXPECT_EQ(50, target.size());
}

TEST(TrampSecurities, RemoveFromMapManyTimes)
{
    std::map<int, Securities> target;
    InstertInContainer(target, 100);
    RemoveFromContainer(target, 50);
    EXPECT_EQ(50, target.size());
}

TEST(TrampSecurities, RemoveFromStackManyTimes)
{
    std::stack<Securities> target;
    InstertInContainer(target, 100);
    
    RemoveFromContainer(target, 50);
    EXPECT_EQ(50, target.size());
}

TEST(TrampSecurities, RemoveFromDequeManyTimes)
{
    std::deque<Securities> target;
    InstertInContainer(target, 100);

    RemoveFromContainer(target, 50);
    EXPECT_EQ(50, target.size());
}

TEST(TrampSecurities, FindInVector)
{
    std::vector<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_TRUE(FindInConteiner(target, 10, searchResult));
    EXPECT_EQ(searchResult.m_guid, 10);
}

TEST(TrampSecurities, FindInVectorAndNotFoundReturnFalse)
{
    std::vector<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_FALSE(FindInConteiner(target, 10000, searchResult));
}

TEST(TrampSecurities, FindInList)
{
    std::list<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_TRUE(FindInConteiner(target, 10, searchResult));
    EXPECT_EQ(searchResult.m_guid, 10);
}

TEST(TrampSecurities, FindInListAndNotFoundReturnFalse)
{
    std::list<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_FALSE(FindInConteiner(target, 1000, searchResult));
}

TEST(TrampSecurities, FindInMap)
{
    std::map<int, Securities> target;
    InstertInContainer(target, 100);
    Securities searchResult;
    EXPECT_TRUE(FindInConteiner(target, 10, searchResult));
    EXPECT_EQ(searchResult.m_guid, 10);
}

TEST(TrampSecurities, FindInMapAndNotFound)
{
    std::map<int, Securities> target;
    InstertInContainer(target, 100);
    Securities searchResult;
    EXPECT_FALSE(FindInConteiner(target, 1000, searchResult));
}

TEST(TrampSecurities, FindInStack)
{
    std::stack<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_TRUE(FindInConteiner(target, 10, searchResult));
    EXPECT_EQ(searchResult.m_guid, 10);
}

TEST(TrampSecurities, FindInStackAnNotFoundREturnFalse)
{
    std::stack<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_FALSE(FindInConteiner(target, 1000, searchResult));
}

TEST(TrampSecurities, FindInDeque)
{
    std::deque<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_TRUE(FindInConteiner(target, 10, searchResult));
    EXPECT_EQ(searchResult.m_guid, 10);
}

TEST(TrampSecurities, FindInDequeAndNotFoundReturnFalse)
{
    std::deque<Securities> target;
    Securities searchResult;
    InstertInContainer(target, 100);
    EXPECT_FALSE(FindInConteiner(target, 1000, searchResult));
}