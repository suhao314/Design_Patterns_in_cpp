#pragma once
#include <string>

/**
 * @brief 观察者的接口定义
 * [Subscriber]
 */
class IObserver{
public:
    virtual ~IObserver() {};
    virtual void update(const std::string& messageFromSubject) = 0;
};