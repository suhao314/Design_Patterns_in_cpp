#pragma once
#include "IStrategy.hpp"
#include "swap.hpp"

class BubbleSort : public IStrategy{
    virtual void sort(std::vector<int>& v, int lo, int hi) override;
    void operator()(std::vector<int>& v, int lo, int hi){sort(v, lo, hi);}
};


/**
 * @brief bubble 过程的定义
 * @details 能够提前发现有序的实现(最优实现: 跳过有序区间)
 * @param v 
 * @param lo 
 * @param hi 
 * @return true 
 * @return false 
 */
bool bubble(std::vector<int>& v, int lo, int hi){
    bool sorted = true;
    for(int i=lo+1; i<hi; i++) {
        if(v[i] < v[i-1]) {
            sorted = false;
            swap(v[i], v[i-1]);
        }
    }
    return sorted;
}


/**
 * @brief 对 v[lo, hi) 进行排序: 非递减
 * 
 * @param v 
 * @param lo 
 * @param hi 
 */
void BubbleSort::sort(std::vector<int>& v, int lo, int hi){
    while(!bubble(v, lo, hi)) hi--;
}
