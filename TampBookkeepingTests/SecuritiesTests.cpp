#include "stdafx.h"
#include "Securities.h"
#include "Operation.h"
#include <iostream>
using namespace trampOperation;

//containers
//vector, list, map, stack, deque

class VectoreTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_vector, 1000, 100);
    }

    virtual void TearDown()
    {
        m_vector.clear();
    }

public:
    std::vector<Securities> m_vector;
};

class ListTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_list, 1000, 100);
    }

    virtual void TearDown()
    {
        m_list.clear();
    }

public:
    std::list<Securities> m_list;
};

class MapTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_map, 1000, 100);
    }

    virtual void TearDown()
    {
        m_map.clear();
    }

public:
    std::map<int,Securities> m_map;
};

class StackTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_stack, 1000, 100);
    }

    virtual void TearDown()
    {
        RemoveFromContainer(m_stack, m_stack.size());
    }

public:
    std::stack<Securities> m_stack;
};

class DequeTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_deque, 1000, 100);
    }

    virtual void TearDown()
    {
        m_deque.clear();
    }

public:
    std::deque<Securities> m_deque;
};

TEST(InsertInVectoreTest, InsertInVectorManyTimes)
{
    std::vector<Securities> vector;
    InsertManyTimes(vector, 1000, 100);
    EXPECT_EQ(100000, vector.size());
}

TEST_F(VectoreTest, RemoveFromVectorManyTimes)
{
    RemoveManyTimes(m_vector, 1000, 50);
    EXPECT_EQ(50000, m_vector.size());
}

TEST_F(VectoreTest, FindInVector)
{
    EXPECT_NO_THROW(FindManyTimes(m_vector, 1000, 100));
}

TEST(InsertInListTest, InsertInListManyTimes)
{
    std::list<Securities> list;
    InsertManyTimes(list, 1000, 100);
    EXPECT_EQ(100000, list.size());
}

TEST_F(ListTest, RemoveFromListManyTimes)
{
    RemoveManyTimes(m_list, 1000, 50);
    EXPECT_EQ(50000, m_list.size());
}

TEST_F(ListTest, FindInList)
{
    EXPECT_NO_THROW(FindManyTimes(m_list, 1000, 100));
}


TEST(InsertInMapTest, InsertInMapManyTimes)
{
    std::map<int, Securities> map;
    InsertManyTimes(map, 1000, 100);
    EXPECT_EQ(100000, map.size());
}

TEST_F(MapTest, RemoveFromMapManyTimes)
{
    RemoveManyTimes(m_map, 1000, 50);
    EXPECT_EQ(50000, m_map.size());
}

TEST_F(MapTest, FindInMap)
{
    EXPECT_NO_THROW(FindManyTimes(m_map, 1000, 100));
}

TEST(InsertInStackTest, InsertInStackManyTimes)
{
    std::stack<Securities> stack;
    InsertManyTimes(stack, 1000, 100);
    EXPECT_EQ(100000, stack.size());
}

TEST_F(StackTest, RemoveFromStackManyTimes)
{
    RemoveManyTimes(m_stack, 1000, 50);
    EXPECT_EQ(50000, m_stack.size());
}

//TEST_F(StackTest, FindInStack)
//{
//    EXPECT_NO_THROW(FindManyTimes(m_stack, 1000, 100));
//}

TEST(InsertInDequeTest, InsertInDequeManyTimes)
{
    std::deque<Securities> deque;
    InsertManyTimes(deque, 1000, 100);
    EXPECT_EQ(100000, deque.size());
}

TEST_F(DequeTest, RemoveFromDequeManyTimes)
{
    RemoveManyTimes(m_deque, 1000, 50);
    EXPECT_EQ(50000, m_deque.size());
}

TEST_F(DequeTest, FindInDeque)
{
    EXPECT_NO_THROW(FindManyTimes(m_deque, 1000, 100));
}




