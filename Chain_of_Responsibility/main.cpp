#include "SquirrelHandler.hpp"
#include "MonkeyHandler.hpp"
#include "ClientCode.hpp"
#include "DogHandler.hpp"


int main() {
    MonkeyHandler* monkey = new MonkeyHandler;
    SquirrelHandler* squirrel = new SquirrelHandler;
    DogHandler* dog = new DogHandler;

    /* 初始化责任链: monkey -> squirrel -> dog */
    monkey->setNext(squirrel)->setNext(dog);

    /**
    * The client should be able to send a request to any handler, not just the
    * first one in the chain.
    */
    std::cout << "Chain: monkey handler -> squirrel handler -> dog handler\n\n";

    /* monkey handler -> squirrel handler -> dog handler */
    ClientCode(*monkey);
    std::cout << "\n\n----------------------------\n\n\n";


    std::cout << "Subchain: squirrel handler -> dog handler\n\n";
    /* squirrel handler -> dog handler */
    ClientCode(*squirrel);

    delete monkey;
    delete squirrel;
    delete dog;

    return 0;
}

/**
 * 动机
 *  1. 在软件构建过程中, 一个请求可能会被多个对象处理, 但每个请求在运行时只能有一个接受者
 *      如果显式指定, 将带来请求发送者与接受者的紧耦合
 *  2. 使请求的发送者不需要指定具体的接收者: 让请求的接受者在运行时自动决定是否要接受
 *      使多个对象都有机会处理请求(形成链, 沿链传递), 从而使得发送者不需要指定接受者
 * 
 * 模式定义:
 *  使多个对象都有机会处理请求, 从而避免请求的发送者和接收者之间的耦合关系
 *  将这些对象连成一个单链表, 沿着单链表传递请求, 直到有一个对象处理它为止
 * 
 * 小结:
 * 1. 应用在一个请求可能有多个接收者, 但最后真正的接收者只有一个, 需要解开发送者和接收者之间的紧耦合
 * 2. 为对象的职责分配增添灵活性, 可以动态地修改和添加处理职责
 * 3. 如果传到链尾端仍得不到处理, 应有合理地缺省处理机制
 */