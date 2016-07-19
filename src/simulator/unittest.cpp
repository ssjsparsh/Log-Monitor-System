//
//  unittest.cpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include "unittest.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include "TimeConvetor.hpp"
#include "IpConvertor.hpp"
using namespace std;

class TimeConvetorUnitTest{
private:
    string _startDatetime;
    string _endDatetime;
    TimeConvetor tC;
public:
    TimeConvetorUnitTest(string starttime, string endtime){
        _startDatetime = starttime;
        _endDatetime = endtime;
    }
    void test(){
        time_t startTime = tC.time2unix(tC.string2time(_startDatetime));
        cout<< startTime <<endl;
        cout<< tC.time2string(tC.unix2time(startTime)) << endl;
        startTime = tC.string2unix(_startDatetime);
        cout<< startTime <<endl;
        cout<< tC.unix2string(startTime) << endl;
        time_t endTime = tC.time2unix(tC.string2time(_endDatetime));
        cout<< endTime<<endl;
        cout<< tC.unix2string(endTime) << endl;
    }
};
/*
 IpConvertor iC;
 int res = iC.ip2int("2.2.2.6");
 cout<< res <<endl;
 res++;
 cout<< iC.int2ip(res) << endl;
 
 TimeConvetorUnitTest tcu("2014-10-31 00:00", "2014-10-31 23:59");
 tcu.test();
 
 //test case for timeconvertor
 TimeConvetor tC;
 
 string datetime = "2014-10-31 00:01";
 //cout<< tC.string2unix(datetime)<<endl;
 //cout<< tC.unix2string(tC.string2unix(datetime))<<endl;
 auto tm = tC.string2time(datetime);
 //tm.tm_min++;
 cout<< tC.time2unix(tC.string2time(datetime))<<endl;
 cout<< tC.time2string(tC.unix2time(tC.time2unix(tC.string2time(datetime))))<<endl;
 tm.tm_min++;
 cout<< tC.time2unix(tm)<<endl;
 cout<< tC.time2string(tC.unix2time(tC.time2unix(tm)))<<endl;
 
 
 time_t startTime = tC.time2unix(tC.string2time("2014-10-31 00:00"));
 cout<< startTime <<endl;
 time_t endTime = tC.time2unix(tC.string2time("2014-10-31 23:59"));
 cout<< endTime<<endl;
 */
