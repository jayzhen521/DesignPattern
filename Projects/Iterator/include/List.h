#pragma once

#include <vector>
#include <stdexcept>

#include "Config.h"
#include "AbstractList.h"

#include "ListIterator.h"
#include "ReverseListIterator.h"

template <typename Item>
class List : AbstractList<Item>{

public:
    List(uint64_t size = DEFAULT_LIST_CAPACITY);
    virtual ~List();

    virtual Iterator<Item>* CreateIterator() const override;
    virtual Iterator<Item>* CreateReverseIterator() const override;

    uint64_t Count() const;
    Item Get(uint64_t index) const;

    void add(Item item);

private:
    std::vector<Item> _items;

};

template <typename Item>
List<Item>::List(uint64_t size)
    :_items(std::vector<Item>(size))
{}

template <typename Item>
uint64_t List<Item>::Count() const{
    return _items.size();
}

template <typename Item>
Item List<Item>::Get(uint64_t index) const {
    if (index >= _items.size()) {
        throw std::runtime_error("Index out of bounds");
    }

    return _items[index];
}

template <typename Item>
void List<Item>::add(Item item)
{
    _items.push_back(item);
}

template <typename Item>
List<Item>::~List() {
    
}

template<typename Item>
inline Iterator<Item>* List<Item>::CreateIterator() const
{
    return new ListIterator<Item>(this);
}

template<typename Item>
inline Iterator<Item>* List<Item>::CreateReverseIterator() const
{
    return new ReverseListIterator<Item>(this);
}
