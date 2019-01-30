#include "stdafx.h"
#include "ForceIgnorer.h"
#include "ForceUtils.h"

force::ForceIgnorer::ForceIgnorer()
{
}

force::ForceIgnorer::ForceIgnorer(ForceIterator& it) :
    ForceIterator(it)
    , m_skipedText("force")
{
}

force::ForceIgnorer & force::ForceIgnorer::operator++()
{
    ForceIterator::_Ptr++;
    force::utils::FilterText(*this, m_skipedText);
    return *this;
}

force::ForceIgnorer & force::ForceIgnorer::operator++(int)
{
    ++(ForceIterator::_Ptr);
    return *this;
}
