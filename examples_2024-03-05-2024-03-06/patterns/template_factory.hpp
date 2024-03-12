#include <memory>
#include "sensor.hpp"
#include "factory.hpp"

// class TSensorCreator {
//     public:
//         virtual std::unique_ptr<Sensor> createSensor() = 0;
// };

template<typename T>
class DefaultCreator: public SensorCreator {
    public:
        std::unique_ptr<Sensor> createSensor() override {
            return std::make_unique<T>();
        }
};