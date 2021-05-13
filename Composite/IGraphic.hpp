/**
 * @file IGraphic.hpp
 * @author your name (you@domain.com)
 * @brief Composite 中的树根
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>

/**
 * @brief 接口定义
 * [Component]
 */
class IGraphic{
public:
    virtual void move(int x, int y) = 0;
    virtual void draw() = 0;
    virtual ~IGraphic(){}
};