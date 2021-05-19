#include <iostream>
#include "Integers.hpp"


int main(int, char**) {
    Integers integers;
    for (auto i : integers)
        std::cout << i << " "; 
    std::cout<<std::endl;
    
    for (auto it = integers.begin(), end = integers.end(); it != end; ++it) { 
        const auto i = *it; 
        std::cout << i << " ";
    }
    std::cout<<std::endl;

    std::fill(integers.begin(), integers.end(), 3);

    for (auto it = integers.begin(), end = integers.end(); it != end; ++it) { 
        const auto i = *it; 
        std::cout << i << " ";
    }
    std::cout<<std::endl;

    return 0;
}
