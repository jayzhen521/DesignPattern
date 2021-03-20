#pragma once

#include "Iterator.h"

template <typename Item>
class SkipList;

template <typename Item>
class SkipListIterator : public Iterator<Item>
{
public:
    SkipListIterator(const SkipList<Item>* aSkipList);

    virtual void First() override;
    virtual void Next() override;
    virtual Item CurrentItem() const override;
    virtual bool IsDone() const override;

private:
    const SkipList<Item>* _list;
    uint64_t _current;

};

template <typename Item>
SkipListIterator<Item>::SkipListIterator(const SkipList<Item>* aSkipList)
    :_list(aSkipList)
{}

template <typename Item>
void SkipListIterator<Item>::First() {
    _current = 0;
}

template <typename Item>
void SkipListIterator<Item>::Next() {
    _current += 2;
}

template <typename Item>
Item SkipListIterator<Item>::CurrentItem() const {
    if (IsDone()) {
        throw std::runtime_error(ITERATOR_OUT_OF_BOUNDS);
    }

    return _list->Get(_current);
}

template <typename Item>
bool SkipListIterator<Item>::IsDone() const {
    return _current >= _list->Count();
}