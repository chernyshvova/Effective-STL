#pragma once

namespace force
{
    class ForceRemover : public std::string::iterator
    {
    public:
        ForceRemover();
        ForceRemover(std::string::iterator c, const std::string& skipedText);
        bool operator==(const std::string::iterator& it);
        bool operator!=(const ForceRemover& it);
        char operator*();
        ForceRemover& operator++();
        ForceRemover& operator++(int);
        ForceRemover& operator+=(int);
        //ForceRemover& operator--();
        //ForceRemover operator--(int);


    private:
        std::string::iterator m_cursor;
        std::string m_skipedText;
    };
}


