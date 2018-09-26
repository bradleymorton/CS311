// da3.h
// Bradley Morton
//Skeleton provided by Glenn G. Chappell
// 24 Sep 2018
//
// For CS 311 Fall 2018
// Header for Project 3 Functions

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <cstddef>
using std::size_t;

#include <vector>
//For std::vector
#include<stdexcept>
//For std::out_of_range

//Class provided by Glenn Chappel
// **************************************************************** // *
// Begin DO-NOT-CHANGE section                                      // *
// Do not alter the lines below                                     // *
// **************************************************************** // *
                                                                    // *
                                                                    // *
// struct LLNode                                                    // *
// Linked List node, with client-specified value type               // *
// Invariants:                                                      // *
//     Either _next is nullptr, or _next points to an LLNode,       // *
//      allocated with new, owned by *this.                         // *
// Requirements on Types:                                           // *
//     ValType must have a copy ctor and a (non-throwing) dctor.    // *
template <typename ValType>                                         // *
struct LLNode {                                                     // *
    ValType   _data;  // Data for this node                         // *
    LLNode *  _next;  // Ptr to next node, or nullptr if none       // *
                                                                    // *
    // The following simplify creation & destruction                // *
                                                                    // *
    // 1- & 2-param ctor                                            // *
    // _data is set to data (given). _next is set to next, if       // *
    // given, or nullptr if not.                                    // *
    // Pre:                                                         // *
    //     theNext, if passed, is either nullptr, or else it points // *
    //      to an LLNode allocated with new, with ownership         // *
    //      transferred to *this.                                   // *
    explicit LLNode(const ValType & data,                           // *
                    LLNode * next = nullptr)                        // *
        :_data(data),                                               // *
         _next(next)                                                // *
    {}                                                              // *
                                                                    // *
    // dctor                                                        // *
    // Does delete on _next.                                        // *
    ~LLNode()                                                       // *
    { delete _next; }                                               // *
                                                                    // *
    // No default ctor, copy, or move.                              // *
    LLNode() = delete;                                              // *
    LLNode(const LLNode & other) = delete;                          // *
    LLNode & operator=(const LLNode & other) = delete;              // *
    LLNode(LLNode && other) = delete;                               // *
    LLNode & operator=(LLNode && other) = delete;                   // *
                                                                    // *
};  // End struct LLNode                                            // *
                                                                    // *
                                                                    // *
// **************************************************************** // *
// End DO-NOT-CHANGE section                                        // *
// Do not alter the lines above                                     // *
// **************************************************************** // *


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 size_t index)
{
	for(index; index>=0; --index)
	{
		if(head==nullptr)
		{
			throw std::out_of_range("The index is larger than the list.");
		}
		head=head->_next;
	}
    return head->data;


template <typename Func>
void didItThrow(Func f,
                bool & threw)
{
    try
    {
    	f();
    }
    catch
    {
    	threw=true;
    	throw();
    }



	threw=false;
    return;
}


template <typename RAIter>
size_t uniqueCount(RAIter first,
                   RAIter last)
{
	std::vector<RAIter> uniqueCount;
	bool present=false;
	while(first!= last)
	{
		for(int i =0; i<uniqueCount.size(); ++i)
		{
			if(first->_data==uniqueCount[i])
			{
				present=true;
				break;
			}
		}
		if(present==false)
		{
			uniqueCount.push_back(first->_data);
		}

		present=false;
		first= first->_next;
	}
    return size_t(uniqueCount);
}


// Implementation in source file
int modExp(int a,
           int b,
           int n);


#endif  //#ifndef FILE_DA3_H_INCLUDED

