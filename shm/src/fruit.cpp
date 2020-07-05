#include "fruit.hpp"

size_t Fruit::getPrice() const {
  return static_cast<size_t>((static_cast<float>(timeToSpoilLeft_) /
                              static_cast<float>(timeToSpoil_)) *
                             static_cast<float>(basePrice_));
}

std::string Fruit::getName() const { return name_; }
size_t Fruit::getAmount() const { return amount_; }
size_t Fruit::getBasePrice() const { return basePrice_; }
size_t Fruit::getTimeToSpoil() const { return timeToSpoil_; }
size_t Fruit::getTimeToSpoilLeft() const { return timeToSpoilLeft_; }

Fruit &Fruit::operator--() {
  if (timeToSpoilLeft_ > 0) {
    --timeToSpoilLeft_;
  }
  return *this;
}
Fruit &Fruit::operator--(int) {
  Fruit &temp(*this);
  if (timeToSpoilLeft_ > 0) {
    operator--();
  }
  return temp;
}
bool Fruit::operator==(const Cargo &cargo) const {
  if (typeid(cargo) == typeid(Fruit)) {
    const Fruit *fruit = static_cast<const Fruit *>(&cargo);
    return name_ == fruit->getName() && amount_ == fruit->getAmount() &&
           basePrice_ == fruit->getBasePrice() &&
           timeToSpoil_ == fruit->getTimeToSpoil() &&
           timeToSpoilLeft_ == fruit->getTimeToSpoilLeft();
  }
  return false;
}
bool Fruit::operator!=(const Cargo &cargo) const {
  if (typeid(cargo) == typeid(Fruit)) {
    const Fruit *fruit = static_cast<const Fruit *>(&cargo);
    return !(this == fruit);
  }
  return false;
}
Cargo &Fruit::operator+=(size_t amount) {
  amount_ += amount;
  return *this;
}
Cargo &Fruit::operator-=(size_t amount) {
  if (amount <= amount_) {
    amount_ -= amount;
    return *this;
  }
  return *this;
}

void Fruit::nextDay() {
  if (timeToSpoilLeft_ > 0) {
    --timeToSpoilLeft_;
  }
  if (timeToSpoilLeft_ = 0) {
    amount_ = 0;
  }
}
