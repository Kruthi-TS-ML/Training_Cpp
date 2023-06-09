#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    time_t system_time = time(nullptr);
    tm *newTime = localtime(&system_time);
    cout << "Current System time is " << asctime(newTime) << endl;
    
    newTime->tm_sec = 40;
    newTime->tm_min = 5;
    newTime->tm_hour = 10;
    newTime->tm_year = 105;
    newTime->tm_mon = 3;
    newTime->tm_mday = 0;
    newTime->tm_wday = 2;
    
    time_t locTime = mktime(newTime);
    system("date");
    string execCmd = "date -s @";
    string buffer = execCmd + to_string(locTime);
    cout << "buff " << buffer << endl;
    system(buffer.c_str());
    return 0;
}