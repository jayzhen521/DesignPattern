#pragma once

#include "AbstractList.h"
#include "List.h"

#include "SkipListIterator.h"

template <typename Item>
class SkipList : public List<Item>
{
public:
    SkipList(uint64_t size = DEFAULT_LIST_CAPACITY);
    virtual ~SkipList();

    virtual Iterator<Item>* CreateIterator() const override;
    virtual Iterator<Item>* CreateReverseIterator() const override;

    //not nessary for testing
    //virtual uint64_t Count() const;
    //virtual Item Get(uint64_t index) const;
    
private:
    

};

template <typename Item>
SkipList<Item>::SkipList(uint64_t size)
    :List<Item>(size)
{}

template <typename Item>
SkipList<Item>::~SkipList()
{}

template<typename Item>
inline Iterator<Item>* SkipList<Item>::CreateIterator() const
{
    return new SkipListIterator<Item>(this);
}

template<typename Item>
inline Iterator<Item>* SkipList<Item>::CreateReverseIterator() const
{
    //
    return NULL;
}

