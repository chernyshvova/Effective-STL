#include "stdafx.h"
#include "ForseRemover.h"

force::ForceRemover::ForceRemover() {}
force::ForceRemover::ForceRemover(std::string::iterator cursor, const std::string& skipedText) :
    m_cursor(cursor)
    , m_skipedText(skipedText)
{}

bool force::ForceRemover::operator==(const std::string::iterator& it)
{
    return m_cursor == it;
}

bool force::ForceRemover::operator!=(const ForceRemover& it)
{
    return !(m_cursor == it.m_cursor);
}

char force::ForceRemover::operator*()
{
    return *m_cursor;
}



force::ForceRemover& force::ForceRemover::operator++()
{
    ++m_cursor;
    for (char skip : m_skipedText)
    {
        if (skip == *m_cursor)
        {
            ++m_cursor;
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

    m_cursor += count;
    return *this;
}

//force::ForceRemover& force::ForceRemover::operator--()
//{
//    --m_cursor;
//    return *this;
//}

//wrong ?
//force::ForceRemover force::ForceRemover::operator--(int)
//{
//    ForceRemover it = *this;
//    --(*this);
//    return it;
//}

