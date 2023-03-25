#include "RingBuffer.h"
#include <iostream>
using namespace std;

template <typename T>
RingBuffer<T>::RingBuffer()
{
    size = 0;
    arr = new T[10];
    first = 0;
    last = 0;
}

template <typename T>
RingBuffer<T>::RingBuffer(size_t size1) //: size(size1 + 1), arr(new T[size1+1]), first(0), last(0)
{
    size = size1 + 1;
    arr = new T[size1 + 1];
    first = 0;
    last = 0;
}

template <typename T>
RingBuffer<T>::RingBuffer(const RingBuffer& copy) : size(copy.size), first(copy.first), last(copy.last), arr(new T[copy.size])
{
}

// Добавить элемент в конец очереди (при переполнении – исключение)
template <typename T>
void RingBuffer<T>::addInEnd(T elem)
{
    if (last == size) size++;
    if ((last + 1) % this -> size == first)
        throw MyException("Overflow");

    arr[last] = elem;
    last = (last + 1) % size;
}

// Взять элемент в начале очереди (при отсутствии – исключение)
template <typename T>
double RingBuffer<T>::getInStart()
{
    if (isEmpty()) throw MyException("Empty");

    double temp = arr[first];
    first = (first + 1) % size;
    size--;

    return temp;
}

// Получить элемент в начале очереди (без его изъятия)
template <typename T>
double RingBuffer<T>::checkInStart()
{
    if (isEmpty()) throw MyException("Empty");
    return arr[first];
}

// Размер очереди
template <typename T>
size_t RingBuffer<T>::getSizeBuffer() const
{
    return size - 1;
}

// Проверка очереди на пустоту
template <typename T>
bool RingBuffer<T>::isEmpty() const
{
    return first == last;
}

// Сделать очередь пустой
template <typename T>
void RingBuffer<T>::clearBuffer()
{
    first = 0;
    last = 0;
    std::cout << "Очередь была очищена!" << std::endl;
}


template <typename T>
RingBuffer<T>::~RingBuffer()
{
    clearBuffer();
    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }
    size = 0;
}