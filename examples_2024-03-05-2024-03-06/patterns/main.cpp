#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "factory.hpp"
#include "template_factory.hpp"
#include "strategy.hpp"
#include "adapter.hpp"
#include "facade.hpp"
#include "template_method.hpp"
#include "observer.hpp"

void run(SensorCreator& creator) {
    auto sensor = creator.createSensor();
    sensor->read();
}

void runManual() {
    std::unique_ptr<Sensor> sensor = nullptr;
    std::string sensorType = "Temperature";

    if (sensorType == "Temperature") {
        sensor = std::make_unique<TemperatureSensor>();
    } else if (sensorType == "Pressure") {
        sensor = std::make_unique<PressureSensor>();
    }
    sensor->read();
}

void run(CommunicationProtocol& protocol) {
    std::vector<uint8_t> data = {0x01, 0x02, 0x03, 0x04};
    protocol.sendData(data);
}

void run(SensorTM& sensor) {
    sensor.readAndLogData();
}

int main(int argc, char const *argv[]) {
    //--------------------------------------------------------------------------------
    // runManual();

    // TemperatureSensorCreator c1;
    // PressureSensorCreator c2;

    // run(c1);
    // run(c2);
    //--------------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------------
    // SensorCreator creator;
    // auto sensor = creator.create(SensorType::Temperature);
    // sensor->read();
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    // DefaultCreator<TemperatureSensor> c1;
    // DefaultCreator<PressureSensor> c2;

    // run(c1);
    // run(c2);
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    // ADCDriver adc(std::make_unique<SingleShotSamplingStrategy>());
    // int value = adc.sample();
    // adc.setSamplingStrategy(std::make_unique<ContinuousSamplingStrategy>());
    // value = adc.sample();
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    // ExistingBinaryProtocol binaryProtocol;
    // run(binaryProtocol);
    // JSONToBinaryAdapter adapter;
    // run(adapter);
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    // CellularFacade cf {new ModuleA()};
    // cf.connect();
    //--------------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------------    
    // TemperatureSensorTM tempSensor;
    // run(tempSensor);
    //--------------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------------
    NewsPublisher publisher;
    publisher.subscribe(new NewsReceiver1());
    publisher.subscribe(new NewsReceiver2());

    publisher.publish("Breaking news!");
    //--------------------------------------------------------------------------------
    
    return 0;
}
