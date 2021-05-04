#pragma once
#include "Transport.hpp"

/**
 * @brief 工厂基类, 定义了具体工厂类创建对象的接口
 * 接口的工厂
 */
class TransportFactory{
public:
    /* virtual 在此处将依赖关系延迟到运行时 */
    virtual Transport* createTransport() = 0;
    virtual ~TransportFactory(){}                           /* 虚构造函数: 确保删除基类指针指向的派生类对象时能触发动态绑定 */
};

/**
 * @brief 具体工厂类: 负责创建相应的对象
 * 每个类都应该有自己的具体工厂类
 */
class RoadFactory : public TransportFactory{
public:
    virtual Transport* createTransport(){
        return new Truck();
    }
};

/**
 * @brief 具体工厂类: 负责创建相应的对象 
 * 每个类都应该有自己的具体工厂类
 */
class SeaFactory : public TransportFactory{
public:
    virtual Transport* createTransport(){
        return new Ship();
    }
};