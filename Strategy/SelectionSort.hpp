#pragma once
#include "IStrategy.hpp"
#include "swap.hpp"

class SelectionSort : public IStrategy{
    virtual void sort(std::vector<int>& v, int lo, int hi) override;
    void operator()(std::vector<int>& v, int lo, int hi){sort(v, lo, hi);}
};


/**
 * @brief 在 v[lo, hi) 中寻找最大元素的秩(如有多个返回最后一个)
 * @details 稳定实现
 * @param v 
 * @param lo 
 * @param hi 
 * @return int 
 */
int selectMax(std::vector<int>& v, int lo, int hi){
    int maxPos = lo;
    int max = v[maxPos];
    for(lo+=1; lo<hi; lo++){
        if(max <= v[lo]){
            max = v[lo];
            maxPos = lo;
        }
    }
    return maxPos;
}


void SelectionSort::sort(std::vector<int>& v, int lo, int hi){
    while(lo < hi){
        int maxPos = selectMax(v, lo, hi);
        swap(v[--hi], v[maxPos]);
    }
}