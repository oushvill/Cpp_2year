
#pragma once
using namespace std;

#include <iostream>
#include "stdio.h"


class Box {
public:
    int length;
    int width;
    int height;
    double weight;
    int value;

    Box(int lenght, int width, int height, double weight, int value);

    int getLength();
    int getWidth();
    int getHeight();
    double getWeight();
    int getValue();

    void setLenght(int lenght);
    void setWidth(int width);
    void setHeight(int height);
    void setWeight(double weight);
    void setValue(int value);

    //2. Суммарная стоимость всех коробок
    int sumValue(Box boxes[], int size);

    //3. Сумма длины, ширины и высоты всех коробок <= anySum
    bool noMaxSum(Box boxes[], int size, int anySum);

    //4. Максимальный вес коробок при объеме < maxV
    double maxWeight(Box boxes[], int size, int maxV);

    //5. Одна коробка может содержать другую
    bool boxInBox(Box boxes[], int size);
};
//6. Оператор сравнения
bool operator==(Box &boxes1, Box &boxes2);

//7. Операторы ввода/вывода
ostream &operator<<(ostream &out, Box &box);
istream &operator>>(istream &in, Box &box);


