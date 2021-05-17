#pragma once
#include "ISubject.hpp"
#include "Subject.hpp"
#include "Observer.hpp"
#include "IObserver.hpp"

void clientCode() {
    Subject* subject = new Subject();
    

    Observer *observer0 = new Observer(subject);
    Observer *observer1 = new Observer(subject);
    Observer *observer2 = new Observer(subject);
    Observer *observer3;
    Observer *observer4;

    std::cout<<Observer::observerCount_<<" observer(s) is observering subject "<<subject<<std::endl;
    subject->createNotify("Hello World From Subject");

    observer0->unsubscribe();
    observer1->unsubscribe();
    observer2->unsubscribe();

    std::cout<<Observer::observerCount_<<" observer(s) is observering subject "<<subject<<std::endl;

    observer3 = new Observer(subject);
    observer4 = new Observer(subject);

    std::cout<<Observer::observerCount_<<" observer(s) is observering subject "<<subject<<std::endl;

    subject->createNotify("Now We Have Some Secretes to Share.");

    
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete observer0;
    delete subject;
}