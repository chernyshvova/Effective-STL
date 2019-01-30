#pragma once

using ForceIterator = std::_String_iterator<std::_String_val<std::_Simple_types<char>>>;
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


