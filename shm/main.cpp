#include <iostream>

#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "map.hpp"

void ItemClassTest();
void FruitClassTest();
void MapClassTest();

int main() {
    FruitClassTest();
    // ItemClassTest();

    return 0;
}

void FruitClassTest() {
    Fruit orange("orange", 3, 5, 10);
    Fruit apple("apple", 2, 5, 20);
    Fruit fruit("apple", 2, 5, 20); // name, amount, base price, time to spoil

    std::cout << "Name: " << apple.getName() << '\n';
    std::cout << "Amount: " << apple.getAmount() << '\n';
    std::cout << "Base price: " << apple.getBasePrice() << '\n';
    std::cout << "Price: " << apple.getPrice() << '\n';
    
    if (fruit == apple) {
        std::cout << "Apple is fruit" << '\n';
    }
    if (orange != apple) {
        std::cout << "Apple isn't orange" << '\n';
    }

    apple += 10;
    std::cout << "Amount inc: " << apple.getAmount() << '\n';
    apple -= 10;
    std::cout << "Amount dec: " << apple.getAmount() << '\n';
    
    --apple;
    apple--;
    std::cout << "Spoil: " << apple.getTimeToSpoilLeft() << '\n';
    std::cout << "Price: " << apple.getPrice() << "\n\n";
}

void ItemClassTest() {
    Item emerald("emerald", 2, 20, Item::Rarity::rare);
    Item diamond("diamond", 7, 40, Item::Rarity::epic);
    Item item("diamond", 7, 40, Item::Rarity::epic); // name, amount, price, rarity

    std::cout << "Name: " << diamond.getName() << '\n';
    std::cout << "Amount: " << diamond.getAmount() << '\n';
    std::cout << "Base price: " << diamond.getBasePrice() << '\n';
    std::cout << "Price: " << diamond.getPrice() << '\n';
    std::cout << "Base price: " << emerald.getBasePrice() << '\n';
    std::cout << "Price: " << emerald.getPrice() << '\n';
    
    if (item == diamond) {
        std::cout << "Diamond is item" << '\n';
    }
    if (emerald != diamond) {
        std::cout << "Diamond isn't emerald" << '\n';
    }

    diamond += 10;
    std::cout << "Amount inc: " << diamond.getAmount() << '\n';
    diamond -= 10;
    std::cout << "Amount dec: " << diamond.getAmount() << "\n\n";
}
