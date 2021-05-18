#pragma once
#include "ICommand.hpp"
#include "Recevier.hpp"
#include <string>
#include <iostream>

/**
 * @brief 
 * [Concrete Command]
 */
class Command_jumbo : public ICommand {
private:
    Receiver* receiver_;
    std::string foo_;
    std::string bar_;
public:
    Command_jumbo(Receiver* receiver, std::string foo, std::string bar);
    virtual void execute() const override;
};

Command_jumbo::Command_jumbo(Receiver* receiver, std::string foo, std::string bar) : 
    receiver_(receiver), foo_(foo), bar_(bar) {}

void Command_jumbo::execute() const {
    std::cout<<"Command_jumbo executing: "<<std::endl;
    this->receiver_->businessLogic_baz(foo_);
    this->receiver_->businessLogic_qux(bar_);
}