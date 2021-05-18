#pragma once
#include <string>
#include <iostream>
#include "ICommand.hpp"

class Invoker{
private:
    ICommand* on_start_;
    ICommand* on_finish_;
public:
    ~Invoker();
    void setOnStart(ICommand* command);
    void setOnFinish(ICommand* command);
    void doSthImportant();
};

void Invoker::setOnFinish(ICommand* command) {
    this->on_finish_ = command;
}

void Invoker::setOnStart(ICommand* command) {
    this->on_start_ = command;
}

void Invoker::doSthImportant() {
    std::cout << "Invoker: Does anybody want something done before I begin?\n";
    if(this->on_start_)
        this->on_start_->execute();

    std::cout << "Invoker: ...doing something really important...\n";

    std::cout << "Invoker: Does anybody want something done after I finish?\n";
    if(this->on_finish_)
        this->on_finish_->execute();
}

Invoker::~Invoker() {
    delete on_start_;
    delete on_finish_;
}