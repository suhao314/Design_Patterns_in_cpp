#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "SquirrelHandler.hpp"
#include "Request.hpp"
#include "MonkeyHandler.hpp"

void ClientCode(AbstractHandler& handler) {
    std::vector<Request> requests = {Request("Nut", RequestType::REQ_Nuts), Request("Banana", RequestType::REQ_Banana), Request("Coffee", RequestType::REQ_Coffee)};
    /* ClientCode 构造一系列的请求发送给 handler */
    for (const auto req : requests) {
        std::cout << "ClientCode: Who wants to handle a " << req.getDescription() << "?\n";
        const std::string result = handler.handle(req);
        if (!result.empty()) {
            /* 被 handler 处理 */
            std::cout << "    +" << result;
        } else {
            /* 不能被责任链中的任何一个 handler 处理 */
            std::cout << "    -" << req.getDescription() << " was left untouched.\n";
        }
    }
}