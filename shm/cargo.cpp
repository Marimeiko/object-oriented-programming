#include "cargo.hpp"

Cargo::Cargo()
    : Cargo("", 0, 0)
{}
Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}

bool Cargo::operator==(Cargo& cargo) {
    return (name_ == cargo.name_) &&
           (amount_ == cargo.amount_) &&
           (basePrice_ == cargo.basePrice_);
}
bool Cargo::operator!=(Cargo& cargo) {
    return (name_ != cargo.name_) ||
           (amount_ != cargo.amount_) ||
           (basePrice_ != cargo.basePrice_);
}
Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

std::string Cargo::getName() { return name_; }
size_t Cargo::getAmount() { return amount_; }
size_t Cargo::getBasePrice() { return basePrice_; }

void Cargo::setName(std::string name) { name_ = name; }
void Cargo::setAmount(size_t amount) { amount_ = amount; }
void Cargo::setBasePrice(size_t basePrice) { basePrice_ = basePrice; }
