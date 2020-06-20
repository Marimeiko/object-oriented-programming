#pragma once

#include <vector>

constexpr size_t INITIAL_ISLAND_NUM = 10;
constexpr int SQUARE_MAP_SIZE = 100;

class Map {
  public:
    Map();            //c-tor
    virtual ~Map();   //d-tor
    void printMap();  //tmp f-cton for printing $vectorOfIslands_ content;

  private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
