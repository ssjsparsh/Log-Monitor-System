//
//  IpConvertor.cpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include "IpConvertor.hpp"
#include <sstream>

IpConvertor::IpConvertor(){};

vector<string> IpConvertor::split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int IpConvertor::ip2int(string ip){
    int res = 0;
    vector<string> ips = split(ip, '.');
    for(string s : ips){
        res = res * 256 + stoi(s);
    }
    return res;
}

string IpConvertor::int2ip(int ip){
    string res;
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;
    res = to_string(bytes[3]) + "." + to_string(bytes[2]) + "." + to_string(bytes[1]) + "." + to_string(bytes[0]);
    return res;
}

bool IpConvertor::ipvalidate(string ip){
    vector<string> ips = split(ip, '.');
    if(ips.size() != 4) return false;
    for(string s : ips){
        int ipnum = stoi(s);
        if(ipnum < 0 || ipnum > 255) return false;
    }
    return true;
}
