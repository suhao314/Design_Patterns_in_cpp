#pragma once
#include "IState.hpp"
#include <iostream>
#include <typeinfo>

/**
 * @brief 与状态有关的上下文
 * 保存了对于一个具体状态对象的引用, 并会将所有与该状态相关的工作委派给它
 * 上下文通过状态接口与状态对象交互, 且会提供一个设置器用于传递新的状态对象
 * [Context]
 */
class Context {
protected:
    IState* state_;

public:
    ~Context();
    Context(IState* initialState);
    void changeState(IState* state);

    void request1();
    void request2();
};

Context::~Context() {
    delete state_;
}

Context::Context(IState* initialState) : state_(nullptr) {
    changeState(initialState);
}

void Context::changeState(IState* state) {
    std::cout<<"Context::changeState() invoked, changing state to "<<typeid(*state).name()<<std::endl;
    if(state_!=nullptr) 
        delete state_;
    state_ = state;
    state_->setContext(this);
}

void Context::request1() {
    state_->handle1();
}

void Context::request2() {
    state_->handle2();
}