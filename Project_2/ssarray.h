//ssarray.h
//Bradley Morton 9/18/18
//For CS311
//Holds a template for an array with more functionality than an array, but less than a vector. 

#ifndef SSARRAY_H
#define SSARRAY_H



#include <algorithm>


//Template SSArray
//Array with known size, written big five silent functions, bracket operators, begin, end
//Invariants: size_type must be >=0, the template type must have valid = and < operators
template <typename ArrayType>
class SSArray
{
//variables
public: //Member types
	using value_type=ArrayType;
	using size_type= std::size_t;
private: //Data members
	size_type _size;
	value_type *_array;


public: 

	//Default constructor
	//No preconditions
	//Postconditions: array with size 8 exists
	SSArray(): _size(8), _array(new value_type[8])
	{}

	//1 parameter constructor
	//Precondition- number for size must be at greater than or equal to zero
	//Postcondition- array of size passed of type passed is created. 
	SSArray(int size) : _size(size), _array(new value_type[size])
	{}

	//2 parameter constructor
	//Takes size and ArrayType value
	//Precondition- size must be greater than or equal to 0
	//Postcondition- array of size and type passed is filled with value passed
	SSArray(int size, ArrayType value) : _size(size), _array(new value_type[size])
	{
		for(int i=0; i<_size; ++i)
		{
			_array[i]=value;
		}
	}


	//Destructor
	~SSArray()
	{
		delete[] _array;
	}


	//Copy constructor
	//Precondition- a valid SSArray object
	//Postcondition- a new SSArray object has been created. 
	SSArray(const SSArray & base) : _size(base.size()), _array(new value_type[base.size()])
	{
		for(int i=0; i<_size; ++i)
		{
			_array[i]=base[i];
		}
	}

	//Move constructor
	//Precondition- the prior SSArray object was valid
	//Poscondition- a new SSArray with the data of the old array will
	//be created and the old SSArray will be set to null
	SSArray(SSArray && oldSSArray)noexcept : _size(oldSSArray.size()), _array(oldSSArray._array ) 
	{
		oldSSArray._size=0;
		oldSSArray._array= nullptr;
	}


	//Copy assignment operator
	//Precondition- a valid SSArray object must exist
	//Postcondition- a new object with the same size and data
	//exists, and the original can be altered without altering
	//the new object. 
	SSArray & operator=(const SSArray & base)
	{
		SSArray temp(base);
		mswap(temp);
		return *this;

	}


	//Move assignment operator
	//Precondition- there must be a valid existing SSArray object. 
	//Postconditions- a new SSArray with the size and items of the 
	//first is created, and the other array still holds its values. 
	SSArray & operator = (SSArray && base) noexcept
	{
		mswap(base);    //make mswap member
		return *this;
	}

	private: 
	//mswap
	//A function that swaps the size and elements
	//of two SSArrays
	//Precondition- both SSArrays are valid. 
	void mswap(SSArray & toSwap) noexcept
	{
		std::swap(_size, toSwap._size);
		std::swap(_array, toSwap._array);
	}
	public: 
	//Returns the size of the SSArray
	//No pre or post conditions
	std::size_t size()const
	{
		return _size;
	}


	//begin
	//No precondtions or post conditions
	value_type * begin()
	{
		return _array;
	}


	//const begin
	//No precondtions or post conditions
	const value_type * begin()const
	{
		return _array;
	}

	//end
	//No preconditions or postconditions
	value_type * end()
	{
		return _array+_size;
	}

	//const end
	//No preconditions or postconditions
	const value_type * end()const
	{
		return _array+_size;
	}

	//[] operator
	//Preconditon- 0<=input<size
	//Postconditions- none
	value_type & operator[](const size_type index)
	{
		return _array[index];
	}

	//const [] operator
	//Preconditon- 0<=input<size
	//Postconditions- none
	const value_type & operator[](const size_type index)const
	{
		return _array[index];
	}


};


//Equality operator (==)
//Returns true if two SSArrays with the same type are compared and
//the SSArrays are the same size and possess the same elements in
//the same locations, and otherwise returns false.  
//Precondition- both SSArrays must be of the same type. 
template <typename ArrayType>
bool operator==(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	if(lhs.size()!=rhs.size())
	{
		return false;
	}
	for(int i=0; i<lhs.size(); ++i)
	{
		if(lhs[i]!=rhs[i])
			return false;
	}
	return true;
}

//Inequality operator (!=)
//Returns true if two SSArrays of the same type have different sizes 
//or they have at least one different element, returns false. 
//Precondition- both SSArrays must be of the same type. 
template<typename ArrayType>
bool operator!=(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	return !(lhs==rhs);
}


//Less than operator (<)
//Takes two SSArrays of the same type, compares first element of each.
//Returns true if the first SSArray's element is lower than the first 
//element of the second. If the first of each are the same, it moves 
//to the next and looks again.  
//Precondition- both SSArrays must be of the same type. 
template <typename ArrayType>
bool operator <(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}


//Less than or equal operator (<=)
//Takes two SSArrays of the same type, compares first element of each.
//Returns true if the first SSArray's element is less than or equal to 
//the first element of the second. If the first of each are the same, it moves 
//to the next and looks again.  
//Precondition- both SSArrays must be of the same type. 
template <typename ArrayType>
bool operator <=(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	return !(rhs<lhs);
}

//Greater than operator (>)
//Takes two SSArrays of the same type, compares first element of each.
//Returns true if the first SSArray's element is higher than the first 
//element of the second. If the first of each are the same, it moves 
//to the next and looks again.  
//Precondition- both SSArrays must be of the same type.
template <typename ArrayType>
bool operator >(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	return rhs<lhs;
}


//Greater than or equal operator (>=)
//Takes two SSArrays of the same type, compares first element of each.
//Returns true if the first SSArray's element is greater than or equal to 
//the first element of the second. If the first of each are the same, it moves 
//to the next and looks again.  
//Precondition- both SSArrays must be of the same type. 
template <typename ArrayType>
bool operator >=(const SSArray<ArrayType> & lhs, const SSArray<ArrayType> & rhs)
{
	return !(lhs<rhs);
}














#endif