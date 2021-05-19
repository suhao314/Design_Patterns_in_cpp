#pragma once
#include "IComponent.hpp"
#include <iostream>

class Component2 : public IComponent {
public:
    void doC();
    void doD();
};

void Component2::doC() {
    std::cout<<"Component2::doC() invoked"<<std::endl;
    mediator_->notify(this, "C");
}

void Component2::doD() {
    std::cout<<"Component2::doD() invoked"<<std::endl;
    mediator_->notify(this, "D");
}