#include "stdafx.h"
#include "ForceUtils.h"

void force::utils::FilterText(ForceIterator & it, const std::string & text)
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
        FilterText(it, text);
    }
}
