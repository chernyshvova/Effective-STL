#include "stdafx.h"
#include "ForceIgnorer.h"

namespace {
    void filterText(force::ForceIgnorer& it, const std::string& text, bool backwards = false)
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
    filterText(*this, m_skipedText);
    return *this;
}

force::ForceIgnorer & force::ForceIgnorer::operator++(int)
{
    ++(ForceIterator::_Ptr);
    return *this;
}
