#include <iostream>

#include "single_for/for_generator.hpp"

int main() {
    for(auto [i]     : gtd::for_generator(4)) {
        std::print(std::cout,"{}\t", i);
    }
    std::cout << std::endl;
    for(auto [i,j]   : gtd::for_generator(3,3)) {
        std::print(std::cout,"{} {}\t", i, j);
    }
    std::cout << std::endl;
    for(auto [i,j,k] : gtd::for_generator(2,2,2)) {
        std::print(std::cout,"{} {} {}\t", i, j, k);
    }
    std::cout << std::endl;
    return 0;
}