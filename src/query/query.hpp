//
//  query.hpp
//  query
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#ifndef query_hpp
#define query_hpp

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include "TimeConvetor.hpp"
#include "IpConvertor.hpp"
using namespace std;

struct record{
    int timestamp;
    int usage;
    record(int x, int y);
};

class query{
private:
    /*
     ipdict: hashmap mapping ip -> CPUs -> records
     
     key: ip value: CPU0's records and CPU1's records
     
     */
    unordered_map<int, vector<vector<record> >  >  ipdict;
    string _datapath;
    IpConvertor iC;
    TimeConvetor tC;
public:
    query();
    query(string datapath);
    bool init();//init:read file into ipdict;
    void search(string ipaddress, string serverid, string starttime, string endtime); //search: find set of records and display
    long findUnixTimestamp(vector<record>& records, time_t timestamp);//binary search to find timestamp
    bool check(string ipaddress, string serverid, string starttime, string endtime);//validate input string
};
#endif /* query_hpp */
