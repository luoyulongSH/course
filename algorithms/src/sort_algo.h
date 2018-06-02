//
// Created by luoyulong on 18/4/22.
//

#ifndef ALGORITHMS_SORT_ALGO_H
#define ALGORITHMS_SORT_ALGO_H
#include <functional>
#include <vector>
namespace algo
{
    void InsertSort(std::vector<int>& data)
    {
        for ( int i = 1; i < data.size(); ++i )
        {
            int value = data[i];
            int j = i - 1;
            while ( j >=0 && data[j] > value )
            {
                data[ j + 1] = data[j];
                --j;
            }

            data[j + 1] = value;
        }
    }

    void Merge(std::vector<int >& data, int s1, int e1, int e2, std::vector<int>& temp)
    {
        for (int i = s1; i < e2; ++i)
        {
            temp[i] = data[i];
        }

        int i = s1;
        int j = e1;
        int idx = s1;
        while ( i < e1 && j < e2)
        {
            if (temp[i] > temp[j])
            {
                data[idx] = temp[j];
                ++j;
            }
            else
            {
                data[idx] = temp[i];
                ++i;
            }

            ++idx;
        }

        while (i < e1)
        {
            data[idx ++] = temp[i ++];
        }

        while (j < e2)
        {
            data[idx ++] = temp [j ++];
        }

    }


    void MergeSort(std::vector<int>& data, int s, int e, std::vector<int>& temp)
    {
        if ( s + 1 < e )
        {
            int m = ( e - s ) / 2 + s;
            MergeSort( data, s, m, temp );
            MergeSort( data, m, e, temp );
            Merge( data, s, m, e, temp );
        }

    }

    void MergeSort(std::vector<int>& data)
    {
        std::vector<int> temp(data.size());
        MergeSort( data, 0, data.size(), temp );
    }


}

#endif
