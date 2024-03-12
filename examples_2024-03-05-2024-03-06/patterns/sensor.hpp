#include <iostream>

#pragma once

class Sensor {
    public:
        virtual double read() = 0;
        virtual ~Sensor() = default;
};

class TemperatureSensor : public Sensor {
    public:
        double read() override {
            std::cout << "Reading temperature sensor..." << std::endl;
            return 3.14;
        }
};

class PressureSensor : public Sensor {
    public:
        double read() override {
            std::cout << "Reading pressure sensor..." << std::endl;
            return 2.71;
        }
};