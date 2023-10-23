#include <iostream>
using namespace std;
#pragma once
// header file time.hpp to declare your class
class TimeRange
{
public:
    // default constructor
    TimeRange();

    TimeRange(int beginHour, 
              int beginMinute, 
              int endHour, 
              int endMinute);

    // setting appointement time
    void set(int hour1, int minute1, int hour2, int minute2);

    // checks validity
    int isValid();

    // outputs class info
    void output(std::ostream &outs);

    // returns class info
    int getBeginHour();
    int getBeginMinute();
    int getEndHour();
    int getEndMinute();

    // makes a time index
    int TimeIndex(int hour1, int minute1);

private:
    int beginHour;
    int beginMinute;
    int endHour;
    int endMinute;
};

