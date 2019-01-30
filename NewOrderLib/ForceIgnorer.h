#pragma once
#include "ForceUtils.h"

namespace force
{
    class ForceIgnorer: public ForceIterator
    {
    public:
        ForceIgnorer();
        ForceIgnorer(ForceIterator&);
        ForceIgnorer& operator++();
        ForceIgnorer& operator++(int);
    private:
        std::string m_skipedText;
    };
}


