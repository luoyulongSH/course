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
#include "../../src/structure/queue.h"
#include "../../src/traits/traits_demo.h"
class TestQueue: public testing::Test
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
TEST_F(TestQueue, queue_front)
{
    Queue<int> queue;
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


TEST_F(TestQueue, queue_back)
{
    Queue<int> queue;
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



TEST_F(TestQueue, queue)
{
    Queue<int> queue;
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

TEST_F(TestQueue, queue_iterator)
{



    Queue<int> queue;

    for (int i = 10; i < 100; ++i)
    {
        queue.push_back(i);
    }
    int i = 10;
    for (Queue<int>::Iterator iter = queue.begin();  iter != queue.end() ; ++iter) {
        ASSERT_EQ(iter.head, i - 10);
        ASSERT_EQ(*iter, i ++ );
    }
}

TEST_F(TestQueue, queue_point)
{

    int arr[10];
    std::list<int> list;
    Queue<int*> queue;
    Queue<const int *> q2;

    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i;
        queue.push_back(arr + i);
        q2.push_back(arr + i);
    }
    int i = 0;
    for (Queue<int*>::Iterator iter = queue.begin();  iter != queue.end() ; ++iter) {
        ASSERT_EQ(**iter, i ++ );
    }
}

TEST_F(TestQueue, queue_point2)
{
    Queue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.push_back(i);
    }


   std::reverse(queue.q_begin(), queue.q_end());
    int i = 10;
    for (Queue<int>::Iterator iter = queue.begin();  iter != queue.end() ; ++iter) {
        ASSERT_EQ(*iter,  --i);
    }
}

