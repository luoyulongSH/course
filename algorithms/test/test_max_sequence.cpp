//
// Created by luoyulong on 18/4/29.
//

#include <gtest/gtest.h>
#include "../src/max_sequence_array.h"
#include <iostream>
#include <math.h>

class TestMaxSequence: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};


namespace std
{
    template <typename _TP>
    ostream& operator<< (ostream& out, const std::vector<_TP>& vec)
    {
        size_t size = vec.size();
        for (size_t i = 0; i < size - 1; ++ i)
        {
            out << vec[i] << ",";
        }
        if (size > 0)
        {
            out << vec[size - 1];
        }

        return out;
    }
}

using  namespace algo;
TEST_F(TestMaxSequence, max_seq)
{
    int num = 17000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = (i % 2 == 0)? i : -i ;
    }

    std::random_shuffle(data.begin(), data.end());

    typedef std::vector<int>::iterator iterator;
    std::tuple<iterator, iterator, int> result
            = GenerateMaxSequenceArray<iterator, int>( data.begin(), data.end() );

    std::tuple<iterator, iterator, int> result2
            = FindMaxSequence<iterator, int>(data.begin(), data.end());

    std::tuple<iterator, iterator, int> result3
            = FindMaxSequenceByLinear<iterator>(data.begin(), data.end());

//    std::cout << data <<"\n";

    {
        iterator begin, end;
        int sum ;
        std::tie(begin, end, sum) = result;
        std::cout << begin - data.begin() << " , " << end - data.begin()
                  << " , " << sum << "\n";
    }

    {
        iterator begin, end;
        int sum ;
        std::tie(begin, end, sum) = result2;
        std::cout << begin - data.begin() << " , " << end - data.begin()
                  << " , " << sum << "\n";
    }

    {
        iterator begin, end;
        int sum ;
        std::tie(begin, end, sum) = result3;
        std::cout << begin - data.begin() << " , " << end - data.begin()
                  << " , " << sum << "\n";
    }
}

TEST_F(TestMaxSequence, GenerateMaxSequenceArray)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = (i % 2 == 0)? i : -i ;
    }

    std::random_shuffle(data.begin(), data.end());

    typedef std::vector<int>::iterator iterator;

//    for (int i = 0; i < 1000; ++ i)
//    {
        std::tuple<iterator, iterator, int> result
                = GenerateMaxSequenceArray<iterator, int>( data.begin(), data.end() );
//    }
//    std::tuple<iterator, iterator, int> result
//            = GenerateMaxSequenceArray<iterator, int>( data.begin(), data.end() );


//    {
//        iterator begin, end;
//        int sum ;
//        std::tie(begin, end, sum) = result;
//        std::cout << begin - data.begin() << " , " << end - data.begin()
//                  << " , " << sum << "\n";
//    }
}

TEST_F(TestMaxSequence, FindMaxSequence)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = (i % 2 == 0)? i : -i ;
    }

    std::random_shuffle(data.begin(), data.end());

    typedef std::vector<int>::iterator iterator;

//    printf( "%lf %lf \n" ,log2(50), log2(30));
//    for (int i = 0 ; i < 1000; ++i ) {


        std::tuple<iterator, iterator, int> result
                = FindMaxSequence<iterator, int>(data.begin(), data.end());
//    }
//    {
//        iterator begin, end;
//        int sum ;
//        std::tie(begin, end, sum) = result;
//        std::cout << begin - data.begin() << " , " << end - data.begin()
//                  << " , " << sum << "\n";
//    }
}

//
TEST_F(TestMaxSequence, FindMaxSequenceByLinear)
{
    int num = 10000;
    std::vector<int> data(num);
    for (int i = 0; i < num; ++i )
    {
        data[i] = (i % 2 == 0)? i : -i ;
    }

    std::random_shuffle(data.begin(), data.end());

    typedef std::vector<int>::iterator iterator;
    std::tuple<iterator, iterator, int> result
            = FindMaxSequenceByLinear(data.begin(), data.end());

}