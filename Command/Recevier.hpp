#pragma once
#include <string>
#include <iostream>

class Receiver{
public:
    void businessLogic_baz(const std::string& str);
    void businessLogic_qux(const std::string& str);
};

void Receiver::businessLogic_baz(const std::string& str) {
    std::cout<<"    Receiver::convert to upper case: "<<std::endl;
    for(char e : str){
        if(e>='a' && e<= 'z')
            e += 'A'-'a';
        std::cout<<e;
    }
    std::cout<<std::endl;
}

void Receiver::businessLogic_qux(const std::string& str) {
    std::cout<<"    Receiver::convert to lower case: "<<std::endl;
    for(char e : str){
        if(e>='A' && e<= 'Z')
            e += 'a'-'A';
        std::cout<<e;
    }
    std::cout<<std::endl;
}