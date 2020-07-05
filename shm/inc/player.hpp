#pragma once

#include <memory>

#include "delegate.hpp"
#include "ship.hpp"

class Player : public Delegate {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); }
    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return availableSpace_; }
    size_t getSpeed() const { return this->ship_->getSpeed(); }
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    void payCrew(size_t money) override;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t getAvailableSpace() { return ship_->getAvailableSpace(); }
};
