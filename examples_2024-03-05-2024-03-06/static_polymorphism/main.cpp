#include <iostream>
#include "crtp_simple.hpp"
#include "crtp_with_abstract_base.hpp"

void run(AbstractSensor& sensor) {
    sensor.initialize();
    std::cout << sensor.read() << std::endl;
}

int main(int argc, char const *argv[]) {
    //--------------------------------------------------------------------------------
    TempSensor s;
    HumSensor h;
    std::cout << s.read() << std::endl;
    std::cout << h.read() << std::endl;

    //--------------------------------------------------------------------------------
    TemperatureSensor ts;
    HumiditySensor hs;

    run(ts);
    run(hs);
    //--------------------------------------------------------------------------------

    return 0;
}
