#pragma once

#include <vector>

class Map {
  public:
    Map();            //c-tor
    virtual ~Map();   //d-tor

  private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
