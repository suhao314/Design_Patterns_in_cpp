/**
 * @file Originator.hpp
 * @author your name (you@domain.com)
 * @brief 原发器类的定义(接口定义和类定义合二为一)
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <string>
#include <iostream>
#include "IMemento.hpp"
#include "Memento.hpp"

/**
 * @brief 原发器
 * @details 重要功能:
 *  1. 生成自己的快照
 *  2. 按照快照恢复状态
 * [Originator]
 */
class Originator {
private:
    std::string state_;
    std::string randomString(int length=10);
public:
    IMemento* save();
    void restore(IMemento* memento);
    Originator(std::string state);
    ~Originator();
    void changeSatate();
};

IMemento* Originator::save() {
    return new Memento(state_);
}

void Originator::restore(IMemento* memento) {
    this->state_ = memento->state();
    std::cout << "Originator: My state has changed to: " << this->state_ << "\n";
}

std::string Originator::randomString(int length) {
    const char alphaNum[] = 
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int stringLength = sizeof(alphaNum) - 1;

    std::string rs;
    for(int i=0; i<length; i++) {
        rs += alphaNum[std::rand() % stringLength];
    } 
    return rs;
}

void Originator::changeSatate() {
    std::cout << "Originator: state will change:\n";
    this->state_ = randomString(30);
    std::cout << "Originator: and my state has changed to: " << this->state_ << "\n";
}

Originator::Originator(std::string state) : state_(state) {
    std::cout << "Originator: My initial state is: " << this->state_ << "\n";
}

Originator::~Originator() {

}
