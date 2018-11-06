// tvsarray.h
// Andrew Adler
// Bradley Morton
// Ian Ferguson
// Started: 30 Oct 2018
<<<<<<< HEAD
// Updated: 01 Nov 2018
=======
// Updated: 1 Nov 2018
>>>>>>> a311fca01338948ec830722b7c639a743585f686

#ifndef TVSARRAY_H_INCLUDED
#define TVSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max;
// *********************************************************************
// class TVSArray - Class definition
// *********************************************************************
// class TVSArray
<<<<<<< HEAD
// Templated Very Smart Array of a template type.
=======
// Templated Very Smart Array of template type.
>>>>>>> a311fca01338948ec830722b7c639a743585f686
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of an arbitary value type, allocated with new[], owned by
//      *this, holding _capacity of the arbitrary value type. Except: _data may be nullptr, if
//      _capacity == 0.
template<typename T>
class TVSArray {
    // ***** TVSArray: types *****
public:
    // value_type: type of data items
    using value_type = T;
    // size_type: type of sizes & indices
    using size_type = std::size_t;
    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;
    // ***** TVSArray: internal-use constants *****
private:
    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };
    // ***** TVSArray: ctors, dctor, op= *****
public:
    // Default ctor & ctor from size
    // Strong Guarantee
    // No pre or post conditions
    explicit TVSArray(size_type size=0)
    :_capacity(std::max(size, size_type(DEFAULT_CAP))),
    // _capacity must be declared before _data
    _size(size),
    _data(new value_type[_capacity])
    {}
    // Copy ctor
    // Strong Guarantee
    // Precondition- a valid tvsarray object to copy from
    // Postcondition- a new object is created. 
    TVSArray(const TVSArray & other):
                                    _size(other.size()),
                                    _data(new value_type[other._capacity]),
                                    _capacity(other._capacity)
    {
        try
        {
            std::copy(other.begin(),other.end(),begin());
        }
        catch(...)
        {
            this->~TVSArray();
            throw;
        }
    }
    // Move ctor
    // No-Throw Guarantee
    // Precondition- a valid tvsarray object to move from
    // Postcondition- the other object is no longer usable
    TVSArray(TVSArray && other) noexcept: _size(other.size()), _data(other._data )
    {
        other._size=0;
        other._data= nullptr;
    }

    // Copy assignment operator
    // Strong Guarantee
    // Precondition- a valid tvsarray item
    TVSArray & operator=(const TVSArray & other)
    {
        TVSArray temp(other);
        swap(temp);
        return *this;
    }
    // Move assignment operator
    // No-Throw Guarantee
    // Precondition- a valid tvsarray object
    TVSArray & operator=(TVSArray && other) noexcept
    {
        if(this == &other)
        {
            return *this;
        }
        swap(other);

        return *this;
    }
    // Dctor
    // No-Throw Guarantee
    // No pre or post conditions. 
    ~TVSArray()
    {
        delete [] _data;
    }
    // ***** TVSArray: general public operators *****
public:
    // operator[] - non-const & const
    // No-Throw Guarantee
    // Precondition- value is within the size of the tvsarray
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }
    // ***** TVSArray: general public functions *****
public:
    // size
    // No-Throw Guarantee
    // No pre or post conditions
    size_type size() const
    {
        return _size;
    }
    // empty
    // No-Throw Guarantee
    // No pre or post conditions
    bool empty() const
    {
        return size() == 0;
    }
    // begin - non-const & const
    // No-Throw Guarantee
    // No pre or post conditions
    iterator begin()
    {
        return _data;
    }
    // No pre or post conditions
    const_iterator begin() const
    {
        return _data;
    }
    // end - non-const & const
    // No-Throw Guarantee
    // No pre or post conditions
    iterator end()
    {
        return begin() + size();
    }
    // No pre or post conditions
    const_iterator end() const
    {
        return begin() + size();
    }
    // resize
    // Strong Guarantee
    // Postcondition- the new tvsarray size is the size passed
    void resize(size_type newsize)
    {
        if (newsize <= _capacity)
        {
            _size = newsize;
        }
        else
        {
            size_type newCapacity=std::max(2*_capacity,newsize);
            value_type * temp = new value_type[newCapacity];
            try
            {
                std::copy(begin(),end(),temp);
            }
            catch(...)
            {

                delete[] temp;
                throw;
            }
            delete[] _data;
            _data = temp;
            _size = newsize;
            _capacity = newCapacity;
        }
    }
    // insert
    // Basic Guarantee
    // Precondition- position passed is within the size of the tvsarray
    // Postcondition- the value passed was inserted into the tvsarray at the position passed and the size increases by one
    iterator insert(iterator pos,
                    const value_type & item)
    {
        size_type index = pos - begin();
        resize(_size+1);
        _data[_size-1] = item;
        iterator i = begin() + index;

        try
        {
            std::rotate(i, begin() + _size -1, end());
        }
        catch (...) {
            resize(_size -1);
            throw;
        }

        return i;
    }
    // erase
    // Strong Guarantee
    // Precondition- position passed is within the size of the tvsarray
    // Postcondition- the value passed was removed from the tvsarray at the position passed and the size decreases by one
    iterator erase(iterator pos)
    {
        std::rotate(pos,pos+1,end());
        resize(_size - 1);
        return pos;
    }
    // push_back
    // InsertEnd operation.
    // Strong Guarantee
    // Postcondition- size is one larger, and the last entry is the passed value
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }
    // pop_back
    // RemoveEnd operation.
    // Strong Guarantee
    // Postcondition- the tvsarray has a size decrease of one
    void pop_back()
    {
        erase(end()-1);
    }
    // swap
    // No-Throw Guarantee
    // Postcondition- the values of all member variables are swapped with those of the other tvsarray
    void swap(TVSArray & other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }
    // ***** TVSArray: data members *****
private:
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to array
};  // End class TVSArray

#endif // TVSARRAY_H_INCLUDED