#pragma once
#include "IComponent.hpp"
#include "IVisitor.hpp"
#include <string>

/**
 * @brief 具体的被访问者访问的类
 * 
 * Each Concrete Component must implement the `Accept` method in such a way that
 * it calls the visitor's method corresponding to the component's class.
 * 
 * 
 * [ElementA]
 */
class ConcreteComponentA : public IComponent {
public:
    virtual void accept(IVisitor* visitor) const override;

    std::string exclusiveMethodOfConcreteComponentA() const;
};

void ConcreteComponentA::accept(IVisitor* visitor) const {
    visitor->visitConcreteComponentA(this);
}

std::string ConcreteComponentA::exclusiveMethodOfConcreteComponentA() const {
    return "A";
}