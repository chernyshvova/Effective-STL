#pragma once
#include <vector>

struct Securities
{
    int m_guid = -1;
    std::vector<char> m_data = std::vector<char>(10000);
};

