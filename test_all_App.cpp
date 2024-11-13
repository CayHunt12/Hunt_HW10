/**
*test_all_App.cpp
* An application that demonstrates the usage of LED, GPIO, and AnalogIn classes.
* 
* This program turns on user LEDs 1 and 3, flashes user LED 2, reads the temperature  sensor value, reads a push button on P8.16, and turns on an LED on P9.12  if the button is pressed.
* 
* Command-line arguments: None.
* Example invocation: ./test_all_App
/

#include <iostream>
#include "LED.h"     // Include LED class (from Molloy’s textbook)
#include "GPIO.h"    // Include GPIO class (from Molloy’s textbook)
#include "AnalogIn.h" // Include user-defined AnalogIn class

int main() {
    // Control user LEDs 1 and 3
        LED led1(1);
        LED led3(3);
        led1.turnOn();
        led3.turnOn();

        LED led2(2);
        led2.flash(2);

        AnalogIn tempSensor(0)
        int tempValue = tempSensor.readAdcSample();
        if (tempValue != -1) {
          std::cout << "Temperature sensor value: " << tempValue << std::endl;
        }


        GPIO button("45");
        button.setDirection(GPIO::INPUT);
        int buttonState = button.getValue();

        GPIO ledP912("60");
        ledP912.setDirection(GPIO::OUTPUT);

        if (buttonState == 1) {
          std::cout << "Button pressed, turning on LED" << std::endl;
          ledP912.setValue(GPIO::HIGH);
        }else{
          std::cout << "Button is not Pressed" << std::endl;
        }

    return 0;

 }   
