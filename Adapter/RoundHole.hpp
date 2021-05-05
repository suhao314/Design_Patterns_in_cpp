#pragma once

#include "RoundPeg.hpp"
#include <cmath>

#define ERROR 1e-3

/**
 * @brief 圆孔类的定义
 * 其中 fits 方法只能接受 RoundPeg 类指针作为参数
 * 可能的场景: 
 *      本类的代码不可修改
 *      需求变化: 要使用 SquarePeg 类作为 fits 方法的参数
 */
class RoundHole{
private:
    double radius;
public:
    RoundHole(double r):radius(r){}
    double getRadius(){return radius;}
    bool fits(RoundPeg* const peg);
};


bool RoundHole::fits(RoundPeg* const peg){
    return fabs(peg->getRadius()-this->getRadius())<ERROR;
}