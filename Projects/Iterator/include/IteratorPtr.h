#pragma once

template <typename Item>
class Iterator;

template <typename Item>
class IteratorPtr
{
public:
    IteratorPtr(Iterator<Item>* iter);
    ~IteratorPtr();

    Iterator<Item>* operator->();
    Iterator<Item>& operator*();

    IteratorPtr(const IteratorPtr&) = delete;
    IteratorPtr& operator=(const IteratorPtr&) = delete;

private:
    Iterator<Item>* _i;

};

template<typename Item>
inline IteratorPtr<Item>::IteratorPtr(Iterator<Item>* iter)
    :_i(iter)
{
}

template<typename Item>
inline IteratorPtr<Item>::~IteratorPtr()
{
    delete _i;
}

template<typename Item>
inline Iterator<Item>* IteratorPtr<Item>::operator->()
{
    return _i;
}

template<typename Item>
inline Iterator<Item>& IteratorPtr<Item>::operator*()
{
    // TODO: insert return statement here
    return *_i;
}

