#include "stdafx.h"
#include "Securities.h"
#include "Operation.h"
#include <iostream>
using namespace trampOperation;

//containers
//vector, list, map, stack, deque

namespace{
    
    const size_t s_iteration_count = 1000;
    const size_t s_itemCount = 100;
    const size_t s_removeCount = 50;
    const size_t s_findCount = 100;
}


class VectoreTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        InsertManyTimes(m_vector, s_iteration_count, s_itemCount);
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
        InsertManyTimes(m_list, s_iteration_count, s_itemCount);
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
        InsertManyTimes(m_map, s_iteration_count, s_itemCount);
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
        InsertManyTimes(m_stack, s_iteration_count, s_itemCount);
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
        InsertManyTimes(m_deque, s_iteration_count, s_itemCount);
    }

    virtual void TearDown()
    {
        m_deque.clear();
    }

public:
    std::deque<Securities> m_deque;
};

TEST(InsertInVectorTest, InsertInVectorManyTimes)
{
    std::vector<Securities> vector;
    InsertManyTimes(vector, s_iteration_count, s_itemCount);
    EXPECT_EQ(100000, vector.size());
}

TEST_F(VectoreTest, RemoveFromVectorManyTimes)
{
    RemoveManyTimes(m_vector, s_itemCount, s_removeCount);
    EXPECT_EQ(95000, m_vector.size());
}

TEST_F(VectoreTest, FindInVector)
{
    EXPECT_NO_THROW(FindManyTimes(m_vector, s_itemCount, s_findCount));
}

TEST(InsertInListTest, InsertInListManyTimes)
{
    std::list<Securities> list;
    InsertManyTimes(list, s_iteration_count, s_itemCount);
    EXPECT_EQ(100000, list.size());
}

TEST_F(ListTest, RemoveFromListManyTimes)
{
    RemoveManyTimes(m_list, s_itemCount, s_removeCount);
    EXPECT_EQ(95000, m_list.size());
}

TEST_F(ListTest, FindInList)
{
    EXPECT_NO_THROW(FindManyTimes(m_list, s_itemCount, s_findCount));
}


TEST(InsertInMapTest, InsertInMapManyTimes)
{
    std::map<int, Securities> map;
    InsertManyTimes(map, s_iteration_count, s_itemCount);
    EXPECT_EQ(100000, map.size());
}

TEST_F(MapTest, RemoveFromMapManyTimes)
{
    RemoveManyTimes(m_map, s_itemCount, s_removeCount);
    EXPECT_EQ(95000, m_map.size());
}

TEST_F(MapTest, FindInMap)
{
    EXPECT_NO_THROW(FindManyTimes(m_map, s_itemCount, s_findCount));
}

TEST(InsertInStackTest, InsertInStackManyTimes)
{
    std::stack<Securities> stack;
    InsertManyTimes(stack, s_iteration_count, s_itemCount);
    EXPECT_EQ(100000, stack.size());
}

TEST_F(StackTest, RemoveFromStackManyTimes)
{
    RemoveManyTimes(m_stack, s_itemCount, s_removeCount);
    EXPECT_EQ(95000, m_stack.size());
}

//TEST_F(StackTest, FindInStack)
//{
//    EXPECT_NO_THROW(FindManyTimes(m_stack, s_itemCount, s_findCount));
//}

TEST(InsertInDequeTest, InsertInDequeManyTimes)
{
    std::deque<Securities> deque;
    InsertManyTimes(deque, s_iteration_count, s_itemCount);
    EXPECT_EQ(100000, deque.size());
}

TEST_F(DequeTest, RemoveFromDequeManyTimes)
{
    RemoveManyTimes(m_deque, s_itemCount, s_removeCount);
    EXPECT_EQ(95000, m_deque.size());
}

TEST_F(DequeTest, FindInDeque)
{
    EXPECT_NO_THROW(FindManyTimes(m_deque, s_itemCount, s_findCount));
}



