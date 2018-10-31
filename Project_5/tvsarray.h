// tvsarray.h
// Andrew Adler
// Bradley Morton
// Ian Ferguson
// Started: 30 Oct 2018
// Updated: 1 Nov 2018

#ifndef TVSARRAY_H_INCLUDED
#define TVSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max;
// *********************************************************************
// class VSArray - Class definition
// *********************************************************************
// class VSArray
// Very Smart Array of int.
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
    // ***** VSArray: internal-use constants *****
private:
    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };
    // ***** VSArray: ctors, dctor, op= *****
public:
    // Default ctor & ctor from size
    // Strong Guarantee
    explicit TVSArray(size_type size=0)
    :_capacity(std::max(size, size_type(DEFAULT_CAP))),
    // _capacity must be declared before _data
    _size(size),
    _data(new value_type[_capacity])
    {}
    // Copy ctor
    // Strong Guarantee
    TVSArray(const TVSArray & other):
                                    _size(other.size()),
                                    _data(new value_type[other.size()]),
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
    TVSArray(TVSArray && other) noexcept: _size(other.size()), _data(other._data )
    {
        other._size=0;
        other._data= nullptr;
    }

    // Copy assignment operator
    // ??? Guarantee
    TVSArray & operator=(const TVSArray & other)
    {
        TVSArray temp(other);
        mswap(temp);
        return *this;
    }
    // Move assignment operator
    // No-Throw Guarantee
    TVSArray & operator=(TVSArray && other) noexcept
    {
        if(this == &other)
        {
            return *this;
        }
        std::swap(_size, other._size);
        std::swap(_data, other._data);

        return *this;
    }
    // Dctor
    // No-Throw Guarantee
    ~TVSArray()
    {
        delete [] _data;
    }
    // ***** VSArray: general public operators *****
public:
    // operator[] - non-const & const
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }
    // ***** VSArray: general public functions *****
public:
    // size
    // No-Throw Guarantee
    size_type size() const
    {
        return _size;
    }
    // empty
    // No-Throw Guarantee
    bool empty() const
    {
        return size() == 0;
    }
    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin()
    {
        return _data;
    }
    const_iterator begin() const
    {
        return _data;
    }
    // end - non-const & const
    // No-Throw Guarantee
    iterator end()
    {
        return begin() + size();
    }
    const_iterator end() const
    {
        return begin() + size();
    }
    // resize
    // ??? Guarantee
    void resize(size_type newsize)
    {
        if (newsize <= _capacity)
        {
            _size = newsize;
        }

        else
        {
            _capacity = std::max(2*_capacity,newsize);
            value_type * temp = new value_type[_capacity];
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
        }
    }
    // insert
    // ??? Guarantee
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
    // ??? Guarantee
    iterator erase(iterator pos)
    {
        return begin();
    }
    // push_back
    // InsertEnd operation.
    // ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
        ++_size;
    }
    // pop_back
    // RemoveEnd operation.
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
        --_size;
    }
    // swap
    // No-Throw Guarantee
    void swap(TVSArray & other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }
    // ***** TVSArray: data members *****
public:
    public:
    size_type getCapacity()
    {
        return _capacity;
    }
private:
    void mswap(TVSArray & toSwap) noexcept
    {
        std::swap(_size, toSwap._size);
        std::swap(_data, toSwap._data);
    }
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to array
};  // End class TVSArray

#endif // TVSARRAY_H_INCLUDED



// void resize(size_type newSize)
//     {
//         if (newSize <= _capacity)
//         {
//             _size = newSize;
//         }

//         else
//         {
//             auto temp =new value_type[newSize+50000];
//             std::copy(begin(),end(),temp);
//             std::swap(temp, _data);
//             delete [] temp;
//             _capacity=newSize+50000;
//             _size=newSize;
//         }
//     }
