/**
 * @file Delivery.hpp
 * @author your name (you@domain.com)
 * @brief 物流应用(工厂方法)
 * @version 0.1
 * @date 2021-05-02
 * 
 * @copyright Copyright (c) 2021
 * 
 * 旧版的物流应用:
 *      只支持陆地运输
 * 新需求: 
 *      需要能够灵活改变运输方式
 * 
 */

#pragma once
#include "Transport.hpp"
#include "TransportFactory.hpp"

class Delivery{
private:
    TransportFactory* _tf;          /* 可被赋值为任意具体的 Factory */
public:
    Delivery(TransportFactory* tf) : _tf(tf){}
    void delivery(){
        Transport* t = _tf->createTransport();
        t->deliver();
    }
};

/**
 * @brief 要点总结
 * 1. Factory Method 模式用于隔离对象的使用者和具体类型之间的耦合关系;
 *  面对一个经常变化的具体类型, 紧耦合关系(new)会导致软件的脆弱
 * 2. Factory Method 模式通过面向对象的手法, 将索要创建的具体对象工作推迟到子类
 *  从而实现一种扩展(而非更改)的策略
 * 3. Factory Method 模式解决单个对象的需求变化(由陆运改为海运)
 *  要求创建方法/参数相同 
 * 
 */