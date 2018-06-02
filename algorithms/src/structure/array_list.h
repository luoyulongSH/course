//
// Created by luoyulong on 18/6/1.
//

#ifndef ALGORITHMS_ARRAY_LIST_H
#define ALGORITHMS_ARRAY_LIST_H

namespace algo
{
    template <typename _TP>
    class ArrayList
    {
    private:
        struct Node
        {
            Node(const _TP& _tp): tp(_tp), prev_node(nullptr), next_node(nullptr)
            {}

            _TP tp;
            Node* prev_node;
            Node* next_node;
        };

        class Cache
        {
        public:
            Cache():size_(0), capacity_(4)
            {
                arr_ = (_TP*)malloc(sizeof(Node) * capacity_);
            }

            ~Cache()
            {
                free(arr_);
            }


            Node* Fetch()
            {
                CheckCapacity();
                return arr_[size_ ++];
            }

            void Release(Node* node)
            {

            }

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
        private:
            int size_;
            int capacity_;
            Node* arr_;
        };
    public:
        class ListIterator
        {
        public:
            ListIterator(Node<_TP>* node): node_(node)
            {
            }

            _TP& operator*()
            {
                return node_->tp;
            }

            ListIterator& operator++()
            {
                node_ = node_->next_node;
                return *this;
            }

            ListIterator& operator--()
            {
                node_ = node_->prev_node;
                return *this;
            }

            bool operator != ( const ListIterator& iter)
            {
                return node_ != iter.node_;
            }

        private:
            Node* node_;
            friend class ArrayList;
        };

    public:
        typedef ListIterator iterator;
        ArrayList():head_node_(new Node<_TP>(_TP{0})), tail_node_(new Node<_TP>(_TP{0})),  end_(tail_node_), size_(0)
        {
            head_node_->next_node = tail_node_;
            tail_node_->prev_node = head_node_;
        }

        ~ArrayList()
        {
            Node<_TP>* node = head_node_;
            Node<_TP>* tmp;
            while ( node )
            {
                tmp = node->next_node;
                delete node;
                node = tmp;
            }
        }

        void clear()
        {
            Node<_TP>* node = head_node_->next_node;
            Node<_TP>* tmp;
            while ( node != tail_node_)
            {
                tmp = node->next_node;
                delete node;
                node = tmp;
            }

            size_ = 0;
        }

        void push_front( const _TP& tp )
        {
            insert_before(head_node_->next_node, tp);
        }

        void push_back( const _TP& tp)
        {
            insert_after(tail_node_->prev_node, tp);
        }

        void insert_after( iterator& iter, const _TP& tp )
        {
            insert_after(iter.node_, tp);
        }

        void insert_before( iterator& iter, const _TP& tp )
        {
            insert_before(iter.node_, tp);
        }

        _TP& front()
        {
            return head_node_->prev_node->tp;
        }

        _TP& back()
        {
            return tail_node_->next_node->tp;
        }

        void pop_front()
        {
            erase(head_node_->next_node);
        }

        void pop_back()
        {
            erase(tail_node_->prev_node);
        }

        iterator begin()
        {
            ListIterator iter(head_node_->next_node);
            return iter;
        }

        iterator& end()
        {
            return end_;
        }

        size_t size() const
        {
            return size_;
        }

    private:
        void insert_before(Node* node, const _TP& tp)
        {
            Node<_TP>* new_node = new Node<_TP>(tp);
            Node<_TP>* prev_node = node->prev_node;

            node->prev_node = new_node;
            prev_node->next_node = new_node;

            new_node->prev_node = prev_node;
            new_node->next_node = node;

            size_ ++;
        }

        void insert_after( Node* node, const _TP& tp )
        {
            Node* new_node = new Node(tp);
            Node* next_node = node->next_node;

            node->next_node = new_node;
            next_node->prev_node = new_node;

            new_node->next_node = next_node;
            new_node->prev_node = node;

            size_ ++;
        }

        void erase( Node* node )
        {
            node->prev_node->next_node = node->next_node;
            node->next_node->prev_node = node->prev_node;

            delete node;
            size_ --;
        }

    private:
        Node* head_node_;
        Node* tail_node_;
        iterator end_;
        size_t size_;

        int capacity_;

        Node* cache_;
    };

}

#endif //ALGORITHMS_LIST_H
