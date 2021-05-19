#pragma once
#include "IMediator.hpp"

/**
 * @brief 重构之前相互关联和依赖的对象们的接口定义
 * [Colleague]
 */
class IComponent{
protected:
    IMediator* mediator_;
public:
    virtual ~IComponent() {}
    IComponent(IMediator* mediator=nullptr);
    virtual void setMediator(IMediator* mediator);
};

IComponent::IComponent(IMediator* mediator) : mediator_(mediator) {}

void IComponent::setMediator(IMediator* mediator) {
    mediator_ = mediator;
}