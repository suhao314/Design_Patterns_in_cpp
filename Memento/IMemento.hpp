#pragma once
#include <string>

/**
 * @brief Memento 类的接口定义
 * [Memento Interface]
 */
class IMemento {
public:
    virtual std::string getName() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};