#pragma once
#include "stdafx.h"

namespace trampOperation
{
    template<typename Container, typename Value>
    void Insert(Container& cont, Value value)
    {
        cont.insert(cont.end(), value);
    }

    template<typename KeyType, typename ValueType>
    void Insert(std::map<KeyType, ValueType>& cont, ValueType value)
    {
        static int g_key = 0;
        cont[g_key++] = value;
    }

    template<typename ValueType>
    void Insert(std::stack<ValueType>& cont, ValueType value)
    {
        cont.push(value);
    }

    template<typename Container>
    void RemoveFrom(Container& cont)
    {
        cont.pop_back();
    }


    template<typename KeyType, typename ValueType>
    void RemoveFrom(std::map<KeyType, ValueType>& cont)
    {
        cont.erase(cont.cbegin());
    }

    template<typename ValueType>
    void RemoveFrom(std::stack<ValueType>& cont)
    {
        cont.pop();
    }


    template<typename Container>
    void InstertInContainer(Container& cont, const size_t countTimes)
    {
        int g_guid = 0;
        for (int i = 0; i < countTimes; ++i)
        {
            Securities newSecurities;
            newSecurities.m_guid = g_guid++;
            Insert(cont, newSecurities);
        }
    }

    template<typename Container>
    void RemoveFromContainer(Container& cont, const size_t countTimes)
    {
        for (int i = 0; i < countTimes; ++i)
        {
            RemoveFrom(cont);
        }
    }

    template<typename Container>
    bool FindInConteiner(Container& cont, const size_t securitiesGui, Securities& findResult)
    {
        for (auto it : cont)
        {
            if (it.m_guid == securitiesGui)
            {
                findResult = it;
                return true;
            }
        }
        return false;
    }

    template<typename KeyType, typename ValueType>
    bool FindInConteiner(std::map<KeyType, ValueType>& cont, const size_t securitiesGui, Securities& findResult)
    {
        for (auto it : cont)
        {
            if (it.second.m_guid == securitiesGui)
            {
                findResult = it.second;
                return true;
            }
        }
        return false;
    }

    template<typename KeyType, typename ValueType>
    bool FindInConteiner(std::stack<KeyType, ValueType>& cont, const size_t securitiesGui, Securities& findResult)
    {
        std::stack<KeyType> tmp;
        bool result = false;
        while (!cont.empty())
        {
            if (cont.top().m_guid == securitiesGui)
            {
                findResult = cont.top();
                result = true;
            }
            tmp.push(cont.top());
            cont.pop();
        }

        while (!tmp.empty())
        {
            cont.push(tmp.top());
            tmp.pop();
        }

        return result;
    }
}
