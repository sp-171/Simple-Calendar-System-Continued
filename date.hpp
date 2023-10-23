#include <iostream>
using namespace std;
#pragma once

//header file date.hpp to declare your class
class Date
{
    public: 
        Date();
        //default constructor
        Date(int month, int day);
        //sets to month and day
        void set_appointed(int index, bool appt_val);
        //sets appointed index equal to apt val
        void set_date(int month, int day);
        //sets month and day

        bool get_available(int index);
        //checks if no appt is booked

        int get_month();
        // gets month
        int get_day();
        // gets day
        void get_date();

        int isValid();
        // checks if user input is valid
        int isHoliday();
        // checks if holiday
        int isWeekend();
        // checks if holiday

        void output(ostream &outs);
        // print out member variables
        // print if weekday, weekend, holiday

        void printFreeTimeSlots();
        // prints out all free time slots
        void printAppointedTimeSlots();
        // prints all appointed time slots

        friend bool equal(const Date one, const Date two);
        // seeing if equal dates

        void TimePrint(int index, ostream &outs);
        // Prints the time for the appointment at index, to outs

        void set_appointed();
        //sets all appointed to 0;
        int get_if_appointed(int timeSlotBegin, int timeSlotEnd);
        int get_if_appointed2();
        //check if given timeslot is appointed
        int check_appointed();
        //same as get if appointed but without parameter
        void book_appointment(int timeSlotBegin, int timeSlotEnd);
        //sets given time slot to appointed
        void cancel_appointment(int timeSlotBegin, int timeSlotEnd);

    private:
        int month;
        int day;
        bool appointed[48];
};



