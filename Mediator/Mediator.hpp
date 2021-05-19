#pragma once
#include "IMediator.hpp"
#include "Component1.hpp"
#include "Component2.hpp"


/**
 * @brief 具体中介者类: 依赖于所有的 [ConcreteColleague]
 * [ConcreteMediator]
 */
class Mediator : public IMediator {
private:
    Component1* component1_;
    Component2* component2_;

public:
    Mediator(Component1* component1, Component2* component2);
    virtual void notify(IComponent* sender, std::string event) const override;
};

/**
 * @brief 调用 Medaitor 的构造函数前要求 ConcreteComponent 对象已经存在
 * 
 * @param component1 
 * @param component2 
 */
Mediator::Mediator(Component1* component1, Component2* component2) : 
    component1_(component1), component2_(component2) {
        /* Concrete Component 类的对象在被构造时 Concrete Medaitor 对象还不存在, 需要 Concrete Medaitor 负责对 Concrete Component 的 IMediator* 变量赋值 */
        component1_->setMediator(this);
        component2_->setMediator(this);
    }

void Mediator::notify(IComponent* sender, std::string event) const {
    /* C++ 不支持 switch(std::string) */
    if(event == "A") {
        std::cout << "Mediator reacts on A and triggers following operations:\n";
        std::cout<<"Medaitor::notify() -> Component2::doC()"<<std::endl;
        component2_->doC();
    }
    if(event == "D") {
        std::cout << "Mediator reacts on D and triggers following operations:\n";
        std::cout<<"Mediator::notify() -> Component1::doB() && Component2::doC()"<<std::endl;
        component1_->doB();
        component2_->doC();
    }
}