#pragma once
#include <vector>
#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"

class Printer{
private:
    std::vector<Shape*> prototypes;

public:
    Printer(){
        /* 仅为举例(在 prototypes 中放一些内容), 不改写为工厂方法 */
        Shape* c = new Circle(10, 10, 0, 5);
        prototypes.push_back(c);
        Shape* r = new Rectangle(10, 10, 0, 1, 1);
        prototypes.push_back(r);
    }

    /* 在此处应用原型模式: 无需知晓细节, 可以直接复制出完全一致的对象而无需了解所属类及类的细节 */
    void copy(){
        std::vector<Shape*> shapes;
        for(auto const i : prototypes){
            shapes.push_back(i->clone());
            std::cout<<i<<" cloned -> "<<shapes.back()<<std::endl;
        }
    }
};