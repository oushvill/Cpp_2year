#include "Iterator.h"

// Конструктор, который привязывает итератор к очереди
template <typename T>
Iterator<T>::Iterator(RingBuffer<T>& que) : index(que.first), queue(&que)
{
}

// Начать перебор элементов
template <typename T>
void Iterator<T>::start()
{
    index = queue -> first;
}

// Перейти к следующему элементу
template <typename T>
void Iterator<T>::next()
{
    index = (index + 1) % queue -> size;
}

// Проверка, все ли проитерировано
template <typename T>
bool Iterator<T>::finish()
{
    if (queue -> isEmpty()) return true;

    return index == queue -> last;
}

// Получить очередной элемент очереди
template <typename T>
T Iterator<T>::getValue()
{
    return queue -> arr[index];
}