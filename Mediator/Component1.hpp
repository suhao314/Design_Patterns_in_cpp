#pragma once
#include "IComponent.hpp"
#include <iostream>

class Component1 : public IComponent {
public:
    void doA();
    void doB();
};

void Component1::doA() {
    std::cout<<"Component1::doA() invoked"<<std::endl;
    mediator_->notify(this, "A");
}

void Component1::doB() {
    std::cout<<"Component1::doB() invoked"<<std::endl;
    mediator_->notify(this, "B");
}