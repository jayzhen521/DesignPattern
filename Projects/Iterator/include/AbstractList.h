#pragma once

template <typename Item>
class Iterator;

template <class Item>
class AbstractList
{
public:
    virtual Iterator<Item>* CreateIterator() const = 0;
    virtual Iterator<Item>* CreateReverseIterator() const = 0;

};
