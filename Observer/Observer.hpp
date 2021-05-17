#pragma once
#include <iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"

/**
 * @brief 具体观察者
 * [ConcreteSubscribers]
 */
class Observer : public IObserver {
protected:
    ISubject* subject_;                                         /* 所侦听的对象 */
    std::string messageFromSubject_;                            /* 所侦听到的信息 */

    int number_;                                                /* 当前观察者的编号 */
    
public:
    static int observerCount_;                                  /* 当前正在侦听的观察者计数(可实现为单例) */
    Observer(ISubject* subject);
    virtual ~Observer() {}

    virtual void update(const std::string& messageFromSuject) override;

    virtual void unsubscribe();

};

int Observer::observerCount_ = 0;

Observer::Observer(ISubject* subject) : subject_(subject) {
    subject_->attachObserver(this);
    number_ = observerCount_++;
}


/**
 * @brief 供 ConcreteSunject 调用
 * 
 * @param messageFromSubject 
 */
void Observer::update(const std::string& messageFromSubject) {
    messageFromSubject_ = messageFromSubject;
    std::cout<<"Observer "<<number_<<"#: "<<messageFromSubject_<<std::endl;
}

void Observer::unsubscribe() {
    subject_->detachObserver(this);
    Observer::observerCount_--;
    std::cout<<"Observer "<<number_<<"#: UNSUBSCRIBE"<<std::endl;
}