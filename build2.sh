#configure the pins
echo "45" > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio45/value

echo "60" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio60/value

#Build script for compiling test_all_App

g++ -o test_all_App test_all_App.cpp AnalogIn.cpp LED.cpp GPIO.cpp

if [ $? -eq 0 ]; then
    echo "Build successful. Run ./test_all_App to execute."
    else
        echo "Build failed."
        fi
