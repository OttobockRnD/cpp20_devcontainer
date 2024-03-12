#include <iostream>

#pragma once

template <typename Derived>
class SensorBase {
    public:
        void initialize() {
            static_cast<Derived*>(this)->initImpl();
        }

        double read() {
            return static_cast<Derived*>(this)->readImpl();
        }
};

class TempSensor : public SensorBase<TempSensor> {
    friend class SensorBase<TempSensor>;
    private:
        void initImpl() {
            std::cout << "TempSensor init" << std::endl;
        }

        double readImpl() {
            return 25.3;
        }
};

class HumSensor : public SensorBase<HumSensor> {
    friend class SensorBase<HumSensor>;
    private:
        void initImpl() {
            std::cout << "HumSensor init" << std::endl;
        }

        double readImpl() {
            return 55.5;
        }
};