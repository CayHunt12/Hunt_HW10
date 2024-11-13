#include "GPIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

MYGPIO::MYGPIO(int num) : number(num) {
    path = "/sys/class/gpio/gpio" + std::to_string(number) + "/";
        // Export GPIO if not already exported (assume this is done externally
        // or handled)
}

void MYGPIO::write(std::string path, std::string filename, std::string value) {
    std::ofstream file(path + filename);
        if (file.is_open()) {
                file << value;
                file.close();
        } else {
            throw std::runtime_error("Could not write to" + path + filename);
            }
}

void MYGPIO::write(std::string path, std::string filename, int value) {
    write(path, filename, std::to_string(value));
    }

std::string MYGPIO::read(std::string path, std::string filename) {
    std::ifstream file(path + filename);
        std::string value;
            if (file.is_open()) {
                    getline(file, value);
                    file.close();
      } else {
      throw std::runtime_error("Could not read from " + path + filename);
      }
      return value;
  }

  void MYGPIO::setDirection(int dir) {
      write(path, "direction", (dir == GPIO_DIRECTION_OUT) ? "out" : "in");
      }
  int MYGPIO::getDirection() {
      std::string dir = read(path, "direction");
          return (dir == "out") ? GPIO_DIRECTION_OUT : GPIO_DIRECTION_IN;
    }

  void MYGPIO::setValue(int val) {
      write(path, "value", val);
  }

  int MYGPIO::getValue() {
      std::string val = read(path, "value");
          return (val == "1") ? GPIO_VALUE_HIGH : GPIO_VALUE_LOW;
    }

  void MYGPIO::toggleOutput() {
      if (getDirection() == GPIO_DIRECTION_OUT) {
              setValue((getValue() == GPIO_VALUE_HIGH) ? GPIO_VALUE_LOW :
              GPIO_VALUE_HIGH);
          }
      }
      
MYGPIO::~MYGPIO() {
    // Optionally, unexport GPIO (handled outside to avoid unexpected behavior)
    }


