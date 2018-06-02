//
// Created by luoyulong on 18/5/27.
//

#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H

namespace algo
{
    template <typename  _TP>
    class List;

    template <typename  _TP>
    struct Node
    {
        Node(const _TP& _tp): tp(_tp), prev_node(nullptr), next_node(nullptr)
        {}

        _TP tp;
        Node* prev_node;
        Node* next_node;
    };

    template <typename  _TP>
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

        bool operator == ( const ListIterator& iter )
        {
            return iter.node_ == node_;
        }

        bool operator != ( const ListIterator& iter)
        {
            return node_ != iter.node_;
        }


        friend bool operator != ( const ListIterator& iter1, const ListIterator& iter2 );

        friend bool operator == ( const ListIterator& iter1, const ListIterator& iter2 );

    private:
        Node<_TP>* node_;
        friend class List<_TP>;
    };

    template <typename  _TP>
    bool operator == ( const ListIterator<_TP>& iter1, const ListIterator<_TP>& iter2 )
    {
        return  iter1.node_ == iter2.node_;
    }

    template <typename  _TP>
    bool operator != ( const ListIterator<_TP>& iter1, const ListIterator<_TP>& iter2 )
    {
        return  iter1.node_ != iter2.node_;
    }

    template <typename  _TP>
    class List
    {
    public:
        typedef ListIterator<_TP> iterator;
        List():head_node_(new Node<_TP>(_TP{0})), tail_node_(new Node<_TP>(_TP{0})),  end_(tail_node_), size_(0)
        {
            head_node_->next_node = tail_node_;
            tail_node_->prev_node = head_node_;
        }

        ~List()
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

        void insert_after( ListIterator<_TP>& iter, const _TP& tp )
        {
            insert_after(iter.node_, tp);
        }

        void insert_before( ListIterator<_TP>& iter, const _TP& tp )
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

        ListIterator<_TP> begin()
        {
            ListIterator<_TP> iter(head_node_->next_node);
            return iter;
        }

        ListIterator<_TP>& end()
        {
            return end_;
        }

        size_t size() const
        {
            return size_;
        }
    public:


    private:
        void insert_before(Node<_TP>* node, const _TP& tp)
        {
            Node<_TP>* new_node = new Node<_TP>(tp);
            Node<_TP>* prev_node = node->prev_node;

            node->prev_node = new_node;
            prev_node->next_node = new_node;

            new_node->prev_node = prev_node;
            new_node->next_node = node;

            size_ ++;
        }

        void insert_after( Node<_TP>* node, const _TP& tp )
        {
            Node<_TP>* new_node = new Node<_TP>(tp);
            Node<_TP>* next_node = node->next_node;

            node->next_node = new_node;
            next_node->prev_node = new_node;

            new_node->next_node = next_node;
            new_node->prev_node = node;

            size_ ++;
        }

        void erase( Node<_TP>* node )
        {
            node->prev_node->next_node = node->next_node;
            node->next_node->prev_node = node->prev_node;

            delete node;
            size_ --;
        }

    private:


        Node<_TP>* head_node_;
        Node<_TP>* tail_node_;
        ListIterator<_TP> end_;

        size_t size_;
    };

}

#endif //ALGORITHMS_LIST_H
