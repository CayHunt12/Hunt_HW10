#ifndef MYGPIO_H
#define MYGPIO_H

#include <iostream>
#include <fstream>
#include <string>

#define GPIO_DIRECTION_IN 0
#define GPIO_DIRECTION_OUT 1

#define GPIO_VALUE_LOW 0
#define GPIO_VALUE_HIGH 1

class MYGPIO {
private:
    int number;
    std::string name, path;
    std::ofstream stream;

    void write(std::string path, std::string filename, std::string value);
    void write(std::string path, std::string filename, int value);
    std::string read(std::string path, std::string filename);

    public:
    MYGPIO(int number); // Constructor
    int getNumber();
    void setDirection(int dir);
    int getDirection();
    void setValue(int val);
    int getValue();
    void toggleOutput();
    ~MYGPIO(); // Destructor
    };

    #endif // MYGPIO_H

