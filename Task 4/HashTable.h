#pragma once
#include <iostream>
#include <vector>
#include <list>

template<typename T>
struct Item
{
    const std::string key;
    T value;
    Item(std::string  n, const T& a) : key(std::move(n)), value(a) {}
};

template<typename T>
class HashTable {

//Хэш-таблица на основе вектора списка структур и вектора структур

private:
    std::vector<std::list<Item<T>*>*> hashT;
    std::vector<Item<T>*> checkT;
    [[nodiscard]] int hash(const std::string& key) const;

public:
    HashTable();
    explicit HashTable(const int capacity);
    ~HashTable();

    //добавить элемент
    void Add(const std::string& key, const T& value);
    //удалить элемент
    void Delete(const std::string& key);
    //найти элемент
    [[nodiscard]] Item<T>* Find(std::string key) const;
    //сделать таблицу пустой
    void clearTable();
    //проверка таблицы на пустоту
    [[nodiscard]] bool isEmpty() const;

    class Iterator
    {
    private:
        const HashTable<T>& hashTable;
        typename std::vector<Item<T>*>::const_iterator current;

    public:
        explicit Iterator(const HashTable<T>& hashTable);
        void start();
        void next();
        [[nodiscard]] Item<T>* getValue() const;
        [[nodiscard]] bool finish() const;
    };
};

template class HashTable<int>;
template class HashTable<double>;