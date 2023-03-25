#include "DynamicIntArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Конструктор по умолчанию
DynamicIntArray::DynamicIntArray()
{
    this -> size = 10;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    cout << "Вызван конструктор по умолчанию!" << endl;
}

// Конструктор по размеру
DynamicIntArray::DynamicIntArray(size_t size)
{
    this -> size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    cout << "Вызван конструктор по размеру!" << endl;
}

// Конструктор по размеру и числу
DynamicIntArray::DynamicIntArray(size_t size, int n)
{
    this -> size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = n;
    cout << "Вызван конструктор по размеру и числу!" << endl;
}

// Конструкторы копирования и перемещения
DynamicIntArray::DynamicIntArray(const DynamicIntArray& din)
{
    size = din.size;
    arr = new int[size];
    for (size_t i = 0; i < din.size; i++)
        arr[i] = din.arr[i];
    cout << "Вызван конструктор копирования!" << endl;
}
DynamicIntArray::DynamicIntArray(DynamicIntArray&& dynamic) noexcept :arr(dynamic.arr), size(dynamic.size)
{
    dynamic.arr = nullptr;
    dynamic.size = 0;
}

size_t DynamicIntArray::getSize() const { return size; }

int DynamicIntArray::getElement(int i) const { return arr[i]; }

void DynamicIntArray::setSize(int arrSize)
{
    this -> size = arrSize;
}

void DynamicIntArray::setElement(int i, int n)
{
    this -> arr[i] = n;
}

// Деструктор
DynamicIntArray::~DynamicIntArray()
{
    delete[] arr;
    cout << "Вызван деструктор!" << endl;
}

// Доступ к элементу
int& DynamicIntArray::operator[] (size_t index)
{
    return arr[index];
}

// Изменение размера
void DynamicIntArray::newSize(int newSize)
{
    int* newArray = new int[newSize];

    if (size >= newSize)
    {
        for (int i = 0; i < newSize; i++)
            newArray[i] = arr[i];

        delete[] arr;
        size = newSize;
        this -> arr = newArray;
    }

    if (size < newSize)
    {
        for (int i = 0; i < size; i++)
            newArray[i] = arr[i];

        for (int k = 0; k < newSize - size; k++)
            newArray[k + size] = 0;

        delete[] arr;
        size = newSize;
        this -> arr = newArray;
    }
}

// Операторы присваивания и перемещения
DynamicIntArray& DynamicIntArray::operator = (const DynamicIntArray& dyName)
{
    if (this == &dyName)
        return *this;

    delete[] arr;
    size = dyName.size;
    arr = new int[size];
    for (size_t i = 0; i < size; i++)
        arr[i] = dyName.arr[i];

    return *this;
}

DynamicIntArray& DynamicIntArray::operator = (DynamicIntArray&& dynamic) noexcept
{
    delete[] arr;
    size = dynamic.size;
    arr = dynamic.arr;
    dynamic.arr = nullptr;
    cout << "Вызвано перемещающее присваивание!" << endl;
    return *this;
}

bool operator == (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    bool flag = true;
    size_t size1 = d1.size;
    size_t size2 = d2.size;
    if (size1 != size2) flag = false;

    for (size_t i = 0; i < size1; i++)
        if (d1.arr[i] != d2.arr[i]) flag = false;

    return flag;
}

bool operator != (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    bool flag = !(d1 == d2);
    return flag;
}

bool operator > (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    bool flag = true;
    size_t size1 = d1.size;
    size_t size2 = d2.size;
    if (size1 <= size2) flag = false;

    if (size1 == size2) {
        for (size_t i = 0; i < size1; i++)
            if (d1.arr[i] <= d2.arr[i]) flag = false;
    }

    return flag;
}

bool operator >= (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    bool flag = true;
    size_t size1 = d1.size;
    size_t size2 = d2.size;
    if (size1 < size2) flag = false;

    if (size1 == size2) {
        for (size_t i = 0; i < size1; i++)
            if (d1.arr[i] < d2.arr[i]) flag = false;
    }

    return flag;
}

bool operator < (const DynamicIntArray& d1, const DynamicIntArray& d2) // Ошибки
{
    bool flag = true;
    size_t size1 = d1.size;
    size_t size2 = d2.size;
    if (size1 >= size2) flag = false;

    if (size1 == size2) {
        for (size_t i = 0; i < size1; i++)
            if (d1.arr[i] >= d2.arr[i]) flag = false;
    }

    return flag;
}

bool operator <= (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    bool flag = true;
    size_t size1 = d1.size;
    size_t size2 = d2.size;
    if (size1 > size2) flag = false;

    if (size1 == size2) {
        for (size_t i = 0; i < size1; i++)
            if (d1.arr[i] > d2.arr[i]) flag = false;
    }

    return flag;
}

DynamicIntArray operator + (DynamicIntArray& d1, DynamicIntArray& d2)
{
    DynamicIntArray result = DynamicIntArray(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++)
        result.arr[i] = d1[i];

    for (size_t i = d1.size; i < (d1.size + d2.size); i++)
        result.arr[i] = d2[i - d1.size];

    return result;
}

ostream& operator << (ostream& out, const DynamicIntArray& dynamic)
{
    out << "DynamicIntArray( ";
    for (int i = 0; i < dynamic.size; i++)
        out << dynamic.arr[i] << " ";
    out << ")";

    return out;
}

istream& operator >> (istream& in, DynamicIntArray& dynamic)
{
    for (int i = 0; i < dynamic.size; i++)
        in >> dynamic.arr[i];

    return in;
}