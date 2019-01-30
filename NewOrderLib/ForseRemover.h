#pragma once
namespace force
{
    using ForceIterator = std::_String_iterator<std::_String_val<std::_Simple_types<char>>>;

    class ForceRemover : public ForceIterator
    {
    public:
        ForceRemover();
        ForceRemover(ForceIterator&);
        bool operator==(ForceIterator& it)const;
        bool operator==(ForceRemover& it)const;
        bool operator==(const char)const;
        bool operator!=(const ForceRemover& it);
        char& operator*();
        ForceRemover & operator=(ForceIterator & rval);
        ForceRemover& operator++();
        ForceRemover& operator+(const ForceRemover& rlvar);
        ForceRemover& operator++(int);
        ForceRemover& operator+=(int);
        ForceRemover& operator--(int);

        ForceRemover& operator-(const ForceIterator & other);
        bool operator < (const ForceIterator& other)const;
       
    private:
        std::string m_skipedText;
    };
}


