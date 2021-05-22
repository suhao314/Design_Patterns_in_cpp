#pragma once
#include "IVisitor.hpp"

/**
 * @brief 可被访问的类的接口定义: accept(IVisitor* visitor)
 * 
 * The Component interface declares an `accept` method that should take the base
 * visitor interface as an argument.
 * 
 * [Element Interface]
 */
class IComponent{
public:
    virtual ~IComponent() {}

    virtual void accept(IVisitor* visitor) const = 0;
};