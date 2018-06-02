//
// Created by luoyulong on 18/6/1.
//

#ifndef ALGORITHMS_SIMPLE_QUEUE_H
#define ALGORITHMS_SIMPLE_QUEUE_H
#include <memory.h>
#include <iterator>

namespace algo
{

    template <typename  _TP>
    class SimpleQueue
    {

    public:
        SimpleQueue():size_(0), capacity_(4), head_ (0), tail_(0)
        {
            arr_ = (_TP*)malloc(sizeof(_TP) * capacity_);
        }

        ~SimpleQueue()
        {
            free (arr_);
        }

        class Iterator
        {
        public:
            _TP& operator*()
            {
                if (index >= queue->capacity_)
                {
                    index -= queue->capacity_;
                }
                return queue->arr_[index];
            }

            Iterator& operator++()
            {
                ++index;
                return *this;
            }

            bool operator!= (const Iterator& iter)
            {
                if (iter.index == index && iter.queue == queue)
                {
                    return false;
                }
                return true;
            }

            int index;
        private:
            friend  SimpleQueue;
            SimpleQueue* queue;
        };

        Iterator begin()
        {
            Iterator iter;
            iter.queue = this;
            iter.index = head_;
            return iter;
        }

        Iterator end()
        {
            Iterator iter;
            iter.queue = this;
            iter.index = head_ + size_;
            return iter;
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


        const _TP& back() const
        {
            int index = get_last_index();
            return arr_[index];
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

        const _TP& operator[](int index)
        {
            index += head_;
            if (index >= capacity_)
            {
                index -= capacity_;
            }
            return arr_[index];
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

        int get_last_index() const
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
        _TP* arr_;
        size_t size_;
        size_t capacity_;
        int head_;
        int tail_;
    };
}



#endif //ALGORITHMS_SIMPLE_QUEUE_H
