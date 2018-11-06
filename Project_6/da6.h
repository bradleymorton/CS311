//Project 6 for CS311
//Andrew Adler, Ian Ferguson, Bradley Morton

#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include "llnode2.h"
#include <algorithm>
#include <functional>
#include <memory>
//For lldone.h

template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType>> & head);


template <typename Key, typename Data>
class ListMap {
    
public:
    
    using key_type= Key;
    using data_type= Data;
    
public:
    ListMap();
    ~ListMap()
    {}
    ListMap(const ListMap & base) = delete;
    ListMap(ListMap && other) = delete;
    ListMap & operator=(const ListMap & base) = delete;
    ListMap & operator=(const ListMap && other) = delete;
    int size()
    {
        return _size;
    }
    ListMap find();
    void insert(key_type key, data_type item);
    void erase(key_type key);
    ListMap traverse(std::function<void(key_type, data_type)> function);
    
private:
    int _size;
    std::shared_ptr<LLNode2<std::pair<key_type, data_type>>> _head;
};

#endif //DA6_H_INCLUDED
