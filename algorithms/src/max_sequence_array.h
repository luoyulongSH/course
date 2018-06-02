//
// Created by luoyulong on 18/4/25.
//

#ifndef ALGORITHMS_MAX_SEQUENCE_ARRAY_H
#define ALGORITHMS_MAX_SEQUENCE_ARRAY_H
#include <tuple>

namespace algo
{
    template <typename _RAI, typename _TP>
    std::tuple<_RAI, _RAI, _TP> MergeSequence( const std::tuple<_RAI, _RAI, _TP>& left, _RAI mid,  const std::tuple<_RAI, _RAI, _TP>& right )
    {
        _TP sum_mid = *mid;
        _TP max_sum = *mid;
        _RAI left_iter = mid;
        _RAI low;
        _TP sum1;
        std::tie(low, std::ignore, sum1) = left;
        for (_RAI iter = mid -1; iter >= low; -- iter)
        {
            sum_mid += *iter;
            if ( sum_mid  > max_sum )
            {
                max_sum = sum_mid;
                left_iter = iter;
            }
        }

        sum_mid = max_sum;
        _RAI right_iter = mid;
        _RAI high;
        _TP sum2;
        std::tie(std::ignore, high, sum2) = right;
        for ( _RAI iter = mid + 1; iter < high; ++ iter )
        {
            sum_mid += *iter;
            if (sum_mid > max_sum)
            {
                max_sum = sum_mid;
                right_iter = iter;
            }
        }

        sum_mid = max_sum;

        if ( sum1 > sum2 && sum1 > max_sum)
        {
            return left;
        }
        else if ( sum2 > sum1 && sum2 > max_sum )
        {
            return right;
        }
        else
        {

            return std::make_tuple(left_iter, right_iter + 1, max_sum);
        }
    }

    template <typename _RAI, typename  _TP>
    std::tuple<_RAI, _RAI, _TP> GenerateMaxSequenceArray( _RAI begin, _RAI end )
    {
        if ( begin + 1 == end )
        {
            return std::make_tuple(begin, end, *begin);
        }
        else
        {
            _RAI mid = begin + ( end - begin ) / 2;
            std::tuple<_RAI, _RAI, _TP> tuple1
                    = GenerateMaxSequenceArray<_RAI, _TP>( begin, mid );
            std::tuple<_RAI, _RAI, _TP> tuple2
                    = GenerateMaxSequenceArray<_RAI, _TP>( mid, end );
            return MergeSequence<_RAI, _TP>(tuple1, mid, tuple2);
        }
    }

    template <typename  _RAI, typename  _TP>
    std::tuple<_RAI, _RAI, _TP> FindMaxSequence(_RAI begin, _RAI end)
    {
        _TP max_sum = 0;
        _TP sum = 0;
        _RAI max_low, max_high;

        for (_RAI i = begin; i != end; ++ i)
        {
            sum = 0;
            for (_RAI j = i ; j != end; ++j)
            {
                sum += *j;
                if (sum > max_sum)
                {
                    max_sum = sum;
                    max_low = i;
                    max_high = j;
                }
            }
        }
        return std::make_tuple(max_low, max_high + 1, max_sum);


    };


    template <typename _RAI>
    std::tuple<_RAI, _RAI, typename _RAI::value_type> FindMaxSequenceByLinear(_RAI begin, _RAI end)
    {
        typedef typename  _RAI::value_type _TP;

        _TP max_sum = *begin;
        _RAI low = begin, high = begin;
        _TP sum = 0;


        for (_RAI iter = begin + 1; iter != end; ++iter)
        {

            if (max_sum >= 0 && *iter <= 0)
            {
                continue;
            }

            sum = 0;
            _RAI min = low;
            _RAI max = high;
            _TP last_max = max_sum;
            for (_RAI j = iter; j >= min; --j)
            {
                sum += *j;
                if (iter == high  + 1 && sum > 0)
                {
                    max_sum = last_max + sum;
                    low = min;
                    high = iter;
                    break;
                }
                else if ( sum > max_sum )
                {
                    high = iter;
                    low = j;
                    max_sum = sum;

                }
                else if ( sum <= 0 )
                {
                    break;
                }
            }
        }

        return std::make_tuple(low, high +1, max_sum);


    };

}

#endif //ALGORITHMS_MAX_SEQUENCE_ARRAY_H
