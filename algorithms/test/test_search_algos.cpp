//
// Created by luoyulong on 18/4/22.
//

#include <gtest/gtest.h>
#include "../src/search_algo.h"

class TestSearchAlgo: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};

TEST_F(TestSearchAlgo, BinarySearch)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = i ;
    }

    using  namespace algo;

    std::vector<int>::iterator iter;
    bool value = BinarySearch(data.begin(), data.end(), 100, &iter);
    ASSERT_TRUE(value);
    ASSERT_EQ(iter - data.begin(), 100);

}

