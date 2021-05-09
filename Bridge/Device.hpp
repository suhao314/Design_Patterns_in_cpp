#pragma once


/**
 * @brief Device 接口定义
 * [Implementor]
 */
class Device{
public:
    virtual bool isEnabled() = 0;
    virtual bool enable() = 0;
    virtual bool disable() = 0;
    virtual int getVolume() = 0;
    virtual bool setVolume(int v) = 0;
    virtual int getChannel() = 0;
    virtual bool setChannel(int c) = 0;

    virtual ~Device(){};
};