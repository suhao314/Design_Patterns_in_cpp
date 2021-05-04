#include "Singleton.hpp"
#include <iostream>

void threadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout<<singleton->value()<<std::endl;
}


void threadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Singleton* singleton = Singleton::getInstance("Bar");
    std::cout<<singleton->value()<<std::endl;
}

int main(){
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();

    return 0;
}