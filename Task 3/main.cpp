#include "List.h"

using namespace std;

int main() {
    system("chcp 65001");

    List list;
    AIterator *ITR = new List::Iterator(list);
    ITR->start();
    list.addElem(ITR, 2);
    list.addElem(ITR, 4);
    ITR->start();
    ITR->next();
    cout << "Список элементов: [";
    cout << ITR->get()->data << ",";
    ITR->next();
    cout << ITR->get()->data << "]" << endl;

    cout << "\nПроверка на пустоту: " << list.checkEmpty();
    if (list.checkEmpty() == 0) {
        cout << "\nСписок полон, делаем список пустым!";
        list.makeEmpty();
        cout << "\nПроверка на пустоту: " << list.checkEmpty() << endl;
    } else {
        cout << "\nСписок пустой, действия не нужны! \n";
    }
    ITR->start();


    cout << "\nДобавим элементов и получим новый список: [";
    list.addElem(ITR, 10);
    ITR->next();
    cout << ITR->get()->data << ",";
    list.addElem(ITR, 20);
    ITR->next();
    cout << ITR->get()->data << ",";
    list.addElem(ITR, 30);
    ITR->next();
    cout << ITR->get()->data << "]" << endl;

    /*
    list.addElem(ITR, 1);
    list.addElem(ITR, 2);
    list.addElem(ITR, 3);

    cout << "\nДобавим элементов и получим новый список: [";
    ITR->next();
    cout << ITR->get()->data << ",";
    ITR->next();
    cout << ITR->get()->data << ",";
    ITR->next();
    cout << ITR->get()->data << "]" << endl;
*/
    cout << "Поиск первого вхождения: ";
    cout << list.searchFirstEntry(11)->get()->data << endl;

    cout << "Итератор на первый элемент списка: ";
    cout << list.getFirstI()->get()->data << endl;

    ITR->start();
    ITR->next();
    list.deleteElem(ITR);

    cout << "Итератор на второй элемент списка, после удаления первого: ";
    cout << list.getFirstI()->get()->data << endl;

    cout << "\nСписок №1" << endl;
    ITR = new List::Iterator(list);
    ITR->start();
    while (!ITR->finish()) {
        ITR->next();
        cout << ITR->get()->data << endl;
    }

    List list2 = list;
    AIterator *i = new List::Iterator(list2);
    i->start();
    cout << "Список №2" << endl;
    while (!i->finish()) {
        i->next();
        cout << i->get()->data << endl;
    }
}