#pragma once
#include "IThirdPartyTVLib.hpp"
#include <fstream>
#include <string>
#include <iostream>

/**
 * @brief 对 IThirdPartyTVLib 中所定义接口的实现
 * [Service]/[RealSubject]
 * Proxy 中存在一个此类的指针
 * 
 * 对应于实际应用场景, 可以假想本类中所实现的方法效率低下
 */
class ThirdPartyTVClass : public IThirdPartyTVLib{
private:
    std::vector<std::string> videoList;
    std::vector<std::string> videoInfo;
public:
    ThirdPartyTVClass();
    std::vector<std::string> listVideos() override;
    std::string getVideoInfo(int id) override;
    bool downloadVideo(int id) override;
};

std::vector<std::string> ThirdPartyTVClass::listVideos(){
    return videoList;
}

std::string ThirdPartyTVClass::getVideoInfo(int id){
    if(id>=0 && id<videoInfo.size()) return videoInfo[id];
    else return "";
}

bool ThirdPartyTVClass::downloadVideo(int id){
    return true;
}


ThirdPartyTVClass::ThirdPartyTVClass(){
    std::string buf;
    std::ifstream fs1("/home/suhao314/Design_Pattern_in_cpp/Proxy/videoList.dat");
    while(std::getline(fs1, buf)){
        videoList.push_back(buf);
    }

    std::ifstream fs2("/home/suhao314/Design_Pattern_in_cpp/Proxy/videoInfo.dat");
    while(std::getline(fs2, buf)){
        videoInfo.push_back(buf);
    }

}