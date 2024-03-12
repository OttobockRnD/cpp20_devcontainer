#include <memory>
#include "sensor.hpp"

#pragma once

enum class SensorType {
    Temperature,
    Pressure,
};

class SensorCreator {
    public:
        virtual std::unique_ptr<Sensor> createSensor() { return nullptr; };
        virtual ~SensorCreator() = default;
        std::unique_ptr<Sensor> create() {
            return createSensor();
        }
        virtual std::unique_ptr<Sensor> create(SensorType type) {
            switch (type) {
                case SensorType::Temperature:
                    return std::make_unique<TemperatureSensor>();
                case SensorType::Pressure:
                    return std::make_unique<PressureSensor>();
                default:
                    return nullptr;
            }
        }
};

class TemperatureSensorCreator : public SensorCreator {
    public:
        std::unique_ptr<Sensor> createSensor() override {
            return std::make_unique<TemperatureSensor>();
        }
};

class PressureSensorCreator : public SensorCreator {
    public:
        std::unique_ptr<Sensor> createSensor() override {
            return std::make_unique<PressureSensor>();
        }
};