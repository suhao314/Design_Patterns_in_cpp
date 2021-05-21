#pragma once
#include <iostream>

/**
 * @brief 封装了算法框架的类
 * 
 * 模板方法模式建议将算法分解为一系列步骤
 * 然后将这些步骤改写为方法
 * 最后在 templateMethod 中依次调用这些方法
 * 
 * 客户端需要自行提供子类并实现所有的抽象步骤
 * 如有必要还需重写一些步骤(但这一步中不包括模板方法自身)
 * 
 * [AbstractClass]
 */
class AbstractClass{
protected:
    /* 算法框架中已经实现好的方法 */
    void baseOperation1() const;
    void baseOperation2() const;
    void baseOperation3() const;

    /* 用户需要实现的方法 */
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;

    /* 提供可扩展性, 子类可以 override */
    virtual void hook1() const {}
    virtual void hook2() const {}


public:
    void templateMethod() const;
    virtual ~AbstractClass() {}

};


/**
 * @brief 模板方法: 定义了算法框架, 用户无需更改框架, 但需要实现内部的具体方法
 * [AbstractClass::templateMethod]
 */
void AbstractClass::templateMethod() const {
    baseOperation1();
    requiredOperation1();
    baseOperation2();
    hook1();
    requiredOperation2();
    baseOperation3();
    hook2();
}

void AbstractClass::baseOperation1() const {
    std::cout<<"AbstractClass::baseOperation1() invoked"<<std::endl;
}
void AbstractClass::baseOperation2() const {
    std::cout<<"AbstractClass::baseOperation2() invoked"<<std::endl;
}
void AbstractClass::baseOperation3() const {
    std::cout<<"AbstractClass::baseOperation3() invoked"<<std::endl;
}

