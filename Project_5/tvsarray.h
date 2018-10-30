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
class TVSArray {
    // ***** TVSArray: types *****
public:
    // value_type: type of data items
    using value_type = int;
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
    TVSArray(const TVSArray & other);
    // Move ctor
    // No-Throw Guarantee
    TVSArray(TVSArray && other) noexcept;
    // Copy assignment operator
    // ??? Guarantee
    TVSArray & operator=(const TVSArray & other);
    // Move assignment operator
    // No-Throw Guarantee
    TVSArray & operator=(TVSArray && other) noexcept;
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
    void resize(size_type newsize);
    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item);
    // erase
    // ??? Guarantee
    iterator erase(iterator pos);
    // push_back
    // InsertEnd operation.
    // ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }
    // pop_back
    // RemoveEnd operation.
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }
    // swap
    // No-Throw Guarantee
    void swap(TVSArray & other) noexcept;
    // ***** TVSArray: data members *****
private:
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to array
};  // End class TVSArray

#endif // TVSARRAY_H_INCLUDED
