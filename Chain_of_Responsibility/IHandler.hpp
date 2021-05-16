#pragma once
#include "Request.hpp"
#include <string>

/**
 * @brief Handler Interface
 * 
 */
class IHandler {
public:
    virtual IHandler* setNext(IHandler* handler) = 0;
    virtual std::string handle(Request const& req) = 0;
};