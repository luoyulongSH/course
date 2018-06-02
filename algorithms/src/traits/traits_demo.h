//
// Created by luoyulong on 18/5/12.
//

#ifndef ALGORITHMS_TRAITS_DEMO_H
#define ALGORITHMS_TRAITS_DEMO_H



template <class _Tp>
struct __has_iterator_category
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Up> static __two __test(...);
    template <class _Up> static char __test(typename _Up::iterator_category* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

struct input_data{};

struct Obj
{
    int size()
    {
        return 0;
    }
};

template <typename TP>
struct Obj2
{
    typedef input_data iterator_category;
    int size;
};


template <typename _TP>
void TestTraits(_TP& tp)
{
    bool value = __has_iterator_category<_TP>::value;
    if (value)
    {
        printf("value\n");
    }
    else
    {
        printf("false\n");
    }

}




#endif //ALGORITHMS_TRAITS_DEMO_H
