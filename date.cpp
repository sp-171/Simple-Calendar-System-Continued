//date.cpp to implement your class
#include "date.hpp"
#include "time.hpp"
#include <iostream>
using namespace std;

Date::Date()
{ //default constructor
  //sets all to 0
  month = 0;
  day = 0;
  for(int i = 0; i < 48; i++)
  {
      appointed[i] = 0;
  }    
}

Date::Date(int set_month, int set_day)
{ //constructor
  //sets month and day
  month = set_month;
  day = set_day;
}

void Date::set_appointed(int index, bool appt_val)
{
        appointed[index] = appt_val;
        return;
}

void Date::set_date(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
    return;
}

// Returns true if index is available, and false if index is not available.
bool Date::get_available(int index)
{
    // if already booked at this time
    if (appointed[index] == 0) // checks for appt
    {
        return true;
    }
    return false;
}

int Date::get_month()
{
    // returns month
    return month;
}

int Date::get_day()
{
    // returns day
    return day;
}

void Date::get_date()
{
    cout << month << "/" << day << "/" << "2022";
};


int Date::isValid()
{
    if (isHoliday() == 0)
    {
        if (month == 5) 
        {
            if ((day > 8) && (day < 32))
            {
                if(isWeekend() == 0)
                    return 1;
                else 
                    return 2;
            }
        }
        else if(month == 6)
        {
            if ((day > 0) && (day < 31))
            {
                if(isWeekend() == 0)
                    return 1;
                else 
                    return 2;
            }
        }
        else if(month == 7)
        {
            if ((day > 0) && (day <= 31))
            {
                if(isWeekend() == 0)
                    return 1;
                else return 2;
            }
        }
        else if (month == 8)
        { 
            if ((day > 0) && (day < 8))
            {
                if(isWeekend() == 0)
                    return 1;
                else return 2;
            } 
        }
    }
        return 0;
    
}

int Date::isHoliday()
{
    const Date VictoriaDay(5,23);
    const Date CanadaDay(7,1);
    const Date BCDay(8,1);

   bool one, two, three = 0;
   
   one = equal(*this, VictoriaDay);
   two = equal(*this, CanadaDay);
   three = equal(*this, BCDay);

   if(one == true || two == true || three == true)
   {
       //cout << "No appointments are available. This is a holiday. Please select another date." << endl;
       return 1;
   }
   return 0;
}

int Date::isWeekend()
{
    // checks if weekend (check by month)
    const int NUM_MAY_WEEKENDS = 6;
    const int NUM_JUNE_WEEKENDS = 8;
    const int NUM_JULY_WEEKENDS = 10;
    const int NUM_AUGUST_WEEKENDS = 2;
    const int mayWeekends[NUM_MAY_WEEKENDS] = {14, 15, 21, 22, 28, 29};
    const int juneWeekends[NUM_JUNE_WEEKENDS] = {4, 5, 11, 12, 18, 19, 25, 26};
    const int julyWeekends[NUM_JULY_WEEKENDS] = {2, 3, 9, 10, 16, 17, 23, 24, 30, 31};
    const int augustWeekends[NUM_AUGUST_WEEKENDS] = {6, 7};
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    if (month == 5) // compares may weekends
    {
        for (int i = 0; i < NUM_MAY_WEEKENDS; i++)
        {
            if (mayWeekends[i] == day)
            {
                return 1;
            }
        }
    }
    else if (month == 6) // compares june weekends
    {
        for (int i = 0; i < NUM_JUNE_WEEKENDS; i++)
        {
            if (juneWeekends[i] == day)
            {
                return 1;
            }
        }
    }
    else if (month == 7) // compares july weekends
    {
        for (int i = 0; i < NUM_JULY_WEEKENDS; i++)
        {
            if (julyWeekends[i] == day)
            {
                return 1;
            }
        }
    }
    else if (month == 8) // august weekends
    {
        for (int i = 0; i < NUM_AUGUST_WEEKENDS; i++)
        {
            if (augustWeekends[i] == day)
            {
                return 1;
            }
        }
    }

    return 0;
}

void Date::output(ostream &outs)
{
    outs << "Month: " << month << endl; //output month
    outs << "Day: " << day << endl; //ouput day
    int check = isValid();

    if (check == 0)
    {
        outs << "Date is invalid.\n";
    }
    else if (check == 2)
    {
        outs << "Date is a weekend.\n";
    }
    else if (check == 1)
    {
        outs << "Date is a weekday.\n";
    }
}

void Date::set_appointed()
{
    for(int i = 0; i<48; i++)
    {
        appointed[i] = 0; //setting all to false
    }
    //this->appointed;
}

int Date::get_if_appointed(int timeSlotBegin,int timeSlotEnd) //check if timeSlot is appointed
{
    int temp=0;
    int number_booked=0;

    for(int i = timeSlotBegin; i<(timeSlotEnd+1); i++) //runs for first to last timeSlot
    {
        temp = appointed[i];
        number_booked = temp + number_booked; //if number booked is 1 or >1 that means already appointed
    }
    return number_booked;
}

int Date::get_if_appointed2() //check if timeSlot is appointed
{
    int temp=0;
    int number_booked=0;

    for(int i = 0; i<48; i++) //runs for first to last timeSlot
    {
        temp = appointed[i];
        number_booked = temp + number_booked; //if number booked is 1 or >1 that means already appointed
    }
    return number_booked;
}



int Date::check_appointed() //almost the same function as get_bool. It check all slots for specific day without parameter.
{
    int number_booked=0;
    int temp=0;
    for (int i = 0; i < 48; i++)
    {
        temp=appointed[i];
        number_booked = number_booked + temp;

    }
    return number_booked;
}
void Date::book_appointment(int timeSlotBegin, int timeSlotEnd)
{
    for(int i = timeSlotBegin; i<timeSlotEnd; i++ )
    {
        appointed[i] = 1;
    }
}

void Date::cancel_appointment(int timeSlotBegin, int timeSlotEnd)
{
    for (int i = timeSlotBegin; i < (timeSlotEnd+1); i++)
    {
        appointed[i] = 0;
    }
}

/*
void Date::TimePrint(int i, ostream &outs)
{
    int minute = 0;
    int hour = i/2;

    if(i%2 == 0) //if there is a remainder minute is 30
    {
        minute = 00;
    }
    else if (i % 2 == 1)
    {
        minute = 30;
    }

    outs << hour << ":" << minute << endl;
}
*/

void Date::printFreeTimeSlots()
{
   for (int i = 0; i < 48; i++)
    {
        if (i % 2 == 0)
        {
            if (appointed[i] == 0) //check if time slot is open
            {
                cout << i/2 << ":00 - " << i/2 << ":30" << endl; //print out time slots
            }
        }
        else if (i % 2 == 1)
        {
            if (appointed[i] == 0)
            {
                cout << i/2 << ":30 - " << (i + 1)/ 2 << ":00" << endl; 
            }
        }
    }
}

void Date::printAppointedTimeSlots()
{
    for (int i = 0; i < 48; i++) 
    {
        if (i % 2 == 0)
        {
            if (appointed[i] == 1) //check if time slot is open
            {
                cout << i/2 << ":00 - " << i/2 << ":30" << endl; //print out time slots
            }
        }
        else if (i % 2 == 1)
        {
            if (appointed[i] == 1)
            {
                cout << i/2 << ":30 - " << (i + 1)/2 << ":00" << endl; //print out time slots
            }
        }
    }
}

bool equal(const Date one, const Date two)
{
    if((one.month == two.month) && (one.day == two.day))
        return true;

    return false;
}












