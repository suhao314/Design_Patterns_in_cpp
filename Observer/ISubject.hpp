#pragma once
#include "IObserver.hpp"

/**
 * @brief 信息发布者的接口定义
 * [Publisher]
 */
class ISubject{
public:
    virtual ~ISubject(){}
    virtual void attachObserver(IObserver* observer) = 0;
    virtual void detachObserver(IObserver* observer) = 0;
    virtual void notify() = 0;
};