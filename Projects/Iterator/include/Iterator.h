#pragma once

#include <stdexcept>
#include "List.h"

template <typename Item>
class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual Item& CurrentItem() const = 0;
    virtual bool IsDone() const = 0;

protected:
    Iterator();

};

template <typename Item>
class ListIterator : public Iterator<Item>
{
public:
    ListIterator(List<Item>* list);

    virtual void First() override;
    virtual void Next() override;
    virtual Item& CurrentItem() const override;
    virtual bool IsDone() const override;

private:
    const List<Item> *_list;
    uint64_t _current;

};

template <typename Item>
class ReverseListIterator : public Iterator<Item>
{
public:
    ReverseListIterator(List<Item>* list);

    virtual void First() override;
    virtual void Next() override;
    virtual Item& CurrentItem() const override;
    virtual bool IsDone() const override;

private:
    const List<Item>* _list;
    uint64_t _current;

};

template <typename Item>
ListIterator<Item>::ListIterator(List<Item>* list)
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
Item& ListIterator<Item>::CurrentItem() const {

    if (IsDone()) {
        throw std::runtime_error("Iterator out of bounds");
    }

    _list->Get(_current);
}

template <typename Item>
bool ListIterator<Item>::IsDone() const {
    return _current >= _list->Count();
}

template <typename Item>
ReverseListIterator<Item>::ReverseListIterator(List<Item>* list)
    :_list(list), _current(_list->Count() - 1)
{}

template <typename Item>
void ReverseListIterator<Item>::First() {
    _current = _list->Count() - 1;
}

template <typename Item>
void ReverseListIterator<Item>::Next() {
    --_current;
}

template <typename Item>
Item& ReverseListIterator<Item>::CurrentItem() const {

    if (IsDone()) {
        throw std::runtime_error("Iterator out of bounds");
    }

    _list->Get(_current);
}

template <typename Item>
bool ReverseListIterator<Item>::IsDone() const {
    return _current < 0;
}