//
// Created by luoyulong on 18/4/30.
//

#ifndef ALGORITHMS_QUATERNION_H
#define ALGORITHMS_QUATERNION_H

namespace algo
{
namespace slam
{
template <typename _TP>
class Quaternion
{
public:
    _TP get_w() const
    {
        return w;
    }

    _TP get_x() const
    {
        return x;
    }

    _TP get_y() const
    {
        return y;
    }

    _TP get_z() const
    {
        return z;
    }


    Quaternion operator+ (const Quaternion& q)
    {
        Quaternion sum;
        sum.w = w + q.w;
        sum.x = x + q.x;
        sum.y = y + q.y;
        sum.z = z + q.z;
        return sum;
    }


private:
    _TP w;
    _TP x;
    _TP y;
    _TP z;

};
}
}

#endif //ALGORITHMS_QUATERNION_H
