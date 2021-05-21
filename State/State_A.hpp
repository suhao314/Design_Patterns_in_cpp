#pragma once
#include "IState.hpp"
#include <iostream>

/**
 * @brief 具体状态
 * 会自行实现特定于状态的方法
 * 为了避免多个状态中包含相似代码, 可以提供一个封装有部分通用行为的中间抽象类
 * 
 * [Concrete State]
 */
class State_A : public IState {
public:
    void handle1() override;
    void handle2() override;
};

void State_A::handle1() {
    std::cout << "State_A::handle1 invoked by Context::request1.\n";
    std::cout << "State_A wants to change the state of the context.\n";
}

void State_A::handle2() {
    std::cout << "State_A::handle2 invoked by Context::request2.\n";
    std::cout << "State_A wants to change the state of the context.\n";
}