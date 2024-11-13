echo "Building the AnalogIn application..."
g++ -o test_analog test_analog.cpp AnalogIn.cpp
if [ $? -eq 0 ]; then
echo "Build successful. Run the application using ./test_analog"
else
echo "Build failed."
fi
