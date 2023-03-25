#include "Box.h"

using namespace std;


Box::Box(int length, int width, int height, double weight, int value) {
    this->length = length;
    this->width = width;
    this->height = height;
    this->weight = weight;
    this->value = value;
}

int Box::getLength() {
    return length;
}

int Box::getWidth() {
    return width;
}

int Box::getHeight() {
    return height;
}

double Box::getWeight() {
    return weight;
}

int Box::getValue() {
    return value;
}

void Box::setLenght(int lenght) {
    this->length = lenght;
}

void Box::setWidth(int width) {
    this->width = width;
}

void Box::setHeight(int height) {
    this->height = height;
}

void Box::setWeight(double weight) {
    this->weight = weight;
}

void Box::setValue(int value) {
    this->value = value;
}

//2. Суммарная стоимость всех коробок
int Box::sumValue(Box boxes[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].value;
    }
    return sum;
}

//3. Сумма длины, ширины и высоты всех коробок <= anySum
bool Box::noMaxSum(Box boxes[], int size, int anySum) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].length;
        sum += boxes[i].width;
        sum += boxes[i].height;
    }
    if (sum <= anySum) return true;
    else return false;
}

//4. Максимальный вес коробок при объеме < maxV
double Box::maxWeight(Box boxes[], int size, int maxV) {
    double maxWeight = 0;
    for (int j = 0; j < size; j++) {
        if ((boxes[j].getHeight() * boxes[j].getLength() * boxes[j].getWidth() <= maxV) &&
            (maxWeight <= boxes[j].getWeight())) {
            maxWeight = boxes[j].weight;
        }
    }
    return maxWeight;
}

//5. Одна коробка может содержать другую

bool Box::boxInBox(Box boxes[], int size) {
    int packed = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((boxes[i].getHeight() < boxes[j].getHeight()
                 && boxes[i].getWidth() < boxes[j].getWidth()
                 && boxes[i].getLength() < boxes[j].getLength()))
                packed++;
        }
    }
    if (size + 5 == packed) return true;
    return false;
}

//6. Оператор сравнения
bool operator==(Box &boxes1, Box &boxes2) {
    return ((boxes1.getHeight() == boxes2.getHeight()) && (boxes1.getLength() == boxes2.getLength()) &&
            (boxes1.getWeight() == boxes2.getWeight()) && (boxes1.getWidth() == boxes2.getWidth()) &&
            (boxes1.getValue() == boxes2.getValue()));
}

//7. Операторы ввода/вывода
ostream &operator<<(ostream &out, Box &box) {
    out << "Коробка(" << box.getLength() << ", " << box.getWidth() << ", " << box.getHeight() << ", "
        << box.getWeight()
        << ", " << box.getValue() << ")";
    return out;
}

istream &operator>>(istream &in, Box &box) {
    in >> box.height;
    in >> box.width;
    in >> box.length;
    in >> box.weight;
    in >> box.value;
    return in;
}

