#include "stdafx.h"
#include "ForseRemover.h"

force::ForceRemover::ForceRemover() {}
force::ForceRemover::ForceRemover(ForceIterator cursor) :
    ForceIterator(cursor)
    , m_skipedText("force")
{}

bool force::ForceRemover::operator==(ForceIterator& it)const
{
    
    return ForceIterator::_Ptr == it._Ptr;
}

bool force::ForceRemover::operator!=(const ForceRemover& it)
{
    return !(*this->_Ptr == *it._Ptr);
}

char force::ForceRemover::operator*()
{
    return *ForceIterator::_Ptr;
}

force::ForceRemover& force::ForceRemover::operator++()
{
    ++ForceIterator::_Ptr;
    for (char skip : m_skipedText)
    {
        if (skip == *ForceIterator::_Ptr)
        {
            ++ForceIterator::_Ptr;
        }
    }

    return *this;
}

force::ForceRemover & force::ForceRemover::operator+(const ForceRemover & rlvar)
{
    int a = 0;
    a;
    return *this;
}

force::ForceRemover& force::ForceRemover::operator++(int)
{
    ++(*this);
    return *this;
}

force::ForceRemover & force::ForceRemover::operator+=(int count)
{
    ForceIterator::_Ptr += count;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator--(int)
{
    int a = 0;
    a;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator-=(int)
{
    int a = 0;
    a;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator[](int)
{
    int a = 0;
    a;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator-(const ForceIterator & other)
{
    int a = 0;
    a;
    return *this;
}

bool force::ForceRemover::operator>(const ForceIterator & other) const
{
    return false;
}

bool force::ForceRemover::operator<=(const ForceIterator & other) const
{
    return false;
}

bool force::ForceRemover::operator>=(const _Myiter & _Right) const
{
    return false;
}

bool force::ForceRemover::operator<(const ForceIterator & other)const
{
    return ForceIterator::_Ptr < other._Ptr;
}
