#pragma once

namespace force
{
    class ForceRemover :
        public std::string::iterator
    {
    public:
        ForceRemover();
        ForceRemover(std::string::iterator c);
        bool operator==(const std::string::iterator& it);
        bool operator!=(const ForceRemover& it);

        ForceRemover& operator++();
        ForceRemover operator++(int);
        ForceRemover& operator--();
        ForceRemover operator--(int);

    private:
        std::string::iterator cursor_;

    };
}


