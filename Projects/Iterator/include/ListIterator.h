#pragma once

#include "Iterator.h"

template <typename Item>
class List;

template <typename Item>
class ListIterator : public Iterator<Item>
{
public:
    ListIterator(const List<Item>* list);

    virtual void First() override;
    virtual void Next() override;
    virtual Item CurrentItem() const override;
    virtual bool IsDone() const override;

private:
    const List<Item>* _list;
    uint64_t _current;

};

template <typename Item>
ListIterator<Item>::ListIterator(const List<Item>* list)
    :_list(list), _current(0)
{}

template <typename Item>
void ListIterator<Item>::First() {
    _current = 0;
}

template <typename Item>
void ListIterator<Item>::Next() {
    ++_current;
}

template <typename Item>
Item ListIterator<Item>::CurrentItem() const {

    if (IsDone()) {
        throw std::runtime_error(ITERATOR_OUT_OF_BOUNDS);
    }

    return _list->Get(_current);

}

template <typename Item>
bool ListIterator<Item>::IsDone() const {
    return _current >= _list->Count();
}