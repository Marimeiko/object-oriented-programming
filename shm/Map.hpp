#pragma once

#include <vector>

class Map {
  public:
    Map();            //c-tor
    virtual ~Map();   //d-tor
    void printMap();  //tmp f-cton for printing $vectorOfIslands_ content;

  private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
