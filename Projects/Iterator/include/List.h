#pragma once

#include "Config.h"

template <typename Item>
class List {

public:
    List(uint64_t size = DEFAULT_LIST_CAPACITY);

    uint64_t Count() const;
    Item& Get(uint64_t index) const;

};

