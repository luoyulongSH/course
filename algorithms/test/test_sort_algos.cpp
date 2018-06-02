//
// Created by luoyulong on 17/12/2.
//

#include <gtest/gtest.h>
#include "../src/sort_algo.h"

class TestSortAlgo: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};

TEST_F(TestSortAlgo, InsertSort)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = num - i;
    }

    std::random_shuffle(data.begin(), data.end());

    using  namespace algo;
    InsertSort(data);

    for (int i = 1; i < data.size(); ++i)
    {

        ASSERT_TRUE(data[i] > data[i - 1]);

    }
}


TEST_F(TestSortAlgo, MergeSort)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = i + 1;
    }
    std::random_shuffle(data.begin(), data.end());

    using  namespace algo;
    MergeSort( data );


    for (int i = 1; i < data.size(); ++i)
    {

        ASSERT_TRUE(data[i] > data[i - 1]);

    }
}
