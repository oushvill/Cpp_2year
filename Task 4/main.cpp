#include "HashTable.h"

using namespace std;

int main() {

    system("chcp 65001");

    HashTable<int> table;
    table.Add("aKey", 1);
    table.Add("bKey", 2);
    table.Add("cKey", 3);
    table.Add("dKey", 4);
    table.Add("eKey", 5);
    table.Add("fKey", 6);
    table.Add("gKey", 7);
    table.Add("hKey", 8);
    table.Add("iKey", 9);

    HashTable<int>::Iterator it(table);
    it.start();
    cout << "Хэш-таблица: ";
    while (!it.finish()) {
        cout << it.getValue()->value << " ";
        it.next();
    }
    cout << endl;
    string a = "aKey";
    cout << "\nПоиск элемента по ключу " << a << ": ";
    Item<int> *item = table.Find(a);
    cout << item->value << endl;

    cout << "Удаление последних двух элеменетов: " << table.Find("hKey")->value << " и "
         << table.Find("iKey")->value << endl;

    table.Delete("iKey");
    table.Delete("hKey");

    cout << "\nНовая Хэш-таблица: ";
    HashTable<int>::Iterator itNew(table);
    itNew.start();
    while (!itNew.finish()) {
        cout << itNew.getValue()->value << " ";
        itNew.next();
    }

    table.clearTable();
    itNew.start();
    while (!itNew.finish()) {
        cout << itNew.getValue()->value << " ";
        itNew.next();
    }

    cout << "\nОпустошение таблицы и проверка на пустоту: " << table.isEmpty()<<endl;
}