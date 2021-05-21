#pragma once
#include "Context.hpp"
#include "State_A.hpp"
#include "State_B.hpp"


void clientCode() {
    Context* context = new Context(new State_A);
    context->request1();
    context->request2();

    delete context;
}