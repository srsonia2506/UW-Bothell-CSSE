#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void rep() {
        cout << hours << " : " << minutes << " : " << seconds << endl;
    }
};
