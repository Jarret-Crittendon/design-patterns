// Author: Jarret Crittendon
// Date: 2023 JAN 06
// Challenge: Use the adapter pattern to adapt a Drone class to
// the Duck class.

#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include "Duck.hpp"

class Drone {
public:
    void beep() const {
        std::cout << "The drone beeps incessantly.\n";
    }

    void spin_rotors() const {
        std::cout << "Rotors are spinning.\n";
    }

    void take_off() const {
        std::cout << "The drone takes off into the air.\n";
    }
};

class DroneAdapter : public Duck {
public:
    explicit DroneAdapter(const Drone& dr):
        Duck(), drone(dr) { }
    virtual void perform_fly() const override;
    virtual void perform_quack() const override;
    virtual void swim() const override;
    virtual void display() const override;

private:
    Drone drone;
};

void DroneAdapter::perform_fly() const {
    drone.spin_rotors();
    drone.take_off();
}

void DroneAdapter::perform_quack() const {
    drone.beep();
}

void DroneAdapter::swim() const {
    std::cout << "The drone does not swim.\n";
}

void DroneAdapter::display() const {
    std::cout << "A sleek, state-of-the-art drone.\n";
}


#endif