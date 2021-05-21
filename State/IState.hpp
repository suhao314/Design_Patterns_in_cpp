#pragma once

class Context;

/**
 * @brief 状态模式建议为对象的所有可能状态新建一个类, 然后将所有状态的对应行为抽取到这些类中
 * 接口会声明特定于状态的方法
 * 这些方法应能被其他所有具体状态所理解, 因为你不希望某些状态所拥有的方法永远不会被调用
 * [State Interface]
 */
class IState{
protected:
    /**
     * 状态对象可存储对于上下文对象的反向引用
     * 状态可以通过该引用从上下文处获取所需信息, 并且能触发状态转移
     */
    Context* context_;
public:
    virtual ~IState() {}

    void setContext(Context* context);

    /* 所有可能状态的对应行为抽取 */
    virtual void handle1() = 0;
    virtual void handle2() = 0;

};

/**
 * @brief 可以提供设置上下文状态的功能, 实现状态类也可以设置上下文的下一个状态
 * 
 * @param context 
 */
void IState::setContext(Context* context) {
    context_ = context;
}