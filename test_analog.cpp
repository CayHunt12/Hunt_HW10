#include <iostream>
#include "AnalogIn.h"

/*
 * test_analog.cpp
  * This application tests the AnalogIn class by creating an instance,
   * retrieving the analog input number, and reading an ADC sample.
    *
     * Usage: ./test_analog
      * Example: ./test_analog
       */

       int main() {
          AnalogIn analog(0); // Instantiate with number 0

          std::cout << "Analog input number: " << analog.getNumber() << std::endl;

          int sample = analog.readAdcSample();
          if (sample != -1) {
          std::cout << "ADC sample value: " << sample << std::endl;
          } else {
          std::cerr << "Error reading ADC sample." << std::endl;
          }

          return 0;
       }                                            
