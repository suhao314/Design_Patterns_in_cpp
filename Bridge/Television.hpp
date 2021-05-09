#pragma once
#include "Device.hpp"


/**
 * @brief 电视机类的定义
 * [ConcreteImplementor B]
 */
class Television : public Device{
private:
    bool isOn;
    int volume;
    int channel;
public:
    Television():isOn(false), volume(50), channel(12){}
    virtual bool isEnabled() override {return isOn;}
    virtual bool enable() override {return (isOn=true);}
    virtual bool disable() override {return !(isOn=false);}
    virtual int getVolume() override {return volume;}
    virtual bool setVolume(int v) override {return (volume=v);}
    virtual int getChannel() override {return channel;}
    virtual bool setChannel(int c) override {return (channel=c);}
};
