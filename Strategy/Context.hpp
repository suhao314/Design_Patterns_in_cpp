#pragma once
#include "IStrategy.hpp"

class Context{
private:
    IStrategy* s;
public:
    Context(IStrategy* strategy) : s(strategy) {}
    ~Context() {delete s;}

    void sort(std::vector<int>& v, int lo, int hi){
        s->sort(v, lo, hi);
    }
    
};