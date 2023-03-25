using namespace std;

#include"Container.h"
//#include"Box.cpp"


int main() {
    system("chcp 65001");
    //КОРОБКИ
    Box box0(0, 0, 0, 0.0, 0);
    Box box1(1, 4, 5, 2.0, 200);
    Box box2(2, 5, 4, 3.0, 100);
    Box box3(3, 6, 9, 4.0, 300);
    Box box4(4, 7, 10, 5.0, 400);
 //   Box boxes[] = {box0, box1, box2, box3, box4};
    Box boxes[] = {box4, box3, box2, box1, box0};
    cout << "____________________________________________" << "\n \t\t КОРОБКИ \n"
         << "____________________________________________\n";

    cout << "\nКоробка #1 = " << box1 << endl;
    //2. Суммарная стоимость всех коробок
    cout << "Стоимость всех коробок: " << box1.sumValue(boxes, 5) << "\n";

    //3. Сумма длины, ширины и высоты всех коробок <= anySum
    int anySum;
    cout << "\nВведите anySum=";
    cin >> anySum;
    cout << " Сумма длины, ширины и высоты всех коробок <= anySum: " << box1.noMaxSum(boxes, 5, anySum) << endl;

    //4. Максимальный вес коробок при объеме < maxV
    int maxV;
    cout << "\nВведите maxV=";
    cin >> maxV;
    cout << "Максимальный вес коробок при объеме < maxV: " << box1.maxWeight(boxes, 5, maxV) << endl;

    cout << "\nСоздание коробки в коробке: " << box1.boxInBox(boxes, 4)<< "\n"; //5. Одна коробка может содержать другую

    //КОНТЕЙНЕР
    cout << "____________________________________________" << "\n \t\t КОНТЕЙНЕР \n"
         << "____________________________________________ \n";
    vector <Box> arrBox = {box1, box2, box3, box4};
    Container cont(arrBox, 3, 4, 5, 15);
    Box box5(1, 2, 3, 1, 500);

    //11.Добавление коробки в контейнере
    try {
        cont.appendBoxInContainer(1, box5);
    }
    catch (MyException &ex) {
        cout << ex.what() << endl;
    }
    cont.deleteBoxInContainer(2);       //11.Удаление коробки в контейнере
    cout << "\nКоличество коробок: " << cont.countBoxesCont() << endl; //11. -Количество коробок в контейнере
    cout << "Вес контейнера: " << cont.sumWeightCont() << endl; //11. -Вес контейнера
    cout << "Стоимость контейнера: " << cont.sumValueCont() << endl;   //11. -Стоимость контейнера
    int I;
    cout << "Введите индекс = ";
    cin >> I;
    Box xI = cont.returnBoxByIndex(I);                         //11. -Получение по индексу
    cout << "Это " << xI << " по индексу " << I << endl;
    cout << "\nВесь контейнер: " << cont << endl;

}
