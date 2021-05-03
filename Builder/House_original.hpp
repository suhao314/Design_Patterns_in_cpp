/**
 * @file House.hpp
 * @author your name (you@domain.com)
 * @brief 构建一个房子
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * 原始实现
 * 
 */

#pragma once
#include <iostream>

class House{
protected:
    virtual void buildWall() = 0;
    virtual void buildCeil() = 0;
    virtual void buildFloor() = 0;
public:

    /* 稳定且相对**复杂**的构建过程 */
    void Init(){
        /** 
         * 不能实现为构造函数: 下面的3次调用均为静态绑定(不能调用本类的纯虚方法)
         * 如果是动态绑定: 调用父类构造函数时子类还不存在, 不能动态绑定到子类的函数
         */
        this->buildFloor();
        for(int i=0; i<4; i++) this->buildWall();
        this->buildCeil();
    }
};

class HouseStone : public House{
protected:
    virtual void buildWall() override{
        std::cout<<"build a stone wall"<<std::endl;
    }
    virtual void buildFloor() override{
        std::cout<<"build a stone floor"<<std::endl;
    }
    virtual void buildCeil() override{
        std::cout<<"build a stone ceil"<<std::endl;
    }
};