#pragma once
#include "Remote.hpp"

/**
 * @brief 高级遥控器(带一键静音功能)
 * [RefinedAbstraction]
 */
class AdvancedRemote : public Remote{
public:
    AdvancedRemote(Device* d) : Remote(d){}
    virtual void mute(){device->setVolume(0); std::cout<<"Device "<<device<<" MUTE"<<std::endl;}
};