#pragma once
#include "AbstractClass.hpp"
#include <iostream>

/**
 * @brief 具体类实现(自定义)基类中的纯虚方法
 * [ConcreteClass2]
 */
class ConcreteClass2 : public AbstractClass {
protected:
    virtual void requiredOperation1() const override;
    virtual void requiredOperation2() const override;

    virtual void hook1() const override;
};


void ConcreteClass2::hook1() const {
    std::cout<<"ConcreteClass1::hook1() invoked"<<std::endl;
}


void ConcreteClass2::requiredOperation1() const {
    std::cout<<"ConcreteClass2::requiredOperation1() invoked"<<std::endl;
}

void ConcreteClass2::requiredOperation2() const {
    std::cout<<"ConcreteClass2::requiredOperation2() invoked"<<std::endl;
}


