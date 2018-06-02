//
// Created by luoyulong on 18/4/30.
//

#ifndef ALGORITHMS_FAST_MATH_H
#define ALGORITHMS_FAST_MATH_H

namespace algo
{

    double fast_cos(double theta)
    {
        double value = std::pow(theta, 2);
        return 1 - value / 2 + std::pow(value, 2)/ 24;
    }





}


#endif //ALGORITHMS_FAST_MATH_H
