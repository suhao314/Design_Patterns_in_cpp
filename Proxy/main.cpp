#include "CachedTVClass.hpp"
#include <iostream>

/**
 * [Client]
 */
int main(){
    /*  外部应用 */
    ThirdPartyTVClass* s = new ThirdPartyTVClass;
    CachedTVClass* proxy = new CachedTVClass(s);
    
    proxy->listVideos();
    std::cout<<proxy->getVideoInfo(1)<<std::endl;

    delete s;
    delete proxy;
    return 0;
}

/**
 * @brief 代理模式
 * 动机:
 *  在面向对象系统中, 有些对象由于某种原因(安全控制, 构造器开销很大, 需要进程外的访问等), 直接访问会有很多麻烦
 *  在不失去透明操作(与原始对象的操作接口完全一致)的情况下可以通过增加间接层(Proxy)实现
 * 
 * 小结
 *  1. "增加一层间接层" 时软件系统中对许多复杂问题的一种常见解决方法
 *      在面向对象系统中, 直接使用某些对象会带来很多问题, 作为间接层的 Proxy 对象是解决这一问题的常用手段
 * 2. 具体 Proxy 设计模式的实现方法, 实现粒度相差很大:
 *      有些可能对单个对象做细粒度的控制， 如 copy-on-write
 *      有些可能对组件模块提供抽象代理曾, 在架构层次对对象做 Proxy
 *      有些代理类使用工具生成, 不需要手工写
 * 3. Proxy 并不一定要求保持接口完整的一致性, 只要能够实现间接控制, 有时损失一些透明性也可接受
 * 
 */