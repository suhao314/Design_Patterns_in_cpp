#pragma once
#include "IGraphic.hpp"


/**
 * @brief Dot 类
 * 叶节点要完成大部分的实际工作, 一般不能将工作指派给其他类
 * [Leaf]
 */
class Dot : public IGraphic{
protected:
    int x_;
    int y_;
public:
    Dot(int x, int y) : x_(x), y_(y) {}
    virtual void move(int x, int y) override {
        x_ += x;
        y_ += y;
    }
    virtual void draw(){
        std::cout<<"Dot::draw ("<<x_<<", "<<y_<<")\n";
    }
};