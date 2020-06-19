#include "Map.hpp"

#include <algorithm>
#include <iostream>
#include <random>

//Tmp implementation. The Proper one depends on Island class implementation.

Island generateRandomCoordinate(const int& lowerBound, const int& upperBound) {
    std::random_device randDevice;
    std::mt19937 gen(randDevice());
    std::uniform_int_distribution<> distrib(lowerBound, upperBound);
    Island tmpIsland;
    tmpIsland.positionX = distrib(gen);
    tmpIsland.positionY = distrib(gen);
    return (tmpIsland);
}

Map::Map() {
    constexpr size_t INITIAL_ISLAND_NUM = 10;
    size_t counter = 0;

    while (counter != INITIAL_ISLAND_NUM) {
        Island tmpIsland = generateRandomCoordinate(-100, 100);
        std::vector<Island>::iterator it = std::find_if(vectorOfIslands_.begin(), vectorOfIslands_.end(),
                                                        [tmpIsland](const Island& island) -> bool { return ((island.positionX == tmpIsland.positionX) && (island.positionY == tmpIsland.positionY)); });
        if (it == vectorOfIslands_.end()) {
            vectorOfIslands_.push_back(tmpIsland);
            counter++;
        }
    }
}

Map::~Map() {}

void Map::printMap() {
    std::cout << "\nNumber of Islands: " << vectorOfIslands_.size() << "\n";
    for (const auto& el : vectorOfIslands_) {
        std::cout << "Coordinate (X, Y): "
                  << "(" << el.positionX << ", " << el.positionY << ")\n";
    }
}