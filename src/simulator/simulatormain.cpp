//
//  main.cpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <random>
#include "IpConvertor.hpp"
#include "TimeConvetor.hpp"
#include "simulator.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc <= 1){
        cout<<"Please add DATAPATH!"<<endl;
        cout<<"e.g: \"bash generate.sh log.txt\" "<<endl;
    }
    else if(argc > 2){
        cout<<"Please use correct DATAPATH!"<<endl;
        cout<<"e.g: \"bash generate.sh log.txt\" "<<endl;
    }
    else{
        string datapath = argv[1];
        simulator sC("192.168.1.1", "2014-10-31 00:00", "2014-10-31 23:59", datapath, 1000, 2);
        sC.generateLog();
    }
    return 0;
}
