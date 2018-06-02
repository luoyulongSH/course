//
// Created by luoyulong on 18/5/27.
//

#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <list>
#include "../../src/structure/list.h"
class TestList: public testing::Test
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
TEST_F(TestList, test_list_base)
{
    List<int> list;
    for (int i = 0; i < 100; ++i)
    {
        list.push_back(i);
        ASSERT_EQ(list.size(), i + 1);
    }
    ASSERT_EQ(list.size(), 100);
    for (int i = 0; i < 100; ++i)
    {
        ASSERT_EQ(list.front(), i);
        list.pop_front();
    }
}

TEST_F(TestList, test_list_2)
{
    List<int> list;
    for (int i = 5; i < 10; ++i)
    {
        list.push_back(i);
    }

    for (int i = 4; i >= 0; -- i)
    {
        list.push_front(i);
    }

    ASSERT_EQ(list.size(), 10);
    for (int i = 0; i < 10; ++ i)
    {
        ASSERT_EQ(list.front(), i);
        list.pop_front();
    }
}

TEST_F(TestList, test_list_3)
{
    List<int> list;
    for (int i = 5; i < 10; ++i)
    {
        list.push_back(i);
    }

    for (int i = 4; i >= 0; -- i)
    {
        list.push_front(i);
    }

    list.clear();

    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(list.begin() == list.end());
}

TEST_F(TestList, test_list_4)
{
    List<int> list;
    for (int i = 5; i < 10; ++i)
    {
        list.push_back(i);
    }

    for (int i = 4; i >= 0; -- i)
    {
        list.push_front(i);
    }

    int i = 0;
    for (List<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        ASSERT_EQ(*iter, i++);
    }


}