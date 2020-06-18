#include "cargo.hpp"

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
