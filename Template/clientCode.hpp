#pragma once
#include "AbstractClass.hpp"
#include "ConcreteClass1.hpp"
#include "ConcreteClass2.hpp"


void clientCode(AbstractClass* p) {
    p->templateMethod();
}

