#pragma once
#include "stdafx.h"

using ForceIterator = std::_String_iterator<std::_String_val<std::_Simple_types<char>>>;
namespace force 
{
    namespace utils
    {
        void FilterText(ForceIterator& it, const std::string& text);
    }

}