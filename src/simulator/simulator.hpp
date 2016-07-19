//
//  simulator.hpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#ifndef simulator_hpp
#define simulator_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <random>
#include "IpConvertor.hpp"
#include "TimeConvetor.hpp"

class simulator{
private:
    string _startIp;
    string _startDatetime;
    string _endDatetime;
    string _dataPath;
    int _numofserver = 1000;
    int _numofcpu = 2;
    IpConvertor iC;
    TimeConvetor tC;
    vector<int> generateIplist();
public:
    simulator(string startIp, string startDatetime, string endDatetime, string dataPath, int numofserver, int numofcpu);
    
    void generateLog();
};

#endif /* simulator_hpp */
