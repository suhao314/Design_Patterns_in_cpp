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
    TransportFactory* tf = new SeaCreator;
    Delivery d(tf);
    #endif
    d.delivery();
}