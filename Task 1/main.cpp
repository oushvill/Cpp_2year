#include "DynamicIntArray.h"
#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001");

    // Конструктор по умолчанию
    DynamicIntArray dArr1 = DynamicIntArray();
    cout << dArr1;
    cout << endl;    cout << endl;

    // Конструктор по размеру
    DynamicIntArray dArr2 = DynamicIntArray(5);
    cout << dArr2;
    cout << endl;    cout << endl;

    // Конструктор по размеру и числу n
    DynamicIntArray dArr3 = DynamicIntArray(10, 5);
    cout<<dArr3;
    cout << endl;    cout << endl;

    // Конструктор копирования
    DynamicIntArray dArr4 = DynamicIntArray(dArr3);
    cout << dArr4;
    cout << endl;

    // Изменение размера
    dArr4.newSize(4);
    cout << "Изменение рамзмера: " << dArr4;
    cout << endl;
    dArr4.newSize(10);
    cout << "Изменение рамзмера: " << dArr4;
    cout << endl;

    // Присваивание массивов
    dArr1 = dArr4;
    cout << "Присвоим массиву dArr1 массив dArr4" << dArr1;
    cout << endl;       cout << endl;

    // Соединение массивов
    DynamicIntArray dArr7(5, 2);
    DynamicIntArray dArr8(6, 3);
    DynamicIntArray dArr9 = DynamicIntArray();
    dArr9 = dArr7 + dArr8;
    cout << "Склеивание массив dArr7(5, 2) и dArr8(6, 3) массивов: "  << dArr9;
    cout << "\n" << endl;

    // Сравнение массивов
    DynamicIntArray dArr11 = DynamicIntArray(2, 1);
    DynamicIntArray dArr12 = DynamicIntArray(7, 1);
    cout << "Сравнение массивов: " << endl;

    bool exp1 = dArr11 == dArr12;
    cout << "dArr11(2, 1) == dArr12(7, 1)?: ";
    cout << exp1 << endl;

    bool exp2 = dArr11 != dArr12;
    cout << "dArr11(2, 1) != dArr12(7, 1)?: ";
    cout << exp2 << endl;

    bool exp3 = dArr11 > dArr12;
    cout << "dArr11(2, 1) > dArr12(7, 1)?: ";
    cout << exp3 << endl;

    bool exp4 = dArr11 >= dArr12;
    cout << "dArr11(2, 1) >= dArr12(7, 1)?: ";
    cout << exp4 << endl;

    bool exp5 = dArr11 < dArr12;
    cout << "dArr11(2, 1) < dArr12(7, 1)?: ";
    cout << exp5 << endl;

    bool exp6 = dArr11 <= dArr12;
    cout << "dArr11(2, 1) <= dArr12(7, 1)?: ";
    cout << exp6 << endl;
    cout << endl;

    // Доступ к элементу
    DynamicIntArray dArr121 = DynamicIntArray(7, 2);
    int elem = dArr121[0];
    cout << "Нулевой элемент массива: ";
    cout << elem << endl;

    // Проверка изменения
    DynamicIntArray dArr122 = DynamicIntArray(4, 2);
    dArr122[0] = 1;
    dArr122[1] = 2;
    dArr122[2] = 3;
    dArr122[3] = 4;
    cout << dArr122;
    cout << "\n" << endl;

    // Перемещающее присваивание
    cout << "Перемещающее присваивание: " << endl;
    DynamicIntArray dArr16 = DynamicIntArray(5, 8);
    DynamicIntArray dArr19 = DynamicIntArray(5, 7);
    DynamicIntArray dArr17 = DynamicIntArray(dArr16);
    dArr17 = DynamicIntArray(dArr19);
    cout << dArr17;
    cout << "\n" << endl;

    // Конструктор перемещения
    cout << "Работа конструктора перемещения: " << endl;
    DynamicIntArray dArr14 = DynamicIntArray(7, 2);
    DynamicIntArray dArr15 = DynamicIntArray(7, 3);
    DynamicIntArray dArr18 = DynamicIntArray(dArr14);
    DynamicIntArray dArr20 = DynamicIntArray(dArr14 + dArr15);

    cout << dArr20 << endl;
    cout << endl;

    // Ввод/Вывод массивов
    DynamicIntArray dArr10 = DynamicIntArray(5);
    cout << "Введите элементы массива: " << endl;
    cin >> dArr10;
    cout << dArr10;
    cout << "\n" << endl;
}