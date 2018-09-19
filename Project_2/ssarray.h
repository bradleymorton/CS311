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
	value_type= *_array;


public: 

	//Default constructor
	//No preconditions
	//Postconditions: array with size 8 exists
	SSArray(): _size(8), _array(new value_type[_size])
	{}

	//1 parameter constructor
	//Precondition- number for size must be at greater than or equal to zero
	//Postcondition- array of size passed of type passed is created. 
	SSArray(int size) : _size(size), _array(new value_type[_size])[]
	{}

	//2 parameter constructor
	//Takes size and ArrayType value
	//Precondition- size must be greater than or equal to 0
	//Postcondition- array of size and type passed is filled with value passed
	SSArray(int size, ArrayType value) : _size(size), _array(new value_type)[_size][]
	{
		for(int i=0, i<_size, ++i)
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
	SSArray(const SSArray & base) : _size(base.size(), _array(new value_type[base.size()]))
	{
		for(int i=0; i<_size; ++i)
		{
			_array[i]=base.[i];
		}
	}

	//Move constructor
	//Precondition- the prior SSArray object was valid
	//Poscondition- a new SSArray with the data of the old array will
	//be created and the old SSArray will be set to null
	SSArray(SSArray && oldSSArray) : _size(oldSSArray.size(), _array(base._array))
	{
		oldSSArray._size=0;
		oldSSArray._array= NULL;
	}


	//Copy assignment operator
	//Precondition- a valid SSArray object must exist
	//Postcondition- a new object with the same size and data
	//exists, and the original can be altered without altering
	//the new object. 
	SSArray & operator=(const SSArray & base)
	{
		SSArray temp(base);
		std::swap(temp._size, _size);
		std::swap(temp._array, _array);
		return *this;

	}


	//Move assignment operator
	//Precondition- there must be a valid existing SSArray object. 
	//Postconditions- a new SSArray with the size and items of the 
	//first is created, and the other array still holds its values. 
	SSArray & operator = (SSArray && base) noexcept
	{
		std::swap(temp._size, _size);
		std::swap(temp._array, _array);
		return *this;
	}


	//Returns the size of the SSArray
	//No pre or post conditions
	std::size_t size()
	{
		return _size;
	}


	//begin
	//No precondtions or post conditions
	value_type * begin()
	{
		return 
	}




};






















#endif