#pragma once
#include "Device.hpp"
#include <iostream>

/**
 * @brief 遥控器类的基类
 * [Abstraction]
 */
class Remote{
protected:
    /* 包含一个 Device 接口的指针, 访问属性为 protected, 使得基类能够访问 */
    Device* device;
public:
    Remote(Device* d) : device(d){}
    virtual void togglePower();
    virtual void volumeDown();
    virtual void volumeUp();
    virtual void channelDown();
    virtual void channelUp();

    virtual ~Remote(){};
};

void Remote::togglePower(){
    if(device->isEnabled()){
        device->disable();
        std::cout<<"Device "<<device<<" is shutting down"<<std::endl;
    } 
    else{
        device->enable();
        std::cout<<"Device "<<device<<" is starting"<<std::endl;
    } 
    return;
}

void Remote::volumeDown(){
    if(device->isEnabled())
        device->setVolume(device->getVolume()+10);
    return;
}

void Remote::volumeUp(){
    if(device->isEnabled())
        device->setVolume(device->getVolume()-10);
    return;
}

void Remote::channelDown(){
    if(device->isEnabled())
        device->setChannel(device->getChannel()-1);
    return;
}

void Remote::channelUp(){
    if(device->isEnabled())
        device->setChannel(device->getChannel()+1);
    return;
}