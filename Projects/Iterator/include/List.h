#pragma once

#include <vector>
#include <stdexcept>

#include "Config.h"

template <typename Item>
class List {

public:
    List(uint64_t size = DEFAULT_LIST_CAPACITY);
    virtual ~List();

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