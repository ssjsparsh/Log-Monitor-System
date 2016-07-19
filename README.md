# Log-Monitor-System

A monitoring system, which monitors 1000 servers. Each server has 2 CPUs. Each server generates a log for CPU usage every minute.

Jobs:

  1,Generate mock log file,

  2,Query a period time's CPU usage on ip address

## System Description

This system has two parts: log file generator, log file query 

Shared Library:
These two parts share two libraries: IpConvertor and TimeConvertor
  
    IpConvertor:
      1,convert string ip to int value
      int ip2int(string ip);
      2,convert int value to string ip
      string int2ip(int ip);
      3,validate input ip string
      bool ipvalidate(string ip);
  
    TimeConvertor:
      1,convert readable string time to unix timestamp
      time_t string2unix(string datetime);
      2,convert unix timestamp to readabel string time
      string unix2string(time_t ts);

Generator:
  Generator ips to datapath
  
    custom set:
        1,startIp
        2,startDatetime
        3,endDatetime
        4,dataPath
        5,number of server
        5,num of CPU of per server

    simulator(string startIp, string startDatetime, string endDatetime, string dataPath, int numofserver, int numofcpu);

Query system:

    1,read file into dictionary;
    bool init();
    
    2, find set of records and display
    void search(string ipaddress, string serverid, string starttime, string endtime);
        2.1 binary search to find timestamp
        long findUnixTimestamp(vector<record>& records, time_t timestamp);
        
    3,validate input string
    bool check(string ipaddress, string serverid, string starttime, string endtime);    
    
    4, UI

Bash script:
    Generate.sh
    Query.sh

## Core Design

Search Alg:

using hashmap mapping ip to server and cpus, O(1) time complexity to find server and cpu
using array store records of one cpu. **option: sort every array O(n log n)
using binary searh to find start index and end index. every search takes O(logn) time complexity.
generate result by linear time.

every query takes O(2 * log n) + O(k) time

If input file is sorted by timestamp, this Alg is linear Alg.
If input file is unsorted, this Alg takes O(nlogn)

Search Alter Alg:

using hashmap mapping ip to server and cpus, O(1) time complexity to find server and cpu
using set(binary search tree) store records of one cpu. 
generate result using O(n log n) time.

every query takes O(2 * log n) + O(k * log n) time

No matter input file is unsorted or not, this Alg takes O(nlogn)

## Usage

Go to root directory, 

1,
To run the generator:
bash ./generate.sh DATA_PATH
e.g bash ./generate.sh ./data/log.txt

This will generate 1000 ip address from 192.168.1.1 ~ 192.168.4.232

2,
To run the interactive query tool:
bash ./query.sh DATA_PATH
e.g bash ./query.sh ./data/log.txt

To Query:

>QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05

CPU1 usage on 192.168.1.10:

(2014-10-31 00:00, 90%), (2014-10-31 00:01, 89%), (2014-10-31 00:02, 87%), (2014-10-31 00:03,  94%) (2014-10-31 00:04, 88%)

>QUERY 192.168.1.12 0 2014-10-31 00:00 2014-10-31 00:05

CPU0 usage on 192.168.1.12:

(2014-10-31 00:00, 90%), (2014-10-31 00:01, 89%), (2014-10-31 00:02, 87%), (2014-10-31 00:03,  94%), (2014-10-31 00:04, 88%)

To exit:
>EXIT
>exit

## Test

E.g:(Just copy and paste to your terminal)

bash ./generate.sh ./data/log.txt
bash ./query.sh ./data/log.txt
QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05
QUERY 192.168.1.12 0 2014-10-31 00:00 2014-10-31 00:05
QUERY 192.168.30.12 0 2014-10-31 00:00 2014-10-31 00:05
QUERY 192.168.1.12 0 2014-01-31 00:00 2014-11-20 00:05
QUERY 192.168.1.12 0 2014-10-31 08:00 2014-10-31 12:00
QUERY 192.168.1.12 0 2014-10-31 03:00 2014-10-31 02:00
exit

see unit test file

## Development log

Total Time spent: 5.5 hours
Design: 1.5 hours
Implement and unit test: 3 hours
Doc and integration: 1 hour

## Author

Zeqiang Wang
