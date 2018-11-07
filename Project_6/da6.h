//Project 6 for CS311
//Andrew Adler, Ian Ferguson, Bradley Morton

#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include "llnode2.h"
//For llnode.h
#include <algorithm>
#include <cstddef>
#include <functional>
#include <memory>
#include <utility>


template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType>> & head)
{
    std::shared_ptr<LLNode2<ValType>> oldHead(nullptr);
    std::shared_ptr<LLNode2<ValType>> newHead(nullptr);

    while(head)
    {
        oldHead = head->_next;
        head -> _next = newHead;
        newHead = head;
        head = oldHead;


    }

    head = newHead;

}



template <typename Key, typename Data>
class ListMap {

public:

    using key_type= Key;
    using data_type= Data;

public:
    // ******************** ListMap Constructors and Destructors ******************
    //Default constructor, takes no parameters
    ListMap()
        : _head(nullptr)
    {}
    //Default constructor
    ~ListMap()
    {}
    //Four of the Big Five are meant to not be available for use
    ListMap(const ListMap & base) = delete;
    ListMap(ListMap && other) = delete;
    ListMap & operator=(const ListMap & base) = delete;
    ListMap & operator=(const ListMap && other) = delete;

    // ******************* ListMap public member functions *************************
    //Returns the size of the ListMap
    size_t size() const
    {
        auto p = _head;  // Iterates through list
        size_t n = 0;   // Number of nodes so far
        while (p)
        {
            p = p->_next;
            ++n;
        }
        return n;
    }

    const data_type * find(key_type key) const
    {
        auto headIter = _head;
        while (headIter)
        {
            if (headIter->_data.first == key)
            {
                return &(headIter->_data.second);
            }
            headIter = headIter->_next;
        }
        return nullptr;
    }

    data_type * find(key_type key)
    {
        auto headIter = _head;
        while (headIter)
        {
            if (headIter->_data.first == key)
            {
                return &(headIter->_data.second);
            }
            headIter = headIter->_next;
        }
        return nullptr;
    }

    //Returns true if the class has no key value pairs, false otherwise
    bool empty() const
    {
        return isEmpty(_head);
    }

    //Inserts a key value pair into the data structure
    void insert(key_type key, data_type item)
    {
        auto result = find(key);
        if (result)
        {
            *result = item;
            return;
        }
        push_front(_head,std::make_pair(key,item));
    }

    //Erases a particular key and its associated value from the data structure
    void erase(key_type key)
    {
        if (_head->_data.first == key)
        {
            _head = _head->_next;
            return;
        }

        auto previousPtr = _head;
        auto currentPtr = _head->_next;

        while(currentPtr)
        {
            if (currentPtr->_data.first == key)
            {
                previousPtr->_next = currentPtr->_next;
                return;
            }
            previousPtr = currentPtr;
            currentPtr = currentPtr->_next;
        }
    }

    //Takes a function that is then applied to every object in the linked list.
    void traverse(std::function<void(key_type, data_type)> function) const
    {
        auto iter=_head;
        while(iter)
        {
            function(iter->_data.first, iter->_data.second);
            iter=iter->_next;
        }
    }

private:
    std::shared_ptr<LLNode2<std::pair<key_type, data_type>>> _head;
};

#endif //DA6_H_INCLUDED
