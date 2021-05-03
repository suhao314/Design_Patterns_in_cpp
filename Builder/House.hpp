/**
 * @file House.hpp
 * @author your name (you@domain.com)
 * @brief 构建一个房子
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * 应用生成器模式
 * 
 */

#pragma once
#include <iostream>

class House{
public:
    virtual ~House(){}
};

/* [Builder] 稳定: 所需操作集合的接口定义 */
class HouseBuilder{
protected:
    House* pHouse;
public:
    virtual void buildWall(){}                  /* 调用父类的虚函数要求父类虚函数有实现 (最简单的实现: {}) */
    virtual void buildCeil(){}
    virtual void buildFloor(){}
    House* getResult(){
        return pHouse;
    }
    virtual ~HouseBuilder(){}
};

/* [Director] 稳定: 将复杂性(对象的构建)集中至此 */
class HouseDirector{
public:
    HouseBuilder* pHouseBuilder;

    /* 传入哪种 builder 就会建造出哪种房子 */
    HouseDirector(HouseBuilder* hb):pHouseBuilder(hb){}

    /* 稳定且相对**复杂**的构建过程 */
    House* Construct(){
        pHouseBuilder->buildFloor();
        for(int i=0; i<4; i++) pHouseBuilder->buildWall();
        pHouseBuilder->buildCeil();
        return pHouseBuilder->getResult();
    }
};

class HouseStone : public House{
public:
    virtual ~HouseStone(){}
};

/* [ConcreteBuilder] 可以包含多种变化 */
class HouseStoneBuilder : public HouseBuilder{
public:
    virtual ~HouseStoneBuilder(){};
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

/**
 * 要点小结
 * 1. Builder 模式主要用于 分步骤构建一个复杂对象
 *      步骤是稳定的(类似于 Template 模式), 但复杂对象的各个部分可以经常变化
 * 2. Builder 对于变化点的封装: 应对复杂对象各部分的变化
 *      不能应对构建步骤的变化
 * 3. C++由于父类构造器中对于虚函数的调用只能静态绑定至本类(且可能会导致编译错误), 需要 Builder模式
 *      Java C# 允许动态绑定, 未必一定需要 Builder模式
 * 
 */