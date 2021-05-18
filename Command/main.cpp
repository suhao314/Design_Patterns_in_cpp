#include <iostream>
#include "Invoker.hpp"
#include "Recevier.hpp"
#include "Command_echo.hpp"
#include "Command_jumbo.hpp"

int main(int, char**) {
    std::string curse = "The Quick Brown Fox Jumps Over the Lazy Dog.";
    std::string charm = "Sogno Di Volare";
    Invoker* invoker = new Invoker();
    invoker->setOnStart(new Command_echo(curse));
    Receiver* receiver = new Receiver;
    invoker->setOnFinish(new Command_jumbo(receiver, curse, charm));

    invoker->doSthImportant();

    delete invoker;
    delete receiver;

    return 0;
}   
