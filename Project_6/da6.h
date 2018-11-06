//Project 6 for CS311
//Andrew Adler, Ian Ferguson, Bradley Morton

#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include "llnode2.h"
//For llnode.h
#include <algorithm>
#include <functional>
#include <memory>


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
    int size() const
    {
        return 0;
    }

    const data_type * find(key_type key) const
    {
        //return &(_head->_data.second);
        return nullptr;
    }

    data_type * find(key_type key)
    {
        //return &(_head->_data.second);
        return nullptr;
    }

    //Returns true if the class has no key value pairs, false otherwise
    bool empty() const
    {
        return (size()==0);
    }

    //Inserts a key value pair into the data structure
    void insert(key_type key, data_type item)
    {

    }

    //Erases a particular key and its associated value from the data structure
    void erase(key_type key)
    {

    }

    void traverse(std::function<void(key_type, data_type)> function) const
    {

    }

private:
    std::shared_ptr<LLNode2<std::pair<key_type, data_type>>> _head;
};

#endif //DA6_H_INCLUDED
