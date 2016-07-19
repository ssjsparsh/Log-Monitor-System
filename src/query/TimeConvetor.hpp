//
//  TimeConvetor.hpp
//  simulator
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#ifndef TimeConvetor_hpp
#define TimeConvetor_hpp

#include <stdio.h>
#include <string>
using namespace std;

class TimeConvetor{
public:
    //convert string to struct time
    struct tm string2time(const string datetime);
    //convert struct time to string
    string time2string(const struct tm tm);
    //convert unix timestamp to struct time
    struct tm unix2time(const time_t ts);
    //convert struct time to unix timestamp
    time_t time2unix(struct tm tm);
    //convert string to unix timestamp
    time_t string2unix(string datetime);
    //convert unixt timestamp to string
    string unix2string(time_t ts);
};
#endif /* TimeConvetor_hpp */
