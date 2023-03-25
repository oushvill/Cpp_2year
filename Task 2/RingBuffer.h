#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;

template <typename T> class Iterator;

template <typename T>
class RingBuffer {

private:
    T* arr;
    size_t size;
    int first;
    int last;

public:
    RingBuffer();
    explicit RingBuffer(size_t size);
    RingBuffer(const RingBuffer& copy);
    void addInEnd(T elem);
    double getInStart();
    double checkInStart();
    [[nodiscard]] size_t getSizeBuffer() const;
    [[nodiscard]] bool isEmpty() const;
    void clearBuffer();

    ~RingBuffer();
    friend class Iterator<T>;
};

class MyException : public exception {
private:
    string m_error;
public:
    explicit MyException(string error) : m_error(std::move(error)) {}
    [[nodiscard]] const char* what() const noexcept override { return m_error.c_str(); }
};


template class RingBuffer<int>;
template class RingBuffer<double>;