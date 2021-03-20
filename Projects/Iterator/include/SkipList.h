#pragma once

#include <list>
#include "List.h"

template <typename Item>
class SkipList : public List<Item>
{
public:
    SkipList(uint64_t size = DEFAULT_LIST_CAPACITY);

    //not nessary for testing
    //virtual uint64_t Count() const;
    //virtual Item Get(uint64_t index) const;
    
private:
    

};

template <typename Item>
SkipList<Item>::SkipList(uint64_t size)
    :List<Item>(size)
{}