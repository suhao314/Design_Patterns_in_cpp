#pragma once

#include "Peg.hpp"

/**
 * @brief 圆钉类的定义
 * 因为 getRadius 方法要求能够触发动态绑定, 应声明(修改)为虚方法
 */
class RoundPeg : public Peg{
private:
    double radius;
public:
    RoundPeg() = default;
    RoundPeg(double r):radius(r){}
    virtual double getRadius() const {return radius;}
};