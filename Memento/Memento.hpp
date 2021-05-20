#pragma once
#include "IMemento.hpp"
#include <time.h>
#include <ctime>
#include <string>

/**
 * @brief Memento 具体类: Originator 的快照数据结构
 * [Concrete Memento]
 */
class Memento : public IMemento {
private:
    std::string state_;
    std::string date_;

public:
    Memento(std::string state);
    virtual std::string state() const override;
    virtual std::string getName() const override;
    virtual std::string date() const override;
};

Memento::Memento(std::string state) : state_(state) {
    time_t now = time(0);
    this->date_ = std::ctime(&now);
}

std::string Memento::state() const {
    return this->state_;
}

std::string Memento::getName() const {
    return this->date_ + "/ (" + this->state_.substr(0, 9) + "...)";
}

std::string Memento::date() const {
    return this->date_;
}