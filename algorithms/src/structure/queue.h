//
// Created by luoyulong on 18/5/11.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H
#include <memory.h>
#include <iterator>

namespace algo
{
//    template <typename  Iterator>
//    struct iterator_traits
//    {
//        typedef typename Iterator::difference_type difference_type;
//        typedef typename Iterator::value_type value_type;
//        typedef typename Iterator::pointer pointer;
//        typedef typename Iterator::reference reference;
//        typedef typename Iterator::iterator_category iterator_category;
//    };
//
//    template<class T>
//    struct iterator_traits<T*>
//    {
//        typedef ptrdiff_t difference_type;
//        typedef T value_type;
//        typedef T* pointer;
//        typedef T& reference;
//        typedef random_access_iterator_tag iterator_category;
//    };
//
//    template <typename _TP>
//    struct Iterator
//    {
//        typedef _TP value_type;
//    };
//
//
//
//
//
//    template <typename  Iter>
//    struct Pointer
//    {
//
//    };

    template <typename  _TP> class QueueIterator;



    template <typename  _TP>
    class Queue
    {
    protected:
        typedef _TP                     value_type;
        typedef value_type&             reference;
        typedef const value_type&       const_reference;

    public:
        Queue():size_(0), capacity_(4), head_ (0), tail_(0)
        {
            arr_ = (_TP*)malloc(sizeof(_TP) * capacity_);
        }

        ~Queue()
        {
            free (arr_);
        }

        class Iterator
        {
        public:
            _TP& operator*()
            {
                if (head >= queue->capacity_)
                {
                    head -= queue->capacity_;
                }

                return queue->arr_[head];
            }

            Iterator& operator++()
            {
                ++head;
                return *this;
            }

            bool operator==(const Iterator& iter)
            {
                if (iter.head == head && iter.queue == queue)
                {
                    return true;
                }
                return false;
            }

            bool operator!= (const Iterator& iter)
            {
                return !this->operator==(iter);
            }


            Iterator operator++(int bar)
            {
                Iterator iter;
                iter.head = head;
                iter.queue = queue;

                head += bar;

                return iter;
            }
            int head;

        private:
            friend  Queue;
            Queue* queue;
        };

        Iterator begin()
        {
            Iterator iter;
            iter.queue = this;
            iter.head = head_;
            return iter;
        }

        Iterator end()
        {
            Iterator iter;
            iter.queue = this;
            iter.head = head_ + size_;
            return iter;
        }

        QueueIterator<_TP> q_begin()
        {
            QueueIterator<_TP> iter(this, head_);
            return iter;
        }

        QueueIterator<_TP> q_end()
        {
            QueueIterator<_TP> iter(this, head_ + size_);
            return iter;
        }


        void push_back(_TP& tp)
        {
            CheckCapacity();
            arr_[tail_] = tp;
            ++size_;
            ++tail_;
            if (tail_ == capacity_)
            {
                tail_ = 0;
            }
        }

        void push_back(const _TP& tp)
        {
            CheckCapacity();
            arr_[tail_] = tp;
            ++size_;
            ++tail_;
            if (tail_ == capacity_)
            {
                tail_ = 0;
            }
        }



        void push_front(const _TP& tp)
        {
            CheckCapacity();
            --head_;
            if ( head_ == -1)
            {
                head_ = capacity_ - 1;
            }

            arr_[head_] = tp;
            ++size_;
        }

        void pop_back()
        {
            assert (size_ > 0);
            if (size_ == 0)
            {
                return;
            }
            tail_ = get_last_index();
            --size_;
        }

        void pop_front()
        {
            assert (size_ > 0);
            if (size_ == 0)
            {
                return;
            }

            ++head_;
            if (head_ == capacity_)
            {
                head_ = 0;
            }

            --size_;
        }

        _TP& back()
        {
            int index = get_last_index();
            return arr_[index];
        }

        const _TP& back() const
        {
            int index = get_last_index();
            return arr_[index];
        }

        _TP& front()
        {
            return arr_[head_];
        }

        const _TP& front() const
        {
            return arr_[head_];
        }


        bool empty() const
        {
            return size_ == 0;
        }

        size_t size() const
        {
            return size_;
        }


    private:
        void CheckCapacity()
        {
            if (size_ >= capacity_)
            {
                int new_capacity_ = capacity_ * 2 + 1;
                _TP* new_arr = (_TP*)realloc(arr_, sizeof(_TP) * new_capacity_);
                if ( new_arr )
                {
                    arr_ = new_arr;
                    if (head_ < tail_ || tail_ == 0)
                    {
                        memmove(new_arr, arr_ + head_ , size_ * sizeof(_TP));
                    }
                    else if (head_ >= tail_)
                    {
                        memmove(new_arr + capacity_ , arr_ , tail_ * sizeof(_TP));
                        memmove(new_arr, arr_ + head_, (capacity_ - head_) * sizeof(_TP));
                        memmove(new_arr + (capacity_ - head_), new_arr + capacity_ , tail_ * sizeof(_TP));

                    }
                }
                else
                {
                    _TP* new_arr = (_TP*)malloc(sizeof(_TP) * new_capacity_);
                    if (head_ < tail_ || tail_ == 0)
                    {
                        memcpy(new_arr, arr_ + head_, size_ * sizeof(_TP));
                    }
                    else if (head_ >= tail_)
                    {
                        memcpy(new_arr, arr_ + head_ , (capacity_ - head_) * sizeof(_TP));
                        memcpy(new_arr + (capacity_ - head_), arr_, tail_ * sizeof(_TP));
                    }

                    free(arr_);
                    arr_ = new_arr;

                }

                head_ = 0;
                tail_ = size_;
                capacity_ = new_capacity_;
            }
        }

        int get_last_index()
        {
            int index;
            if (tail_ == 0)
            {
                index = capacity_ - 1;
            }
            else
            {
                 index = tail_ - 1;
            }
            return index;
        }
    private:
        friend class QueueIterator<_TP>;
        _TP* arr_;
        size_t size_;
        size_t capacity_;
        int head_;
        int tail_;
    };

    template <typename  _TP>
    class QueueIterator
    {
    public:
        typedef _TP                         value_type;
        typedef std::random_access_iterator_tag  iterator_category;
        typedef value_type&                 reference;
        typedef std::ptrdiff_t              difference_type;
        typedef _TP*  pointer;
    public:
        QueueIterator(Queue<_TP>* _queue, int _head):queue(_queue), head(_head)
        {}

        value_type& operator*()
        {
            if (head >= queue->capacity_)
            {
                head -= queue->capacity_;
            }

            return queue->arr_[head];
        }


        bool operator==(const QueueIterator& iter)
        {
            if (iter.head == head && iter.queue == queue)
            {
                return true;
            }
            return false;
        }

        bool operator!= (const QueueIterator& iter)
        {
            return !this->operator==(iter);
        }


        QueueIterator operator++(int bar)
        {
            QueueIterator iter;
            iter.head = head;
            iter.queue = queue;

            head ++;

            return iter;
        }

        QueueIterator& operator++()
        {
            ++head;
            return *this;
        }

        QueueIterator& operator--()
        {
            --head;
            return  *this;
        }

        QueueIterator operator--(int n)
        {
            QueueIterator iter;
            iter.head = head;
            iter.queue = queue;

            head --;

            return iter;
        }

        QueueIterator& operator+(int n)
        {
            head += n;
            return *this;
        }

        QueueIterator& operator-(int n)
        {
            head -= n;
            return *this;
        }

        QueueIterator operator-(const QueueIterator& iter)
        {
            QueueIterator temp(*this);
            temp.head = head - iter.head;
            return temp;
        }

        bool operator < (const QueueIterator& iter)
        {
            return head < iter.head;
        }

        friend bool operator < (const QueueIterator& iter1, const QueueIterator& iter2);

    private:
        Queue<_TP>* queue;
        int head;
    };

    template <typename  _TP>
    bool operator < (const QueueIterator<_TP>& iter1, const QueueIterator<_TP>& iter2)
    {
        return iter1.head < iter2.head;
    }
}
#endif //ALGORITHMS_STACK_H
