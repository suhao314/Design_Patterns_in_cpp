#include <iostream>
#include "clientCode.hpp"

int main(int, char**) {
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass1 *concreteClass1 = new ConcreteClass1;
    clientCode(concreteClass1);
    std::cout << "\n";
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass2 *concreteClass2 = new ConcreteClass2;
    clientCode(concreteClass2);
    
    delete concreteClass1;
    delete concreteClass2;
    
    return 0;
}
