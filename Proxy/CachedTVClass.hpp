#pragma once
#include "IThirdPartyTVLib.hpp"
#include "ThirdPartyTVClass.hpp"

/**
 * @brief 作为 ThirdPartyTVClass 的代理
 * 对 IThirdPartyTVLib 中所定义接口的实现(一般与 ThirdPartyTVClass 的实现不同)
 * [Proxy]
 * 继承自 IThirdPartyTVLib, 可以假装自己是 ThirdPartyTVClass, 同时可以调用 ThirdPartyTVClass 的方法
 * 内含一个 Service/RealSubject 指针
 * 
 * 本质上相当于对 RealSubject 的一种间接访问
 * 
 * 对应于实际应用场景, 可以假想本类中所实现的方法效率更好
 */
class CachedTVClass : public IThirdPartyTVLib{
protected:
    /* Service 指针 */
    ThirdPartyTVClass* service;
    /* Cache */
    bool checkAccess();
    bool downloadFromLocal();
    bool needReset;
    std::vector<std::string> listCache;
    std::vector<std::string> infoCache;

public:
    CachedTVClass(ThirdPartyTVClass* s):service(s),needReset(true){}
    /* 实现接口所定义的方法 */
    virtual std::vector<std::string> listVideos() override;
    virtual std::string getVideoInfo(int id) override;
    virtual bool downloadVideo(int id) override;
};



std::vector<std::string> CachedTVClass::listVideos(){
    if(needReset||listCache.size()==0)
        listCache = service->listVideos();
    return listCache;
}


std::string CachedTVClass::getVideoInfo(int id){
    if(needReset||infoCache.size()==0){
        for(int i=0; i<listCache.size(); i++)
            infoCache.push_back(service->getVideoInfo(i));
    }
    return infoCache[id];
}


bool CachedTVClass::downloadVideo(int id){
    return true;
}


/**
 * @brief Proxy 的整体设计思想
 * 
 * 继承并实现接口
 * 内部间接访问 Realsubject
 * 
 */