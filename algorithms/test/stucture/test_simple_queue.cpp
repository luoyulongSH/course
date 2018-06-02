//
// Created by luoyulong on 18/5/12.
//
//
// Created by luoyulong on 18/4/29.
//

#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <list>
#include "../../src/structure/simple_queue.h"
#include "../../src/traits/traits_demo.h"
class TestSimpleQueue: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};

using  namespace algo;
TEST_F(TestSimpleQueue, queue_front)
{
    SimpleQueue<int> queue;
    for (int i = 0; i < 100; ++i)
    {
        queue.push_back(i);
    }

    for (int i = 0; i < 100; ++i)
    {
        ASSERT_EQ(queue.front(), i);
        queue.pop_front();
    }


}


TEST_F(TestSimpleQueue, queue_back)
{
    SimpleQueue<int> queue;
    for (int i = 99; i >= 0; --i)
    {
        queue.push_front(i);
    }

    for (int i = 0; i >= 100; --i)
    {
        ASSERT_EQ(queue.back(), i);
        queue.pop_back();
    }
}



TEST_F(TestSimpleQueue, queue)
{
    SimpleQueue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.push_back(i);
    }

    for (int i = 0; i < 5; ++ i)
    {
        queue.pop_front();
    }

    for (int i = 10; i < 100; ++i)
    {
        queue.push_back(i);
    }

    for (int i = 5; i < 100; ++i )
    {
        ASSERT_EQ(queue.front(), i);
        queue.pop_front();
    }

}

TEST_F(TestSimpleQueue, queue_iterator)
{

    SimpleQueue<int> queue;

    for (int i = 10; i < 100; ++i)
    {
        queue.push_back(i);
    }
    int i = 10;
    int j = 0;
    for (SimpleQueue<int>::Iterator iter = queue.begin();  iter != queue.end() ; ++iter) {
        ASSERT_EQ(iter.index, i - 10);
        ASSERT_EQ(queue[j++], i);
        ASSERT_EQ(*iter, i ++ );
    }
}

TEST_F(TestSimpleQueue, queue_point)
{

    int arr[10];
    std::list<int> list;
    SimpleQueue<int*> queue;
    SimpleQueue<const int *> q2;

    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i;
        queue.push_back(arr + i);
        q2.push_back(arr + i);
    }
    int i = 0;
    for (SimpleQueue<int*>::Iterator iter = queue.begin();  iter != queue.end() ; ++iter) {
        ASSERT_EQ(**iter, i ++ );
    }
}

