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

template<typename ValueType>
struct BSTreeNode
{
    ValueType _data;
    std::shared_ptr<BSTreeNode<ValueType>> _left;
    std::shared_ptr<BSTreeNode<ValueType>> _right;
    
    explicit BSTreeNode(const ValueType & data, std::shared_ptr<BSTreeNode<ValueType>> left = nullptr, std::shared_ptr<BSTreeNode<ValueType>> right = nullptr): _data(data), _left(left), _right(right) {}
    ~BsTreeNode() = default;
};


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

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS, BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE PROJECT.
    vector<ValType> buff(distance(first, last));
    move(first, last, buff.begin());
    stable_sort(buff.begin(), buff.end());
    move(buff.begin(), buff.end(), first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

