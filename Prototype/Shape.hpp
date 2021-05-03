/**
 * @file Shape.hpp
 * @author your name (you@domain.com)
 * @brief 基类
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * Prototype 模式:
 *  是一种创建型模式, 使得可以复制已有对象, 而无需依使得代码依赖于它门所属的类
 *  
 *  如果已有一个对象, 希望生成一个完全一模一样的复制品:
 *      方法 1. 声明一个属于相同类的对象, 遍历原始对象的所有成员变量, 将其复制到新对象中
 *              问题: 私有变量不可访问 && 有时只知道所实现的接口但却不知道所属的具体类 && 需要知道类的细节(依赖)
 *      方法 2. 原型模式
 * 
 * 适用场景:
 *  1. 如果需要复制一些对象, 同时又希望代码独立于这些对象所属的具体类, 可以使用原型模式
 *  2. 如果子类的区别仅在于其对象的初始化方式, 那么可以使用该模式来减少子类的数量: 别人创建这些子类的目的可能是为了创建特定类型的对象
 */

#pragma once

class Shape{
private:
    int x_;
    int y_;
    int color_;
public:
    
    Shape(Shape const& s) : x_(s.x_), y_(s.y_), color_(s.color_){}
    Shape(int x, int y, int color) : x_(x), y_(y), color_(color){}
    /* 在基类中声明虚析构函数: 确保在析构时能够触发动态绑定 */
    virtual ~Shape(){}

    /* prototype 模式需要一个纯虚的 clone 方法 */
    virtual Shape* clone() = 0;             /* 通过克隆自己创建对象 */
};