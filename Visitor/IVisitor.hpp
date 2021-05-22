#pragma once

class ConcreteComponentA;
class ConcreteComponentB;

/**
 * @brief 访问者类的接口定义
 * 每一个要被访问的类都对应于一个方法
 * 
 * The Visitor Interface declares a set of visiting methods that correspond to
 * component classes. The signature of a visiting method allows the visitor to
 * identify the exact class of the component that it's dealing with.
 * 
 * 
 * [Visitor Interface]
 */
class IVisitor{
public:
    virtual ~IVisitor() {}

    virtual void visitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void visitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};