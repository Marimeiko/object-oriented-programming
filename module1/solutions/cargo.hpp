#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice)
        : name_(name)
        , amount_(amount)
        , basePrice_(basePrice)
    {}
    Cargo()
        : Cargo("", 0, 0)
    {}

    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount) {
        amount_ -= amount;
        return *this;
    }
    bool operator==(size_t amount) {
        return amount_ == amount;
    }
    bool operator!=(size_t amount) {
        return amount_ != amount;
    }

    void setName(std::string name) { name_ = name; }
    void setAmount(size_t amount) { amount_ = amount; }
    void setBasePrice(size_t basePrice) { basePrice_ = basePrice; }
    
    std::string getName() { return name_; }
    size_t getAmount() { return amount_; }
    size_t getBasePrice() { return basePrice_; }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
