#include <iostream>
#include "clientCode.hpp"


int main(int, char**) {
    std::array<const IComponent *, 2> components = {new ConcreteComponentA, new ConcreteComponentB};
    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
    clientCode(components, visitor1);
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
    clientCode(components, visitor2);

    for (const IComponent* comp : components) 
        delete comp;
    
    delete visitor1;
    delete visitor2;

    return 0;
}
