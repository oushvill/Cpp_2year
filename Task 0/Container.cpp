#include"Container.h"

Container::Container(vector<Box> array, int length, int width, int height, int maxWeight) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getWeight();
    }
    if (sum > maxWeight) {
        throw MyException("Ошибка: Коробки на входе в контейнер тяжелее условий ");

    }
    this->array = array;
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight = maxWeight;
}

//11.Добавление коробки в контейнере
void Container::appendBoxInContainer(int i, Box box) {
    double sum = 0;
    for (auto & j : array) sum += j.getWeight();
    auto iter1 = array.cbegin();
    if ((sum + box.getWeight()) > maxWeight) {
        throw MyException("Ошибка: Добавленная коробка переполняет контейнер");
    }
    array.insert(iter1 + i, box);
}

//11.Удаление коробки в контейнере
void Container::deleteBoxInContainer(int i) {
    auto iter = array.cbegin();
    array.erase(iter + i - 1);
}

//11. -Количество коробок в контейнере
int Container::countBoxesCont() {
    return array.size();
}

//11. -Вес контейнера
double Container::sumWeightCont() {
    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getWeight();
    }
    return sum;
}

//11. -Стоимость контейнера
int Container::sumValueCont() {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getValue();
    }
    return sum;
}

//11. -Получение по индексу
Box Container::returnBoxByIndex(int i) {
    return array[i];
}

// 12. Операторы ввода/вывода
ostream& operator <<(ostream& out, Container& container) {
    out << "Длина: " << container.length << ", Ширина: " << container.width << ", Высота: " << container.height << ", Max вес: " << container.maxWeight << "\n|| ";
    for (int i = 0; i < container.array.size(); i++) {
        out << container.array[i] << ", ";
    }
    out << " ||";
    return out;
}
istream& operator >> (istream& in, Container& container) {
    in >> container.height;
    in >> container.width;
    in >> container.length;
    in >> container.maxWeight;
    for (int i = 0; i < container.array.size(); i++) {
        in >> container.array[i];
    }
    return in;
}

//13. Оператор [] позволяет получить/изменить коробку по индексу
Box& Container::operator[](const int index) {
    return array[index];
}