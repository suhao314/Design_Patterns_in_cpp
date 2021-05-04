// #define OLD 1

#ifdef OLD
#include "Delivery_old.hpp"
#endif
#ifndef OLD
#include "Delivery.hpp"
#endif
#include <iostream>

int main(){
    #ifdef OLD
    Delivery d;
    #endif
    #ifndef OLD
    TransportFactory* tf = new SeaFactory;
    /* 将工厂指针作为构造器的参数传入 */
    Delivery d(tf);
    #endif
    d.delivery();
}