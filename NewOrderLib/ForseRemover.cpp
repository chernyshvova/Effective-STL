#include "stdafx.h"
#include "ForseRemover.h"

force::ForceRemover::ForceRemover() {}
force::ForceRemover::ForceRemover(std::string::iterator cursor) :
    std::string::iterator(cursor)
    , m_skipedText("force")
{}

bool force::ForceRemover::operator==(const std::string::iterator& it)
{
    
    return *std::string::iterator::_Ptr == *it;
}

bool force::ForceRemover::operator!=(const ForceRemover& it)
{
    return !(*this == it);
}

char force::ForceRemover::operator*()
{
    return *std::string::iterator::_Ptr;
}



force::ForceRemover& force::ForceRemover::operator++()
{
    ++std::string::iterator::_Ptr;
    for (char skip : m_skipedText)
    {
        if (skip == *std::string::iterator::_Ptr)
        {
            ++std::string::iterator::_Ptr;
        }
    }

    return *this;
}

force::ForceRemover& force::ForceRemover::operator++(int)
{
    ++(*this);
    return *this;
}

force::ForceRemover & force::ForceRemover::operator+=(int count)
{

    std::string::iterator::_Ptr += count;
    return *this;
}