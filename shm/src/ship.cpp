#include "ship.hpp"

#include <numeric>

Ship::Ship(int maxCrew, int speed, size_t id, Time* time, Delegate* delegate)
    : Ship(0, maxCrew, speed, "", id, time, delegate)
{}
Ship::Ship(int capacity, int maxCrew, int speed,
        const std::string& name, size_t id, Time* time, Delegate* delegate)
    : capacity_(capacity)
    , maxCrew_(maxCrew) 
    , crew_(0)
    , speed_(speed)
    , name_(name)
    , id_(id)
    , time_(time)
    , delegate_(delegate)
{
    time_->addObserver(this);
}
Ship::~Ship() {
    time_->removeObserver(this);
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew <= crew_) {
        crew_ -= crew;
        return *this;
    }
    return *this;
}
Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
        return *this;
    }
    return *this;
}

void Ship::setName(const std::string& name) { name_ = name; }
void Ship::setDelegate(Delegate* delegate) { 
    delegate_ = delegate; }

size_t Ship::getCapacity() const { return capacity_; }
size_t Ship::getMaxCrew() const { return maxCrew_; }
size_t Ship::getCrew() const { return crew_; }
size_t Ship::getSpeed() const { return speed_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getId() const { return id_; }

std::shared_ptr<Cargo> Ship::getCargo(const size_t index) {
    if (index >= cargo_.size()) {
        return nullptr;
    }
    return cargo_[index];
}
size_t Ship::getAvailableSpace() const {
    size_t occupied = std::accumulate(cargo_.begin(),
                                      cargo_.end(),
                                      0,
                                      [](size_t sum, const auto& cargo) {
                                          return sum += cargo->getAmount();
                                      });
    return capacity_ - occupied;
}
void Ship::nextDay() {
    if (delegate_) {
        delegate_->payCrew(crew_);
    }
}
