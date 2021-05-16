#pragma once
#include "AbstractHandler.hpp"
#include "Request.hpp"
#include <string>

/**
 * @brief 具体 Handler
 * SquirrelHandler 只能处理 REQ_Nuts 类型的请求, 如不能处理则传给父类
 * [ConcreteHandler2]
 */
class SquirrelHandler : public AbstractHandler {
protected:
    virtual bool canHandleRequest(const Request& req) override;
public:
    std::string handle(Request const& req) override;
};



std::string SquirrelHandler::handle(Request const& req){
    if(canHandleRequest(req)){
        return "SquirrelHandler: I can handle the " + req.getDescription() + ".\n";
    } else {
        return AbstractHandler::handle(req);
    }
}

bool SquirrelHandler::canHandleRequest(Request const& req){
    if(req.getRequestType()==RequestType::REQ_Nuts)
        return true;
    else 
        return false;
}

