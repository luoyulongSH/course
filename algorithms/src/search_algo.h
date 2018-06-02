//
// Created by luoyulong on 18/4/22.
//

#ifndef ALGORITHMS_SEARCH_ALGO_H
#define ALGORITHMS_SEARCH_ALGO_H
#include <vector>
namespace algo
{
    template <typename _RandomAccessIterator, typename _TP>
    bool BinarySearch( _RandomAccessIterator first, _RandomAccessIterator last, const _TP& value, _RandomAccessIterator* idx )
    {
        while ( first <= last)
        {
            _RandomAccessIterator mid = ( last - first ) / 2 +  first;
            if ( *mid == value )
            {
                *idx = mid;
                return true;
            }
            else if ( *mid > value )
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        }


        return false;
    }


}


#endif //ALGORITHMS_SEARCH_ALGO_H
