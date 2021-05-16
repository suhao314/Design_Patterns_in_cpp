#pragma once
#include <string>

/**
 * @brief 简单地通过枚举类型的匹配来判断是否可处理
 * 
 */
enum class RequestType{
    REQ_Nuts,
    REQ_Banana,
    REQ_Coffee,
    REQ_Bone
};

/**
 * @brief 请求信息
 * 
 */
class Request{
protected:
    std::string description;
    RequestType reqType;
public:
    Request(const std::string& desc, RequestType type) : description(desc), reqType(type) {}
    RequestType getRequestType() const {return reqType;}
    const std::string& getDescription() const {return description;}
};