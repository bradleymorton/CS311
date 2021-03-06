// treesort.h
// Code done by Ian Ferguson, Andrew Adler, and Bradley Morton Working from Glenn L. Chappel's skeleton code
// Created: 18 Nov 2018
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
using std::distance;
#include <memory>


//BSTreeNode(Binary Search Tree Node)
//struct (No member types needed to be private)
//Binary Search Tree Node template. Ownership of objects belongs to a shared_ptr.
//Empty trees consist of an empty shared_ptr.
//Invariants:
//      _data = data
//      _left = left in the node or a nullptr
//      _right = right in the node or a nullptr
//Requirements on Types:
//      ValueType needs to have a copy constructor 
//      ValueType needs to have a destructor which must not throw
//      ValueType must have a < operator
template<typename ValueType>
struct BSTreeNode
{
    ValueType _data;
    std::shared_ptr<BSTreeNode<ValueType>> _left;
    std::shared_ptr<BSTreeNode<ValueType>> _right;

    // Constructor which creates a BSTreeNode with no children by default
    // Can take children as additional parameters
    // Pre:
    //     data must not be empty
    // Exceptions:
    //      Throws when a ValueType operation throws
    // Strong guarantee, exception neutral
    explicit BSTreeNode(const ValueType & data, 
                        std::shared_ptr<BSTreeNode<ValueType>> left = nullptr, 
                        std::shared_ptr<BSTreeNode<ValueType>> right = nullptr)
                            : _data(data), 
                              _left(left), 
                              _right(right) 
    {}

    // Destructor
    ~BSTreeNode() = default;
};

// insert
// This function inserts a node into the correct position in a Binary Search Tree by comparing 
    // data to _data in the node's "children" and recursively calls the left or right children 
    // until it comes across a nullptr, which it will replace.
//Requirements on Types:
//      ValueType needs to have a copy constructor 
//      ValueType needs to have a destructor which must not throw
//      ValueType must have a < operator
// Exceptions:
//      Throws when a Valuetype operation throws
//      std::make_shared may throw
// Strong guarantee, exception neutral
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
    //If anything doesn't fit this case, we'll assume that it's equal to or greater than the node's data.
    else
    {
        insert(node -> _right, data);
    }
}

// traversal
// Recursively performs an inorder traversal of a binary search tree
// Requirements on Types:
//      ValueType needs to have a copy constructor 
//      ValueType needs to have a destructor which must not throw
//      ValueType must have a < operator
//      FDIter must be a forward iterator
// Exceptions:
//      Throws when a Valuetype operation throws
//      std::make_shared may throw
// No-Throw guarantee, Exception neutral
template<typename ValueType,typename FDIter>
void traversal(std::shared_ptr<BSTreeNode<ValueType>> & node, FDIter & iter)
{
	if(node==nullptr)   // Once the end of a branch is reached
	{
		return;
	}

	traversal(node->_left, iter);   // Traverse left branch
	*iter++=node->_data;            // Update iter with the data from the next inorder node
	traversal(node->_right, iter);  // Traverse right branch
}

// treesort
// Sort a given range using Treesort.
// Pre:
//      Insert must be written and have its own pre-conditions satisfied.
//      first and last must form a valid iterator range
// Requirements on Types:
//      ValueType needs to have a copy constructor 
//      ValueType needs to have a destructor which must not throw
//      ValueType must have a < operator
//      FDIter must be a forward iterator
// Exceptions:
//      Throws when a Valuetype operation throws
//      std::make_shared may throw
// Strong guarantee, exception neutral
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // ValueType is the type that FDIter points to
    using ValueType = typename iterator_traits<FDIter>::value_type;

    //Creates a Binary Search Tree by creating an empty Tree Node then using insert to iterate through and fill each
        //value.
    std::shared_ptr<BSTreeNode<ValueType>> head = nullptr;
    for(FDIter item = first; item != last; ++item)
    {
        insert(head, *item);
    }

    traversal(head, first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

