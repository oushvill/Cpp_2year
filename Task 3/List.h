#pragma once
#include <iostream>

struct Node
{
    Node* prev;
    Node* next;
    int data;
};

class AIterator
{
public:
    // начать работу
    virtual void start() = 0;
    // получить очередной элемент
    virtual Node* get() = 0;
    // сдвинуть итератор на следующий элемент
    virtual void next() = 0;
    // проверка, все ли проитерировано
    [[nodiscard]] virtual bool finish() const = 0;
};

class AList {
protected:
    int count;
    Node* buffer;

public:
    [[nodiscard]] virtual Node* getBuffer() const = 0;

    // вставить элемент в позицию, отмеченную итератором
    virtual void addElem(AIterator* index, int v) = 0;
    // удалить элемент, отмеченный итератором
    virtual void deleteElem(AIterator* index) = 0;
    // найти первое вхождение элемента в список, результат – итератор на найденный элемент
    [[nodiscard]] virtual AIterator* searchFirstEntry(int n) const = 0;
    // сделать список пустым
    virtual void makeEmpty() = 0;
    // проверка на пустоту
    [[nodiscard]] virtual bool checkEmpty() const = 0;
    // количество элементов в списке
    [[nodiscard]] virtual int getCount() const = 0;
    // получить итератор на первый элемент списка
    [[nodiscard]] virtual const AIterator* getFirstI() const = 0;
};

/**КЛАСС-РЕАЛИЗАЦИЯ СПИСКА**/
class List : public AList
{
private:
    int count;
    Node* buffer;

public:
/**КЛАСС-РЕАЛИЗАЦИЯ ИТЕРАТОРА СПИСКА**/
    class Iterator : public AIterator
    {
    private:
        int index;
        int count;
        Node* buf;
        Node* p;

    public:
        explicit Iterator(const List& list);
        // начать работу
        void start() override;
        // получить очередной элемент
        Node* get() override;
        // сдвинуть итератор на следующий элемент
        void next() override;
        // проверка, все ли проитерировано
        [[nodiscard]] bool finish() const override;
    };

    List();
    List(const List& list);
    List(List&& obj) noexcept;
    ~List();

    [[nodiscard]] Node* getBuffer() const override;

    // вставить элемент в позицию, отмеченную итератором
    void addElem(AIterator* index, int v) override;
    // удалить элемент, отмеченный итератором
    void deleteElem(AIterator* index) override;
    // найти первое вхождение элемента в список, результат – итератор на найденный элемент
    [[nodiscard]] AIterator* searchFirstEntry(int n) const override;
    // сделать список пустым
    void makeEmpty() override;
    // проверка на пустоту
    [[nodiscard]] bool checkEmpty() const override;
    // количество элементов в списке
    [[nodiscard]] int getCount() const override;
    // получить итератор на первый элемент списка
    [[nodiscard]] AIterator* getFirstI() const override;

    List& operator=(const List& obj);
    List operator=(List&& obj) noexcept;
};