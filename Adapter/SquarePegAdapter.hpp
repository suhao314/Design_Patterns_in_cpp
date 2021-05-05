#pragma once
#include "SquarePeg.hpp"
#include "RoundPeg.hpp"
#include "Peg.hpp"
#include <cmath>

/**
 * @brief 适配器继承自 Client 可使用的类型 RoundPeg
 * 假装自己是一枚 RoundPeg, 重写圆钉的接口 getRadius
 * 注意 RoundPeg 类中的 getRadius 必须为虚方法才能触发动态绑定
 */
class SquarePegAdapter : public RoundPeg{
private:
    SquarePeg* peg;
public:
    SquarePegAdapter(SquarePeg* p):peg(p){}

    virtual double getRadius() const override {return peg->getWidth()*sqrt(2.0)*0.5;}
};