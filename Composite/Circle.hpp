#pragma once
#include "Dot.hpp"



/**
 * @brief Circle 类
 * 叶节点要完成大部分的实际工作, 一般不能将工作指派给其他类
 * [Leaf]
 */
class Circle : public Dot{
protected:
    int radius;
public:
    Circle(int x, int y, int r) : Dot(x,y), radius(r) {}
    virtual void draw() override {
        std::cout<<"Circle::draw ("<<x_<<", "<<y_<<", "<<radius<<")\n";
    }
};