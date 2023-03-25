#include "RingBuffer.h"
#include <iostream>
using namespace std;

int main()
{
   system("chcp 65001");

    size_t size = 5;
    RingBuffer<double> buffer(size);

    buffer.addInEnd(10);
    buffer.addInEnd(11);
    buffer.addInEnd(12);
    buffer.addInEnd(14);
    buffer.addInEnd(15);

    Iterator iter(buffer);

    iter.start();

    cout << "Очередь: { " ;
    for (int i = 0; i < buffer.getSizeBuffer(); i++)
    {
        cout << iter.getValue() << " ";
        iter.next();
    }
    cout << "}" << endl;
    cout << "\nТест на исключение при переполнении: ";
    // Тест на исключение при переполнении
    try {
        buffer.addInEnd(16);
    }
    catch (MyException &ex) {
        cout << ex.what() << endl;
    }

    double getElem = buffer.getInStart();
    cout << "\nИзъятый элемент из начала очереди: ";
    cout << getElem << endl;
    size_t buffSize = buffer.getSizeBuffer();
    cout << "Новый размер очереди: ";
    cout << buffSize << endl;

    double checkFirst = buffer.checkInStart();
    cout << "\nПросмотр элемента в начале очереди: ";
    cout << checkFirst << endl;
    int last;
    cout << "Добавим в конец очереди число: "; cin>>last;
    buffer.addInEnd(last);
    size_t buffSize2 = buffer.getSizeBuffer();
    cout << "Новый Размер очереди: ";
    cout << buffSize2 << endl;
    cout << endl;

    buffer.clearBuffer();
    bool emptyCheck = buffer.isEmpty();
    cout << "\nПроверка очереди на пустоту: ";
    cout << emptyCheck << endl;

    // Тест на исключение при отсутствии элементов
    cout << "\nТест на исключение при отсутствии элементов:" << endl;
    try {
        double getElemEx = buffer.getInStart();
    }
    catch (MyException &ex) {
        cout << ex.what() << endl;
    }

    bool сheck = iter.finish();
    cout << "\nПроверка, все ли проитерировано: ";
    cout << сheck << endl;
    cout << endl;
}