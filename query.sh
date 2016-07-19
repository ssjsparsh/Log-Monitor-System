#!/bin/bash


file_name="querymain.cpp"
out_name="querymain"
source="./src/query/"
# Compile the program with -o option to specify the name of the binary
g++ -std=c++11 $source$file_name ./src/query/query.cpp ./src/query/IpConvertor.cpp ./src/query/TimeConvetor.cpp -o ./bin/$out_name

# If there were no compilation errors, run the program
if [[ $? -eq 0 ]]; then
        ./bin/$out_name $1
fi