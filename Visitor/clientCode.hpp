#pragma once
#include "ConcreteComponentA.hpp"
#include "ConcreteComponentB.hpp"
#include "ConcreteVisitor1.hpp"
#include "ConcreteVisitor2.hpp"
#include <array>

void clientCode(std::array<const IComponent*, 2> components, IVisitor* visitor) {
    for(const IComponent* comp : components) 
        comp->accept(visitor);
}