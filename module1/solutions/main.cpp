#include <iostream>

#include "cargo.hpp" 

int main() {
    Cargo beer;
    
    // operator test
    beer += 10;
    beer -= 5;
    if (beer != 1) {
        std::cout << "Not equal" << '\n';
    }
    if (beer == 5) {
        std::cout << "Equal" << '\n';
    }

    // setters & getters test
    beer.setName("zywiec");
    beer.setAmount(99);
    beer.setBasePrice(3);
    std::cout << beer.getName() << '\n';
    std::cout << beer.getAmount() << '\n';
    std::cout << beer.getBasePrice() << '\n';

    return 0;
}