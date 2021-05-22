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
 * [ElementB]
 */
class ConcreteComponentB : public IComponent {
public:
    virtual void accept(IVisitor* visitor) const override;

    std::string specialMethodOfConcreteComponentB() const;
};

void ConcreteComponentB::accept(IVisitor* visitor) const {
    visitor->visitConcreteComponentB(this);
}

std::string ConcreteComponentB::specialMethodOfConcreteComponentB() const {
    return "B";
} 