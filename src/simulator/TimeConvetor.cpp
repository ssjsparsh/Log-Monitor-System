//
//  TimeConvetor.cpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include "TimeConvetor.hpp"

struct tm TimeConvetor::string2time(const string datetime){
    struct tm tm = {0};
    strptime(datetime.c_str(), "%F %R", &tm);
    return tm;
}
string TimeConvetor::time2string(const struct tm tm){
    char buff[20];
    /* Format and print the time, "yyyy-mm-dd hh:mm" */
    strftime(buff,sizeof(buff), "%F %R", &tm);
    return buff;
}

struct tm TimeConvetor::unix2time(const time_t ts){
    struct tm* tm = gmtime(&ts);
    return *tm;
}
time_t TimeConvetor::time2unix(struct tm tm){
    time_t ts;
    ts = timegm(&tm);
    return ts;
}

time_t TimeConvetor::string2unix(string datetime){
    struct tm tm = {0};
    time_t ts;
    strptime(datetime.c_str(), "%F %R", &tm);
    ts = timegm(&tm);
    return ts;
}
string TimeConvetor::unix2string(time_t ts){
    struct tm *tm = gmtime(&ts);
    char buff[20];
    /* Format and print the time, "yyyy-mm-dd hh:mm" */
    strftime(buff,sizeof(buff), "%F %R", tm);
    return buff;
}