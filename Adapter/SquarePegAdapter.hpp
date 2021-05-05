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
    /* Adapter 组合了一个对象: 对象适配器 */
    SquarePeg* peg;
public:
    SquarePegAdapter(SquarePeg* p):peg(p){}

    /* (复杂)转换过程 */
    virtual double getRadius() const override {return peg->getWidth()*sqrt(2.0)*0.5;}
};

/**
 * @brief notes
 * 动机:
 *  在软件系统中, 由于应用环境的变化, 常常要将"一些现存的对象"放在新的环境中应用, 但是新环境要求的接口时这些现存对象所不满足的
 * 
 * 具体实例:
 *  STL <stack> <queue> 通过 <deque> 带上转换器的实现 
 * 
 * 小结:
 *  1. Adapter 模式主要应用于 "希望复用一些现存的类, 但接口与复用环境要求不一致的情况", 主要用于遗留代码复用和类库迁移
 *  2. 类适配器采用多继承方式(Java等语言不直接支持, 且缺乏灵活性, 不推荐使用), 对象适配器采用对象组合方式
 * 
 */