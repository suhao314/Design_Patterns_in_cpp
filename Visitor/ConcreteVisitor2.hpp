#pragma ocne
#include "IVisitor.hpp"
#include <iostream>


/**
 * @brief 具体访问者类
 * 不同的具体访问者可以实现不同版本的访问算法, 但都可以访问所有具体的被访问类
 * 
 * Concrete Visitors implement several versions of the same algorithm, which can
 * work with all concrete component classes.
 *
 * You can experience the biggest benefit of the Visitor pattern when using it
 * with a complex object structure, such as a Composite tree. In this case, it
 * might be helpful to store some intermediate state of the algorithm while
 * executing visitor's methods over various objects of the structure.
 * 
 * [Concrete Visitors]
 */
class ConcreteVisitor2 : public IVisitor {
public:
    virtual ~ConcreteVisitor2() {}

    virtual void visitConcreteComponentA(const ConcreteComponentA* element) const override;
    virtual void visitConcreteComponentB(const ConcreteComponentB* element) const override;
};

void ConcreteVisitor2::visitConcreteComponentA(const ConcreteComponentA* element) const {
    std::cout<< element->exclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
}

void ConcreteVisitor2::visitConcreteComponentB(const ConcreteComponentB *element) const {
    std::cout << element->specialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
}