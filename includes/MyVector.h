#pragma once
#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned int size_t;
#endif

template<typename T>
class _vector
{
public:
    typedef T value_type;
    typedef T* iterator;
    _vector() :_data(nullptr), _size(0), _capacity(0) {};
    _vector(const _vector& vec);
    ~_vector();
    _vector& operator=(const _vector& vec)
    {
        if (this == &vec) return *this;
        value_type* temp = new value_type[vec._capacity];
        for (int i = 0; i < vec._size; ++i) {
            temp[i] = vec._data[i];
        }
        delete[] _data;
        _data = temp;
        _size = vec._size;
        _capacity = vec._capacity;
        return *this;
    }
    value_type& operator[](size_t index) {
        return _data[index];
    }
    bool operator==(const _vector& vec)const {
        if (_size != vec._size) return false;
        for (int i = 0; i < _size; ++i) {
            if (_data[i] != vec._data[i])
                return false;
        }
        return true;
    }
    void clear();
    void push_back(value_type val);
    void insert(iterator it, value_type val);
    void pop_back();
    void erase(iterator it);
    void reserve(size_t new_capacity);
    void resize(size_t new_size);
    value_type front()const;
    value_type back()const;
    iterator begin();
    iterator end();
    size_t size()const;
    size_t capacity()const;
    bool empty();
private:
    value_type* _data;
    size_t _size;
    size_t _capacity;
};

template<typename T>
inline _vector<T>::_vector(const _vector& vec)
{
    _size = vec._size;
    _capacity = vec._capacity;
    _data = new value_type[_capacity];
    for (int i = 0; i < _size; ++i) {
        _data[i] = vec._data[i];
    }
}

template<typename T>
inline _vector<T>::~_vector()
{
    clear();
}

template<typename T>
inline void _vector<T>::clear()
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template<typename T>
inline void _vector<T>::push_back(value_type val)
{
    if (0 == _capacity) {
        _capacity = 1;
        _data = new value_type[1];
    }
    else if (_size + 1 > _capacity) {
        _capacity *= 2;
        value_type* temp = new value_type[_capacity];
        for (int i = 0; i < _size; ++i) {
            temp[i] = _data[i];
        }
        delete[] _data;
        _data = temp;
    }
    _data[_size] = val;
    ++_size;
}

template<typename T>
inline void _vector<T>::insert(iterator it, value_type val)
{
    int index = it - _data;
    if (0 == _capacity) {
        _capacity = 1;
        _data = new value_type[1];
        _data[0] = val;
    }
    else if (_size + 1 > _capacity) {
        _capacity *= 2;
        value_type* temp = new value_type[_capacity];
        for (int i = 0; i < index; ++i) {
            temp[i] = _data[i];
        }
        temp[index] = val;
        for (int i = index; i < _size; i++) {
            temp[i + 1] = _data[i];
        }
        delete[] _data;
        _data = temp;
    }
    else {
        for (int i = _size - 1; i >= index; --i) {
            _data[i + 1] = _data[i];
        }
        _data[index] = val;
    }
    ++_size;
}

template<typename T>
inline void _vector<T>::pop_back()
{
    --_size;
}

template<typename T>
inline void _vector<T>::erase(iterator it)
{
    size_t index = it - _data;
    for (int i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }
    --_size;
}

template<typename T>
inline void _vector<T>::reserve(size_t new_capacity)
{
    if (new_capacity < _capacity) _capacity = _capacity;
    else {
        _capacity = new_capacity;
        iterator temp = _data;
        _data = new value_type[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _data[i] = temp[i];
        }
        delete temp;
    }   
}

template<typename T>
inline void _vector<T>::resize(size_t new_size)
{
    if (new_size <= _size) _size = _size;
    else
    {
        if (new_size > _capacity) reserve(2 * new_size + 1);
        _size = new_size;
    }
}

template<typename T>
inline T _vector<T>::front() const
{
    return _data[0];
}

template<typename T>
inline T _vector<T>::back() const
{
    return _data[_size - 1];
}

template<typename T>
inline T* _vector<T>::begin()
{
    return _data;
}

template<typename T>
inline T* _vector<T>::end()
{
    return _data + _size;
}

template<typename T>
inline size_t _vector<T>::size() const
{
    return _size;
}

template<typename T>
inline size_t _vector<T>::capacity() const
{
    return _capacity;
}

template<typename T>
inline bool _vector<T>::empty()
{
    return _size == 0;
}


