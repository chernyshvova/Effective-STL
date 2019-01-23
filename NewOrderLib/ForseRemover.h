#pragma once

using ForceIterator = std::_String_iterator<std::_String_val<std::_Simple_types<char>>>;
namespace force
{
    
    class ForceRemover : public ForceIterator
    {
    public:
        ForceRemover();
        ForceRemover(ForceIterator c);
        bool operator==(ForceIterator& it)const;
        bool operator!=(const ForceRemover& it);
        char operator*();
        ForceRemover& operator++();
        ForceRemover& operator+(const ForceRemover& rlvar);
        ForceRemover& operator++(int);
        ForceRemover& operator+=(int);
        ForceRemover& operator--(int);
        ForceRemover& operator-=(int);
        ForceRemover& operator[](int);
        ForceRemover& operator-(const ForceIterator & other);
        bool operator < (const ForceIterator& other)const;
        bool operator > (const ForceIterator& other)const;
        bool operator <= (const ForceIterator& other)const;
        bool operator>=(const _Myiter& _Right) const;
       
    private:
        std::string m_skipedText;
    };

    template<typename T>
    class CustomIterator : public std::iterator<std::forward_iterator_tag, T>
    {
    private:
        T *it;
    public:

        // Basic iterator traits
        CustomIterator() {}

        CustomIterator(T *p)
            : it(p)
        {}

        CustomIterator(const CustomIterator& cIt)
            : it(cIt.it)
        {}


        CustomIterator& operator=(const CustomIterator& rhs)
        {
            it = rhs.it;
            return *this;
        }

        CustomIterator& operator++() //prefix increment
        {
            ++it;
            return *this;
        }

        friend void swap(CustomIterator& lhs, CustomIterator& rhs)
        {
            T *tmp = lhs.it;
            lhs.it = rhs.it;
            rhs.it = tmp;
        }

        // Input iterator traits
        CustomIterator operator++(int) //postfix increment
        {
            ++it;
            return *this;
        }

        //T operator*() const;
        T* operator->() const
        {
            return it;
        }

        bool operator==(const CustomIterator& rhs)
        {
            return it == rhs.it;
        }

        bool operator!=(const CustomIterator& rhs)
        {
            return it != rhs.it;
        }

        // Output iterator traits
        T& operator*() const
        {
            return *it;
        }
    };
}


