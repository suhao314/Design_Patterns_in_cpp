/**
 * @file Circle.hpp
 * @author your name (you@domain.com)
 * @brief 圆形
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "Shape.hpp"

class Circle : public Shape{
private:
    int radius;

public:

    /* 原型方法所需 clone 的实现: 调用复制构造函数(深复制)即可 */
    virtual Shape* clone(){
        return new Circle(*this);
    }
    
    /* 构造函数和复制构造函数 */
    Circle(int x, int y, int color, int r):Shape(x,y,color){radius=r;}
    Circle(Circle const& c):Shape(c){radius=c.radius;}
};