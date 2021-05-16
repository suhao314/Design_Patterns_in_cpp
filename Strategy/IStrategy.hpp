#pragma once
#include <vector>

class IStrategy{
public:
    virtual void sort(std::vector<int>& v, int lo, int hi) = 0;
};