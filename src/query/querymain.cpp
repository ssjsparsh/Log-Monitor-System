//
//  main.cpp
//  query
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include <iostream>
#include "IpConvertor.hpp"
#include "TimeConvetor.hpp"
#include "query.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc <= 1){
        cout<<"Please add DATAPATH!"<<endl;
        cout<<"e.g: \"bash query.sh log.txt\" "<<endl;
    }
    else if(argc > 2){
        cout<<"Please use correct DATAPATH!"<<endl;
        cout<<"e.g: \"bash query.sh log.txt\" "<<endl;
    }
    else{
        IpConvertor iC;
        string datapath = argv[1];
        query q(datapath);
        
        if(!q.init()){
            cout<<"Loading Failed!"<<endl;
            return 0;
        }
        
        string line;
        cout<<">";
        while(getline(cin, line)){
            if(line == "EXIT" || line == "exit") return 0;
            
            vector<string> parts = iC.split(line, ' ');
            if(parts.size() != 7 || !(parts[0] == "QUERY" || parts[0] == "query") ) {
                cout<<"Please enter right format!"<<endl;
                cout<<"E.g QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05"<<endl;
                cout<<">";
                continue;
            }
            string ipaddress = parts[1];
            string serverid = parts[2];
            string starttime = parts[3] + " " + parts[4];
            string endtime= parts[5] + " " + parts[6];
            if(!q.check(ipaddress, serverid, starttime, endtime)){
                cout<<"Please enter right format!"<<endl;
                cout<<"E.g QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05"<<endl;
                cout<<">";
                continue;
            }
            cout<<"CPU" + serverid + " usage on " + ipaddress + ":"<<endl;
            q.search(ipaddress, serverid, starttime, endtime);
            cout<<">";
        }
    }
    return 0;
}
