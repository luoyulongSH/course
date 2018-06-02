//
// Created by luoyulong on 18/4/22.
//

#ifndef ALGORITHMS_PLOYNOMIAL_ALGO_H
#define ALGORITHMS_PLOYNOMIAL_ALGO_H

namespace algo
{
    template <typename _RandomAccessIterator, typename _TP>
    _TP PloynomialCalc( _RandomAccessIterator first, _RandomAccessIterator last, const _TP& value )
    {
        _TP result = *first;
        ++first;
        for (; first != last; ++first)
        {
            result = result * value + *first;
        }

        return result;
    }
}
#endif //ALGORITHMS_PLOYNOMIAL_ALGO_H
