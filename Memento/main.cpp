#include <iostream>
#include "clientCode.hpp"

int main(int, char**) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    clientCode();
}
