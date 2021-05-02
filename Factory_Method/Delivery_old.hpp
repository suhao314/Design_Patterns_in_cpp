/**
 * @file Delivery_old.hpp
 * @author your name (you@domain.com)
 * @brief 物流应用(不好的实现)
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
    
public:
    void delivery(){
        // t = new Truck();         /* 声明为了具体的类 */
        // t->deliver();
        /* 未来需要支持海运: 将上述陆地运输注释掉, 新增下面两行 */
        Transport* t = new Ship();     /* new 导致了依赖具体类, 目标: 绕开 new 带来的依赖问题 */
        t->deliver();
    }
};
