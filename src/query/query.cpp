//
//  query.cpp
//  query
//
//  Created by Zeqiang Wang on 7/18/16.
//  Copyright © 2016 Zeqiang Wang. All rights reserved.
//

#include "query.hpp"
#include <fstream>
#include <sstream>


record::record(int x, int y){
    timestamp = x;
    usage = y;
}

query::query(){};

query::query(string datapath):_datapath(datapath){}

bool query::init(){
    ifstream infile;
    infile.open(_datapath);
    if(!infile){
        cout<<"Can not open file!"<<endl;
        return false;
    }
    string line;
    cout<<"Loading..."<<endl;
    while(getline(infile, line)){
        
        vector<string> parts = iC.split(line, ' ');
        if(parts.size() < 4) continue;
        
        int timestamp = stoi(parts[0]);
        int ip = iC.ip2int(parts[1]);
        int serverid = stoi(parts[2]);
        int usage = stoi(parts[3]);
        
        /*
         istringstream in(line);
        if(!(in >> timestamp >> ip >> serverid >> usage)) break;
         */
        if(ipdict.find(ip) == ipdict.end()){
            ipdict[ip] = vector<vector<record>>(2, vector<record>());
        }
        record r(timestamp, usage);
        ipdict[ip][serverid].push_back(r);
        //cout<<timestamp << " "<< ip << " " << serverid <<" "<< usage<<endl;
    }
    
    /*
     //if input file is unsorted, we need add sorting after import data, It takes O(nlogn) time
    for(auto it = ipdict.begin(); it != ipdict.end(); it++){
        for(int i = 0; i < 2; i++){
            sort(it->second[i].begin(), it->second[i].end());
        }
    }

     */
    infile.close();
    cout<<"Done!"<<endl;
    return true;
}

void query::search(string ipaddress, string serverid, string starttime, string endtime){
    time_t unixStarttime = tC.string2unix(starttime);
    time_t unixEndtime = tC.string2unix(endtime);
    int ip = iC.ip2int(ipaddress);
    
    if(ipdict.find(ip) == ipdict.end()){
        cout<<"Ip not Found!"<<endl;
        return;
    }
    
    int servernum = stoi(serverid);
    long startIdx = findUnixTimestamp(ipdict[ip][servernum], unixStarttime);
    long endIdx = findUnixTimestamp(ipdict[ip][servernum], unixEndtime);
    
    string res;
    for(long i = startIdx; i < endIdx; i++){
        res += "(" + tC.unix2string(ipdict[ip][servernum][i].timestamp) +","+ to_string(ipdict[ip][servernum][i].usage) + "%)" + (i == endIdx - 1 ? "" : ",");
    }
    cout<<res<<endl;
}

long query::findUnixTimestamp(vector<record> &records, time_t timestamp){
    long start = 0, end = records.size() - 1;
    while(start <= end){
        long mid = start + (end - start) / 2;
        if(records[mid].timestamp == timestamp) return mid;
        else if(records[mid].timestamp < timestamp){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start;
}

bool query::check(string ipaddress, string serverid, string starttime, string endtime){
    if(!iC.ipvalidate(ipaddress)){
        cout<<"Invalid IP!"<<endl;
        return false;
    }
    if(stoi(serverid) < 0 || stoi(serverid) > 1){
        cout<<"Invalid CPU number!"<<endl;
        return false;
    }
    return true;
}

