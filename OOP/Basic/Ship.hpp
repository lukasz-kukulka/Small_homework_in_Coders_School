#pragma once

#include <string>
class Ship {

public:
    uint8_t getId() const { return id_; };
    std::string getName() const& { return name_; };
    uint8_t getSpeed() const { return speed_; };
    uint8_t getMaxCrew() const { return maxCrew_; };
    uint8_t getCapacity() const { return capacity_; };
private:
    uint8_t id_ { };
    std::string name_ { };
    uint8_t speed_ { 50 };
    const uint8_t maxCrew_ { 100 };
    const uint8_t capacity_ { 80 };
};


