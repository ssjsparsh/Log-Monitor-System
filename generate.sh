#!/bin/bash


file_name="simulatormain.cpp"
out_name="simulatormain"
source="./src/simulator/"
# Compile the program with -o option to specify the name of the binary
g++ -std=c++11 $source$file_name ./src/simulator/simulator.cpp ./src/simulator/IpConvertor.cpp ./src/simulator/TimeConvetor.cpp -o ./bin/$out_name

# If there were no compilation errors, run the program
if [[ $? -eq 0 ]]; then
        ./bin/$out_name $1
fi