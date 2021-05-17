#pragma once
#include "ISubject.hpp"
#include <list>


/**
 * @brief 具体的信息发布者
 * [ConcretePublisher]
 */
class Subject : public ISubject{
protected:
    std::list<IObserver*> observers;
    std::string message;

public:
    virtual ~Subject() {}
    virtual void attachObserver(IObserver* observer) override;
    virtual void detachObserver(IObserver* observer) override;
    virtual void notify() override; 


    virtual void setMessage(const std::string& str);
    virtual void createNotify(const std::string& str);
};

void Subject::attachObserver(IObserver* observer) {
    observers.push_back(observer);
}

void Subject::detachObserver(IObserver* observer) {
    observers.remove(observer);
}

/**
 * @brief 调用 Observer 的 update 接口向具体观察者提供信息
 * 
 */
void Subject::notify() {
    std::list<IObserver*>::iterator iter = observers.begin();
    while(observers.end() != iter){
        (*iter)->update(message);
        ++iter;
    }
}



void Subject::setMessage(const std::string& str) {
    message = str;
}


void Subject::createNotify(const std::string& str) {
    setMessage(str);
    notify();
}