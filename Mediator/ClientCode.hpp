#pragma once
#include "Mediator.hpp"
#include <iostream>

void ClientCode() {
    Component1* c1 = new Component1();
    Component2* c2 = new Component2();

    Mediator* m = new Mediator(c1, c2);

    std::cout << "Client triggers operation A.\n";

    c1->doA();
    std::cout<<std::endl;

    std::cout << "Client triggers operation D.\n";

    c2->doD();

    delete c1;
    delete c2;
    delete m;
     return;
}