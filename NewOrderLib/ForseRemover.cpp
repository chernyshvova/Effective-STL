#include "stdafx.h"
#include "ForseRemover.h"

namespace {
    void filterText(force::ForceRemover& it, const std::string& text, bool backwards = false)
    {
        bool exit = true;
        for (char sym : text)
        {
            if (*it._Ptr == sym)
            {
                it._Ptr++;
                exit = false;
            }  
        }
        if (!exit)
        {
            filterText(it, text);
        }
    }
}


force::ForceRemover::ForceRemover() {}
force::ForceRemover::ForceRemover(ForceIterator& cursor) :
    ForceIterator(cursor)
    , m_skipedText("force")
{}

bool force::ForceRemover::operator==(ForceIterator& it)const
{
    return ForceIterator::_Ptr == it._Ptr;
}

bool force::ForceRemover::operator==(ForceRemover & it) const
{
    return ForceIterator::_Ptr == it._Ptr;
}

bool force::ForceRemover::operator==(const char rval) const
{
    return *ForceIterator::_Ptr == rval;
}

bool force::ForceRemover::operator!=(const ForceRemover& it)
{
    return !(*this->_Ptr == *it._Ptr);
}

char& force::ForceRemover::operator*()
{ 
    return  const_cast<char&>(*ForceIterator::_Ptr);;
}

force::ForceRemover & force::ForceRemover::operator=(ForceIterator& rval)
{
    ForceIterator::_Ptr = rval._Ptr;
    return *this;
}

force::ForceRemover& force::ForceRemover::operator++()
{
    ForceIterator::_Ptr++;
    filterText(*this, m_skipedText);
    return *this;
}

force::ForceRemover & force::ForceRemover::operator+(const ForceRemover & rlvar)
{
    return *this;
}

force::ForceRemover& force::ForceRemover::operator++(int)
{
    ++(ForceIterator::_Ptr);
    return *this;
}

force::ForceRemover & force::ForceRemover::operator+=(int count)
{
    ForceIterator::_Ptr += count;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator--(int)
{
    ForceIterator::_Ptr--;
    return *this;
}

force::ForceRemover & force::ForceRemover::operator-(const ForceIterator & other)
{
    return *this;
}

bool force::ForceRemover::operator<(const ForceIterator & other)const
{
    return ForceIterator::_Ptr < other._Ptr;
}
