#pragma once
#include <vector>

struct Securities
{
    int m_guid;
    std::vector<char> m_data = std::vector<char>(1000);
};

