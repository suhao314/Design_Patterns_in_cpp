#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <algorithm>
#include <time.h>
#include "Context.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"

#define N 10000
void check(std::vector<int> const& a, std::vector<int> const& b);
void doStrategy(Context* context, std::vector<int>* v, std::string str);

int main(int, char**) {
    /* 产生一列随机数 */
    srand((int)time(0));
    std::vector<int> a;
    for(int i=0; i<N; i++)
        a.push_back(rand());
    
    /* 获取标准答案 */
    std::vector<int> copy_0 = a;
    std::sort(copy_0.begin(), copy_0.end());

    /* 原始 vector 副本 */
    std::vector<int> copy_1 = a;
    std::vector<int> copy_2 = a;
    
    /* BubbleSort 线程 */
    Context* context1 = new Context(new BubbleSort);
    std::thread th1(doStrategy, context1, &copy_1, "BubbleSort Thread");
    th1.join();

    /* SelectionSort 线程 */
    Context* context2 = new Context(new SelectionSort);
    std::thread th2(doStrategy, context2, &copy_2, "SelectionSort Thread");
    th2.join();

    /* 与标准答案对比 */
    check(copy_0, copy_1);
    check(copy_0, copy_2);

    return 0;
}


void check(std::vector<int> const& a, std::vector<int> const& b) {
    bool flag = true;
    for(int i=0; i<a.size(); i++) {
        if(a[i]!=b[i]) {
            flag = false;
            break;
        }
    }
    std::cout<<(flag ? ("AC") : ("WA"))<<std::endl;
}

void doStrategy(Context* context, std::vector<int>* v, std::string str){
    std::cout<<str<<std::endl;
    context->sort(*v, 0, v->size());
    // std::cout<<"done";
}