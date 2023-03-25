#pragma once
#include "RingBuffer.h"

template <typename T> class RingBuffer;

template <typename T>
class Iterator {

private:
    int index;
    RingBuffer<T> *queue;

public:
    friend class Queue;
    explicit Iterator(RingBuffer<T>& que);
    void start();
    void next();
    bool finish();
    T getValue();
};

template class Iterator<int>;
template class Iterator<double>;