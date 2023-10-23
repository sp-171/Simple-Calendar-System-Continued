#include <iostream>
using namespace std;
#pragma once

#include "date.hpp"
#include "time.hpp"


class Calendar: public Date
{
    public:
    
    Calendar(); // default constructor
    bool book(const Date &date, const TimeRange &time);
        //books an appointment at the given date and time, assuming it is a valid workday
        //and the given valid time range of the day has not been booked yet. 
    bool cancel(const Date &date, const TimeRange &time);
        //cancels apppointments 
    bool query(const Date& date, const TimeRange& time);

    void printFreeTimeSlots(const Date &date);
    void printAllAppointed();

    void printFreeDays();

    void initializingArrays();

    friend ostream& operator <<(ostream& output, Calendar bookslots);

    private:
        Date May[23];
        Date June[31];
        Date July[32];
        Date August[32];


};
