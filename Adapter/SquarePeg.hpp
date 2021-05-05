#pragma once

#include "Peg.hpp"

/**
 * @brief 方钉类的定义
 * 
 */
class SquarePeg : public Peg{
private:
    double width;
public:
    SquarePeg() = default;
    SquarePeg(double w):width(w){}
    double getWidth(){return width;}
};