#pragma once
#include "AbstractClass.hpp"
#include <iostream>

/**
 * @brief 具体类实现(自定义)基类中的纯虚方法
 * [ConcreteClass1]
 */
class ConcreteClass1 : public AbstractClass {
protected:
    virtual void requiredOperation1() const override;
    virtual void requiredOperation2() const override;
};

void ConcreteClass1::requiredOperation1() const {
    std::cout<<"ConcreteClass1::requiredOperation1() invoked"<<std::endl;
}

void ConcreteClass1::requiredOperation2() const {
    std::cout<<"ConcreteClass1::requiredOperation2() invoked"<<std::endl;
}