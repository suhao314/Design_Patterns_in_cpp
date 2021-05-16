#pragma once
#include "IHandler.hpp"
#include "Request.hpp"
#include <iostream>


/**
 * @brief Handler 基类
 * [Handler]
 */
class AbstractHandler : public IHandler {
private:
    /* keypoint: 多态链表 */
    IHandler* next_handler_;

protected:
    /* 运行时判断是否能处理 */
    virtual bool canHandleRequest(const Request& req);

public:
    AbstractHandler() : next_handler_(nullptr) {}
    virtual ~AbstractHandler() {}

    /* 链表建立: 返回值类型设为 IHandler 方便链表构建 */
    IHandler* setNext(IHandler *handler) override;

    std::string handle(Request const& req) override;

};




IHandler* AbstractHandler::setNext(IHandler* handler){
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler::canHandleRequest(const Request& req){
    return !(next_handler_==nullptr);
}

/**
 * @brief 调用基类 handle 必然是遇到了无法处理的情形: 沿责任链找下一个节点尝试处理
 * 
 * @param req 
 * @return std::string 
 */
std::string AbstractHandler::handle(Request const& req) {
    /* 找下一个节点处理 */
    if(next_handler_)
        return next_handler_->handle(req);
    else    
        return {};
}
