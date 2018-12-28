#include "stdafx.h"
#include "ForseRemover.h"

force::ForceRemover::ForceRemover() {}
force::ForceRemover::ForceRemover(std::string::iterator c) :
    cursor_(c)
{}

bool force::ForceRemover::operator==(const std::string::iterator& it)
{
    return cursor_ == it;
}

bool force::ForceRemover::operator!=(const ForceRemover& it)
{
    return !(cursor_ == it.cursor_);
}

force::ForceRemover& force::ForceRemover::operator++()
{
    ++cursor_;
    return *this;
}

force::ForceRemover force::ForceRemover::operator++(int)
{
    force::ForceRemover it = *this;
    ++(*this);
    return it;
}

force::ForceRemover& force::ForceRemover::operator--()
{
    --cursor_;
    return *this;
}

force::ForceRemover force::ForceRemover::operator--(int)
{
    ForceRemover it = *this;
    --(*this);
    return it;
}