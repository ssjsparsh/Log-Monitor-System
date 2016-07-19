//
//  simulator.cpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include "simulator.hpp"

vector<int> simulator::generateIplist(){
    vector<int> res;
    int startval = iC.ip2int(_startIp);
    for(int i = 0; i < _numofserver; i++){
        res.push_back(startval + i);
    }
    return res;
}

simulator::simulator(string startIp, string startDatetime, string endDatetime, string dataPath, int numofserver, int numofcpu):_startIp(startIp), _startDatetime(startDatetime), _endDatetime(endDatetime), _dataPath(dataPath), _numofserver(numofserver),_numofcpu(numofcpu){};

void simulator::generateLog(){
    //time convert
    time_t startTime = tC.string2unix(_startDatetime);
    time_t endTime = tC.time2unix(tC.string2time(_endDatetime));

    //file operation
    ofstream outfile;
    outfile.open(_dataPath);
    
    //ip generation
    vector<int> iplist = generateIplist();
    
    //write records into file
    for(auto it = startTime; it <= endTime; it += 60){
        for(int ip : iplist){
            string ipaddress = iC.int2ip(ip);
            for(int i = 0; i < _numofcpu; i++){
                string data = to_string(it) + " ";
                data += ipaddress + " ";
                data += to_string(i) + " ";
                data += to_string(random()%100);
                outfile<< data << endl;
            }
        }
    }
    //close file
    outfile.close();
}