#pragma once

#include "Iterator.h"

template <typename Item>
class List;

template <typename Item>
class ReverseListIterator : public Iterator<Item>
{
public:
    ReverseListIterator(const List<Item>* list);

    virtual void First() override;
    virtual void Next() override;
    virtual Item CurrentItem() const override;
    virtual bool IsDone() const override;

private:
    const List<Item>* _list;
    uint64_t _current;

};

template <typename Item>
ReverseListIterator<Item>::ReverseListIterator(const List<Item>* list)
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
Item ReverseListIterator<Item>::CurrentItem() const {

    if (IsDone()) {
        throw std::runtime_error(ITERATOR_OUT_OF_BOUNDS);
    }

    return _list->Get(_current);
}

template <typename Item>
bool ReverseListIterator<Item>::IsDone() const {
    return _current == std::numeric_limits<uint64_t>::max();
}
