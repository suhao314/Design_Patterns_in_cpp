#pragma once
#include <string>
#include "Request.hpp"
#include "AbstractHandler.hpp"

/**
 * @brief 具体 Handler
 * MonkeyHandler 只能处理 REQ_Banana 类型的请求, 如不能处理则传给父类
 * [ConcreteHandler1]
 */
class MonkeyHandler : public AbstractHandler {
protected:
    /* 运行时判断是否能处理 */
    virtual bool canHandleRequest(const Request& req) override;
public:
    std::string handle(Request const& req) override;
};

std::string MonkeyHandler::handle(Request const& req){
    if(canHandleRequest(req)){
        return "MonkeyHandler: I can handle the " + req.getDescription() + ".\n";
    } else {
        return AbstractHandler::handle(req);
    }
}

bool MonkeyHandler::canHandleRequest(Request const& req){
    if(req.getRequestType()==RequestType::REQ_Banana)
        return true;
    else 
        return false;
}

