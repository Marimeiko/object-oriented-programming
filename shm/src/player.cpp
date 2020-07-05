#include "player.hpp"

Player::Player(Ship& ship, size_t money, size_t availableSpace)
    : money_(money)
    , availableSpace_(availableSpace) {
    ship_ = std::make_unique<Ship>(ship);
    ship_->setDelegate(this);
}

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index); 
}

void Player::payCrew(size_t money) {
    if (money_ > money) {
        money_ -= money;
    } else {
        money_ = 0;
    }
}
