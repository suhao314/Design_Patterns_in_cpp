/**
 * @file Rectangle.hpp
 * @author your name (you@domain.com)
 * @brief 矩形
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "Shape.hpp"

class Rectangle : public Shape{
private:
    int a_;
    int b_;
public:

    /* 原型方法所需 clone 的实现 */
    virtual Shape* clone(){
        return new Rectangle(*this);
    }
    
    /* 构造函数和复制构造函数 */
    Rectangle(int x, int y, int color, int a, int b):Shape(x,y,color),a_(a),b_(b){}
    Rectangle(Rectangle const& r):Shape(r),a_(r.a_),b_(r.b_){} 
};