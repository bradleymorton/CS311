// da6.h
// Andrew Adler, Ian Ferguson, Bradley Morton
// Started: 06 Nov 2018
// Updated: 06 Nov 2018

//Project 6 for CS311

#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include "llnode2.h"    //For llnode.h 
#include <cstddef>      // for std::size_t
#include <functional>   // for std::function
#include <memory>       // for std::shared_ptr
#include <utility>      // for std::make_pair

// reverseList
// Rerversed the order of a given linked list of LLNode2's
// Pre:
//      Valid pointer to LLNode2
// No Throw Guarantee
template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType>> & head)
{
    std::shared_ptr<LLNode2<ValType>> oldHead(nullptr);
    std::shared_ptr<LLNode2<ValType>> newHead(nullptr);

    while(head)
    {
        oldHead = head->_next;
        head ->_next = newHead;
        newHead = head;
        head = oldHead;
    }
    head = newHead;
}


// *********************************************************************
// class ListMap - Class definition
// *********************************************************************
// class ListMap
// Templated linked list map of key-value pairs
// Invariants:
//      _head is a shared pointer to the start of a linked list, or is nullptr
//      the final node of the linked list is a nullptr
// Requirements on types:
//      Key must have a copy constructor and a destrcutor
//      Data must have a copy constructor and a destructor
template <typename Key, typename Data>
class ListMap {

public:
    // ***** ListMap: types *****
    using key_type = Key;    // type of key items
    using data_type = Data;  // type of data items

public:
    // ***** ListMap: Constructors and Destructors *****

    // Default constructor, takes no parameters
    //      creates an empty dataset
    // Strong Guarantee
    ListMap()
        : _head(nullptr)
    {}

    // Default destructor
    // No Throw Guarantee
    ~ListMap()
    {}

    // Four of the Big Five are meant to not be available for use
    ListMap(const ListMap & base) = delete;
    ListMap(ListMap && other) = delete;
    ListMap & operator=(const ListMap & base) = delete;
    ListMap & operator=(const ListMap && other) = delete;

    // ***** ListMap public member functions *****
    // size
    // Returns a size_t that is the number of key-value pairs in the ListMap
    // No Throw guarantee
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

    // find
    //      const version
    // Returns a const pointer to the value at the given key
    // If the key is not found, returns nullptr
    // No throw guarantee
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

    // find
    //      non-const version
    // Returns a pointer to the value at the given key
    // If the key is not found, returns nullptr
    // No throw guarantee
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

    // empty
    // Returns true if the class has no key value pairs, false otherwise
    // No throw guarantee
    bool empty() const
    {
        return isEmpty(_head);
    }

    // insert
    // Inserts a key value pair into the dataset at the end of the list if the key is not found
    // If the key is found, replaces the value at the key with the value passed
    // Strong guarantee
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

    // erase
    // Erases a particular key and its associated value from the data structure
    // If the key is not found in the dataset, does nothing
    // No throw guarantee
    void erase(key_type key)
    {
        if (_head->_data.first == key)      // Check for key at beginning of list
        {
            _head = _head->_next;
            return;
        }

        auto previousPtr = _head;
        auto currentPtr = _head->_next;

        while(currentPtr)                   // Check for key in the rest of list
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

    // traverse
    // Takes a function that is then applied to every object in the linked list.
    // Pre:
    //      function takes two parameters and returns void
    // Basic guarantee - does not fix previous values if function throws in middle of dataset
    void traverse(std::function<void(key_type, data_type)> function) const
    {
        auto iter=_head;
        while(iter)
        {
            function(iter->_data.first, iter->_data.second);
            iter=iter->_next;
        }
    }

// ***** ListMap: data members *****
private:
    std::shared_ptr<LLNode2<std::pair<key_type, data_type>>> _head;
};

#endif // DA6_H_INCLUDED
