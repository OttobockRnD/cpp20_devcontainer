#include <iostream>
#include <string>

#pragma once

class SensorTM {
    public:
        void readAndLogData() {
            int data = readData();
            data = processData(data);
            logData(data);
        }
        virtual ~SensorTM() = default;

    protected:
        virtual int readData() = 0;
        virtual int processData(int data) = 0;

    void logData(int data) {
        std::cout << "Sensor data: " << data << std::endl;
    }
};

class TemperatureSensorTM : public SensorTM {
    protected:
        int readData() override {
            return 22;
        }
        int processData(int data) override {
            return data;
        }
};