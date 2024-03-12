#include <iostream>

#pragma once

class AbstractSensor {
public:
    virtual void initialize() = 0;
    virtual double read() = 0;
    virtual ~AbstractSensor() = default;
};

template <typename Derived>
class Sensor : public AbstractSensor {
    public:
        void initialize() override {
            static_cast<Derived*>(this)->initImpl();
        }

        double read() override {
            return static_cast<Derived*>(this)->readImpl();
        }
    protected:
        Sensor() = default;
        Sensor(const Sensor&) = default;
        Sensor(Sensor&&) = default;
};

class TemperatureSensor : public Sensor<TemperatureSensor> {
    friend class Sensor<TemperatureSensor>;
    private:
        void initImpl() {
            std::cout << "TemperaturSensor init" << std::endl;
        }

        double readImpl() {
            return 25.3;
        }
};

class HumiditySensor : public Sensor<HumiditySensor> {
    friend class Sensor<HumiditySensor>;
    private:
        void initImpl() {
            std::cout << "HumiditySensor init" << std::endl;
        }

        double readImpl() {
            return 55.5;
        }
};