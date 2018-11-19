// treesort.h  INCOMPLETE
// Glenn G. Chappell
// 12 Nov 2018
//
// For CS 311 Fall 2018
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
using std::iterator_traits;
#include <algorithm>
using std::stable_sort;
using std::move;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;


//BSTreeNode(Binary Search Tree Node)
//struct (No member types needed to be private)
//Binary Search Tree Node template. Ownership of objects belongs to a shared_ptr.
//Empty trees consist of an empty shared_ptr.
//Invariants:
//  _data = data
//  _left = left in the node or a nullptr
//  _right = right in the node or a nullptr

template<typename ValueType>
struct BSTreeNode
{
    ValueType _data;
    std::shared_ptr<BSTreeNode<ValueType>> _left;
    std::shared_ptr<BSTreeNode<ValueType>> _right;
    
    explicit BSTreeNode(const ValueType & data, std::shared_ptr<BSTreeNode<ValueType>> left = nullptr, std::shared_ptr<BSTreeNode<ValueType>> right = nullptr): _data(data), _left(left), _right(right) {}
    ~BSTreeNode() = default;
};

//Insert
//This function inserts a node into the correct position in a Binary Search Tree by comparing data to _data in the node's "children" and recursively calls the left or right children until it comes across a nullptr, which it will replace.
//Pre:
//  node MUST be a sharedptr to our BSTreeNode
//
template<typename ValueType>
void insert(std::shared_ptr<BSTreeNode<ValueType>> & node, const ValueType & data)
{
    if(node == nullptr)
    {
        node = std::make_shared<BSTreeNode<ValueType>>(data);
        return;
    }
    
    //Any data that is less than the node's data goes to the left of the node
    if(data< node->_data)
    {
        insert(node->_left, data);
    }
}


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // ValType is the type that FDIter points to
    using ValType = typename iterator_traits<FDIter>::value_type;

}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

