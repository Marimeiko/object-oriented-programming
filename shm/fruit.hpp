#pragma once

#include <string>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string name, size_t amount, size_t basePrice, size_t timeToSpoil)
            : Cargo(name, amount, basePrice)
            , timeToSpoil_(timeToSpoil)
    {}
    
    Fruit& operator--();
    Fruit& operator--(int);
    bool operator==(const Cargo& fruit) const;
    bool operator!=(const Cargo& fruit) const;
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getTimeToSpoil() const;
    size_t getTimeToSpoilLeft() const;

private:
    const size_t timeToSpoil_;
    size_t timeToSpoilLeft_ = timeToSpoil_;
};
