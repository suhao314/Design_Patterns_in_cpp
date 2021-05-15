#include "SquirrelHandler.hpp"
#include "MonkeyHandler.hpp"
#include "ClientCode.hpp"


int main() {
  MonkeyHandler *monkey = new MonkeyHandler;
  SquirrelHandler *squirrel = new SquirrelHandler;
  DogHandler *dog = new DogHandler;
  monkey->SetNext(squirrel)->SetNext(dog);

  /**
   * The client should be able to send a request to any handler, not just the
   * first one in the chain.
   */
  std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
  ClientCode(*monkey);
  std::cout << "\n";
  std::cout << "Subchain: Squirrel > Dog\n\n";
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
 */