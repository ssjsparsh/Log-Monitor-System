//
//  IpConvertor.hpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#ifndef IpConvertor_hpp
#define IpConvertor_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class IpConvertor{
public:
    IpConvertor();
    //convert string ip to int val
    int ip2int(string ip);
    //convert int val to string ip
    string int2ip(int ip);
    //split function
    vector<string> split(const string &s, char delim);
    //validate input ip string
    bool ipvalidate(string ip);
};
#endif /* IpConvertor_hpp */
