
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>
#include <exception>

//node class

template <class T>

class Node{
public:
    T m_data;
    Node* m_next;
    Node(const T& data):m_data(data),m_next(nullptr){}
    Node(const Node&) = default;
    ~Node() = default;
    Node& operator=(const Node&) = default;

};

//queue class

template <class T>

class Queue{

    Node<T> *m_front = nullptr;
    Node<T> *m_back = nullptr;
    int m_size = 0;

public:

    class Iterator;
    class ConstIterator;
    class EmptyQueue{};

    Queue() = default;
    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);
    Queue& pushBack(const T&);
    T& front();
    const T& front() const;
    Queue& popFront();
    const int size() const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
};


//iterator Class

template<class T>

class Queue<T>::Iterator{
    Node<T> *m_ptr;

public:

    class InvalidOperation{};

    Iterator(Node<T> *ptr = nullptr);
    Iterator(const Iterator&) = default;
    ~Iterator() = default;
    Iterator& operator=(const Iterator&) = default;
    Iterator& operator++();
    bool operator!=(const Iterator&) const;
    T& operator*() const;

};

//constant iterator Class

template<class T>

class Queue<T>::ConstIterator{
    Node<T> *m_ptr;

public:

    class InvalidOperation{};

    ConstIterator(Node<T> *ptr = nullptr);
    ConstIterator(const ConstIterator&) = default;
    ~ConstIterator() = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator&) const;
    T& operator*() const;

};

/*******************************************************************************************************
 *
 *                 implementation of member functions of the class Queue
 *
 *******************************************************************************************************/

template <class T>

Queue<T>::Queue(const Queue<T>& queue)

{
    if(queue.m_size == 0)
    {
        throw EmptyQueue();
    }
    for (ConstIterator it = queue.begin();it != queue.end();++it)
    {
        try
        {
            pushBack(*it);
        }
        catch (std::bad_alloc& e)
        {
            while(m_size)
            {
                popFront();
            }
            throw;
        }
    }
}

template <class T>

Queue<T>& Queue<T>::operator=(const Queue<T>& queue){
    if(this == &queue)
    {
        return *this;
    }
    Queue<T> temp;
    for(ConstIterator it = queue.begin(); it != queue.end(); ++it)
    {
        try
        {
            temp.pushBack(*it);
        }
        catch (std::bad_alloc& e)
        {
            throw;
        }
    }
    while (m_size)
    {
        popFront();
    }
    m_front = temp.m_front;
    m_back = temp.m_back;
    m_size = temp.m_size;
    temp.m_front = nullptr;
    temp.m_back = nullptr;
    temp.m_size = 0;
    return *this;
}

template <class T>

Queue<T>::~Queue()
{
    while (m_size != 0)
    {
        popFront();
    }
}

template <class T>

Queue<T>& Queue<T>::pushBack(const T &data)
{
    Node<T> *newNode = new Node<T>(data);
    if (m_size == 0)
    {
        m_back = newNode;
        m_front = newNode;
        m_size++;
    }
    else if (m_size > 0)
    {
        m_back->m_next = newNode;
        m_back = newNode;
        m_size++;
    }
    return *this;
}

template <class T>

T& Queue<T>::front()
{
    if(m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_front->m_data;
}

template <class T>

const T& Queue<T>::front() const
{
    if(m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_front->m_data;
}

template <class T>

Queue<T>& Queue<T>::popFront(){
    if (m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    else if (m_size > 0)
    {
        Node<T> *temp = m_front;
        m_front = m_front->m_next;
        if (m_front == nullptr)
        {
            m_back = nullptr;
        }
        delete temp;
        m_size--;
    }
    return *this;
}

template <class T>

const int Queue<T>::size() const
{
    return m_size;
}

template <class T>

typename Queue<T>::Iterator Queue<T>::begin()
{
    if(m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return Iterator(m_front);
}

template <class T>

typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(nullptr);
}

template <class T>

typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    if(m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(m_front);
}

template <class T>

typename Queue<T>::ConstIterator Queue<T>::end() const
{
    if(m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(nullptr);
}

/*******************************************************************************************************
 *
 *                 implementation of member functions of the iterator
 *
 *******************************************************************************************************/

template <class T>

Queue<T>::Iterator::Iterator(Node<T> *ptr):
m_ptr(ptr)
{}

template <class T>

typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if (m_ptr == nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    m_ptr = m_ptr->m_next;
    return *this;
}

template <class T>

bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    return (m_ptr != it.m_ptr);
}

template <class T>

T& Queue<T>::Iterator::operator*() const
{
    if(m_ptr == nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    return m_ptr->m_data;
}

/*******************************************************************************************************
 *
 *                 implementation of member functions of the constant iterator
 *
 *******************************************************************************************************/

template <class T>

Queue<T>::ConstIterator::ConstIterator(Node<T> *ptr):
m_ptr(ptr)
{}

template <class T>

typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if (m_ptr == nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    m_ptr = m_ptr->m_next;
    return *this;
}

template <class T>

bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const
{
    return (m_ptr != it.m_ptr);
}

template <class T>

T& Queue<T>::ConstIterator::operator*() const
{
    if(m_ptr == nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    return m_ptr->m_data;
}

/***********************************************************************************************************************
 *
 *                                           extra functions
 *
 **********************************************************************************************************************/

template <class T,typename F>

Queue<T> filter(const Queue<T>& queue, F function)
{
    Queue<T> result;
    for (typename Queue<T>::ConstIterator it = queue.begin();it != queue.end(); ++it)
    {
        if(function(*it))
        {
            result.pushBack(*it);
        }
    }
    return result;
}

template <class T,typename F>

void transform (const Queue<T>& queue, F function)
{
    for (typename Queue<T>::ConstIterator it = queue.begin();it != queue.end(); ++it)
    {
        function(*it);
    }
}

#endif //EX3_QUEUE_H
