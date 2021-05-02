#pragma once

#include <iostream>

/**
 * @brief 不同运输方式都继承自这一基类: 规定了必须实现的接口 deliver
 * 注意抽象基类不允许被 new 
 */
class Transport{
public:
    virtual void deliver() = 0;
    virtual ~Transport(){}
};

/**
 * @brief 陆地运输方式
 * 
 */
class Truck : public Transport{
public:
    virtual void deliver(){
        std::cout<<"Transport by Truck"<<std::endl;
    }
};

/**
 * @brief 海上运输方式
 * 
 */
class Ship : public Transport{
public:
    virtual void deliver(){
        std::cout<<"Transport by Ship"<<std::endl;
    }
};