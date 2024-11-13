#include "LED.h"
#include <iostream>
#include <fstream>

void LED::turnOn() {
    std::cout << "Turning the LED on\n";
    removeTrigger();
    writeLED("/brightness", "1");
}

void LED::turnOff() {
    std::cout << "Turning the LED off\n";
    removeTrigger();
    writeLED("/brightness", "0");
  }

void LED::flash() {
    std::cout << "Flashing the LED\n";
    writeLED("/trigger", "timer");
    writeLED("/delay_on", "50");
    writeLED("/delay_off", "50");
  }

void LED::getStatus() {
    std::cout << "Checking LED status\n";
    std::ifstream fs(LED_PATH + "/trigger");
    std::string line;
    while (std::getline(fs, line)) {
        std::cout << line << std::endl;
      }
      fs.close();
   }

   void LED::writeLED(const std::string& filename, const std::string& value) {
   std::ofstream fs(LED_PATH + filename);
   fs << value;
   fs.close();
}

void LED::removeTrigger() {
    writeLED("/trigger", "none");
}    

