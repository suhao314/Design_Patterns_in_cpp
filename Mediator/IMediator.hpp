#pragma once
#include <string>

/* 前向引用声明 */
class IComponent;


/**
 * @brief 复杂对象 Mediator 的接口定义
 * [Mediator]
 */
class IMediator{
public:
    virtual ~IMediator() {}
    virtual void notify(IComponent* sender, std::string event) const = 0;
};