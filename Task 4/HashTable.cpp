#include "HashTable.h"

template<typename T>
HashTable<T>::HashTable() : hashT(2)
{
    for (size_t i = 0; i < hashT.size(); i++)
        hashT[i] = nullptr;
}

//Деконструктор
template<typename T>
HashTable<T>::~HashTable()
{
    clearTable();
}

template<typename T>
int HashTable<T>::hash(const std::string& key) const
{
    int sum = 0;
    for (int i: key) sum += i;
    return sum % hashT.size();
}

//добавить элемент
template<typename T>
void HashTable<T>::Add(const std::string& key, const T& value)
{
    int index = hash(key);
    auto* item = new Item<T>(key, value);
    if (!hashT[index])
    {
        hashT[index] = new std::list<Item<T>*>;
        hashT[index] -> push_back(item);
    }
    else
    {
        for (Item<T>* i: *hashT[index])
        {
            if (i -> key == key) return;
        }
        hashT[index] -> push_back(item);
    }
    checkT.push_back(item);
}

//удалить элемент
template<typename T>
void HashTable<T>::Delete(const std::string& key)
{
    int index = hash(key);
    if (!hashT[index])
        return;

    Item<T>* finded_item = Find(key);

    if (!finded_item)
        return;

    typename std::vector<Item<T>*>::iterator it = std::find(checkT.begin(), checkT.end(), finded_item);
    if (it == checkT.end())
        throw std::exception();

    checkT.erase(it);
    hashT[index] -> remove(finded_item);
}

//найти элемент
template<typename T>
Item<T>* HashTable<T>::Find(std::string key) const
{
    int index = hash(key);

    if (!hashT[index])
        return nullptr;

    auto it = hashT[index]->begin();

    for(Item<T>* item: *hashT[index])
    {
        if (item -> key == key)
            return item;
    }
    return nullptr;
}

//сделать таблицу пустой
template<typename T>
void HashTable<T>::clearTable()
{
    for (int i = 0; i < hashT.size(); i++)
    {
        hashT[i] = nullptr;
    }
    checkT.clear();
}

//проверка таблицы на пустоту
template<typename T>
bool HashTable<T>::isEmpty() const
{
    for (int i = 0; i < hashT.size(); i++) {
        if (hashT[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template<typename T>
HashTable<T>::Iterator::Iterator(const HashTable<T>& hashTable) : hashTable(hashTable) {}

template<typename T>
void HashTable<T>::Iterator::start()
{
    current = hashTable.checkT.begin();
}

template<typename T>
void HashTable<T>::Iterator::next()
{
    current++;
}

template<typename T>
Item<T>* HashTable<T>::Iterator::getValue() const
{
    return *current;
}

template<typename T>
bool HashTable<T>::Iterator::finish() const
{
    return current == hashTable.checkT.end();
}
