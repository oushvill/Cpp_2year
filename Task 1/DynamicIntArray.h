#pragma once
#include <iostream>

class DynamicIntArray
{
private:

    int* arr;
    size_t size;

public:

    DynamicIntArray();

    explicit DynamicIntArray(size_t size);

    DynamicIntArray(size_t size, int n);

    DynamicIntArray(const DynamicIntArray& din);

    DynamicIntArray(DynamicIntArray&& dynamic) noexcept;

    [[nodiscard]] size_t getSize() const;
    [[nodiscard]] int getElement(int i) const;
    void setSize(int size);
    void setElement(int i, int n);

    ~DynamicIntArray();

    int& operator[] (size_t index);

    void newSize(int newSize);

    DynamicIntArray& operator = (const DynamicIntArray& dyName);
    DynamicIntArray& operator = (DynamicIntArray&& dynamic) noexcept;

    friend bool operator == (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator != (const DynamicIntArray& d1, const DynamicIntArray& d2);

    friend bool operator > (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator <= (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator < (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator >= (const DynamicIntArray& d1, const DynamicIntArray& d2);

    friend DynamicIntArray operator + (DynamicIntArray& d1, DynamicIntArray& d2);

    friend std::ostream& operator << (std::ostream& out, const DynamicIntArray& dynamic);
    friend std::istream& operator >> (std::istream& in, DynamicIntArray& dynamic);
};