#pragma once

#include <string>

class Cargo {
public:
    bool operator==(Cargo& cargo);
    bool operator!=(Cargo& cargo);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
