
#include <string>

class LED {
private:
    const std::string LED_PATH = "/sys/class/leds/beaglebone:green:usr3";
    void writeLED(const std::string& filename, const std::string& value);
    void removeTrigger();

public:
    LED() = default;
        void turnOn();
        void turnOff();
        void flash();
        void getStatus();
};        
