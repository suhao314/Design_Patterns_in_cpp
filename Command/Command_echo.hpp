#pragma once
#include "ICommand.hpp"
#include <string>
#include <iostream>

/**
 * @brief 
 * [Concrete Command]
 */
class Command_echo : public ICommand{
private:
    std::string payload_;
public:
    explicit Command_echo(std::string const& payload) : payload_(payload) {}
    virtual void execute() const override;
};

void Command_echo::execute() const {
    std::cout<<"Command_echo executing: "<<payload_<<std::endl;
}