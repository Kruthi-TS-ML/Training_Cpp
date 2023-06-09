#include <iostream>
#include <string>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;
    int totalSeconds;

    public:
        void setTimeinSeconds();
        void convertTimeToHHMMSSFormat();
        void displayTime();
};

int main()
{
    Time timeObj;
    timeObj.setTimeinSeconds();
    timeObj.convertTimeToHHMMSSFormat();
    timeObj.displayTime();
    return 0;
}

void Time::setTimeinSeconds()
{
    int inpSeconds;
    cout << "Enter time in seconds: ";
    cin >> inpSeconds;
    this->totalSeconds = inpSeconds;
}


void Time::convertTimeToHHMMSSFormat()
{
    this->hours = this->totalSeconds/3600;
    this->minutes = (this->totalSeconds/60) % 60;
    this->seconds = this->totalSeconds % 60;
}

void Time::displayTime()
{
    string result;
    if(this->hours < 10)
    {
        result = "0" + to_string(this->hours);
    }
    else
    {
        result = to_string(this->hours);
    }
    if(this->minutes < 10)
    {
        result = result + ":" + "0" + to_string(this->minutes);
    }
    else
    {
        result += to_string(this->minutes);
    }
    if(this->seconds < 10)
    {
        result = result + ":" + "0" + to_string(this->seconds);
    }
    else
    {
        result = result + ":" + to_string(this->seconds);
    }
    cout << "Time in HH:MM:SS format is " << result << endl;
}