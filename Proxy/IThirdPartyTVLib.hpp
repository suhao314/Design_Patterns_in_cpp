#pragma once
#include <vector>
#include <string>
#include <stdio.h>

/**
 * @brief 服务接口定义(I for Interface)
 * [ServiceInterface]/[Subject]
 * Proxy 类需要遵循(继承)该接口才能伪装成本类
 */
class IThirdPartyTVLib{
public:
    virtual std::vector<std::string> listVideos() = 0;
    virtual std::string getVideoInfo(int id) = 0;
    virtual bool downloadVideo(int id) = 0;
    virtual ~IThirdPartyTVLib(){};
};

