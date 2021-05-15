#pragma once
#include "IHandler.hpp"

class AbstractHandler : public Handler {
  /**
   * @var Handler
   */
private:
    /* keypoint: 多态链表 */
    Handler *next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {}
    Handler *SetNext(Handler *handler) override {
        this->next_handler_ = handler;
        // Returning a handler from here will let us link handlers in a convenient
        // way like this:
        // $monkey->setNext($squirrel)->setNext($dog);
        return handler;
    }
    std::string Handle(std::string request) override {
        /* 如果多态链表有后继: 让后继处理 */
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }

        return {};
  }
};