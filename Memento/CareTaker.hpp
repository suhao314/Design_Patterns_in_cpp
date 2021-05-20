#pragma once
#include <vector>
#include "Memento.hpp"
#include "Originator.hpp"


/**
 * @brief CareTaker 负责存储历史状态和状态的恢复
 * [CareTaker]
 */
class CareTaker {
private:
    std::vector<IMemento*> history_;
    Originator* originator_;
public:
    CareTaker(Originator* originator);
    void showHistory() const;
    
    void backup();
    void undo();
};

CareTaker::CareTaker(Originator* originator) : originator_(originator) {}

/**
 * @brief 为 Originator 生成快照并储存
 * 
 */
void CareTaker::backup() {
    std::cout<<"CareTaker::backup() invoked, saving state to CareTaker::history_"<<std::endl;
    this->history_.push_back(originator_->save());
}

/**
 * @brief 使用快照记录恢复 Originator 的状态
 * 
 */
void CareTaker::undo() {
    if(history_.size() == 0) return;
    IMemento* memento = history_.back();
    this->history_.pop_back();
    std::cout<<"CareTaker::undo() invoked, restoring state to "<<memento->getName()<<std::endl;
    try {
        this->originator_->restore(memento);
    } catch(...) {
        this->undo();
    }
}

void CareTaker::showHistory() const {
    std::cout<<"------CareTaker::history_ start------"<<std::endl;
    for(auto e : history_) 
        std::cout<<e->getName()<<std::endl;
    std::cout<<"------CareTaker::history_   end------"<<std::endl;
}
