#include "Device.hpp"
#include "Radio.hpp"
#include "Television.hpp"
#include "AdvancedRemote.hpp"
#include <iostream>

int main(){
    Television* tv = new Television();
    Remote* remote = new AdvancedRemote(tv);
    remote->togglePower();
    remote->togglePower();

    Radio* radio = new Radio();
    /* 基类指针不能访问派生类新增的成员 */
    AdvancedRemote* r = new AdvancedRemote(radio);
    r->togglePower();
    r->mute();
    r->togglePower();

    delete tv;
    delete remote;
    delete radio;
    delete r;

    return 0;
}


/**
 * @brief 桥接模式
 * 
 * 遥控器(Remote) 和 设备(Device) 之间如果使用类的继承, 将需要定义 4 个不同的类:
 *  1. class TelevisionRemote : public Remote{...Television* tv...}
 *  2. class TelevisionAdvancedRemote : public Remote{...Television* tv...}
 *  3. ...
 *  4. ...
 * 
 * 如果要增加一种新的遥控器或设备, 会产生出非常多的类
 * 
 * 在遥控器和设备的维度上分别进行独立的扩展, 不再使用继承而使用类的组合来解决问题:
 *  Remote 类中放一个 Device 的指针
 * 这样就将与遥控器中与设备有关的操作委派给 Device 类的指针(作为桥梁连接 Remote 和 Device)
 * 
 * 
 */