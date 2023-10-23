#include <iostream>
#include "calendar.hpp"
using namespace std;


Calendar::Calendar()
{
    //default constructor
}

void Calendar::initializingArrays(){
  for (int i = 0; i < 23; i++)
  {
    May[i].set_date(5,i+9);
  }
  for (int i = 0; i < 31; i++)
  {
    June[i].set_date(6,i+1);
    
  }
  for (int i = 0; i < 32; i++){
    July[i].set_date(7,i+1);
  }
  for (int i = 0; i < 9; i++)
  {
    August[i].set_date(8,i+1);
  }  
}

bool Calendar::book(const Date &date, const TimeRange &time)
{
    Date date_ = date;
    TimeRange time_ = time;

    //getting date and times
    int day = date_.get_day();
    int month = date_.get_month();

    int beginHour = time_.getBeginHour();
    int beginMinute = time_.getBeginMinute();
    int endHour = time_.getEndHour();
    int endMinute = time_.getEndMinute();

    int timeSlotBegin;
    int timeSlotEnd;
    int check = 0;

    //converting to timeslot 
    if(beginMinute == 0)
    {
        timeSlotBegin = (beginHour * 2);
    }
    else
    {
        timeSlotBegin = (beginHour * 2) + 1;
    }

    if(endMinute == 0)
    {
        timeSlotEnd = (endHour * 2);
    }
    else
    {
        timeSlotEnd = (endHour * 2) + 1;
    }

    int numberOfTimeSlots = (timeSlotEnd - timeSlotBegin)+1;

    if (date_.get_month() == 5)
    {
        check = May[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
    }
    else if (date_.get_month() == 6)
    {
        check = June[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
    }
    else if (date_.get_month() == 7)
    {
        check = July[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
    }
    else if (date_.get_month() == 8)
    {
        check = August[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
    }

    if (check == 0)
        {
            cout << "The selected appointments have been booked." << endl;
            if (date_.get_month() == 5)
            {
                 May[day].book_appointment(timeSlotBegin, timeSlotEnd);
                 May[day].set_appointed();
               
            }
            else if (date_.get_month() == 6)
            {
                 June[day].book_appointment(timeSlotBegin, timeSlotEnd);
                 June[day].set_appointed();
            }
            else if (date_.get_month() == 7)
            {
                July[day].book_appointment(timeSlotBegin, timeSlotEnd);
                July[day].set_appointed();
            }
            else if (date_.get_month() == 8)
            {
                August[day].book_appointment(timeSlotBegin, timeSlotEnd);
                August[day].set_appointed();
            }
            return true;
        }
        else if (check == numberOfTimeSlots)
        {
            cout << "The selected appointment time range is fully booked. Cannot book appointment." << endl;
            return false;
        }
        else
        {
            cout << "The selected appointment time range is partially booked. Cannot book appointment." << endl;
            return false;
        }

        
    }

bool Calendar::cancel(const Date &date, const TimeRange &time)
{
    Date date_ = date;
    TimeRange time_ = time;

    //getting date and times
    int day = date_.get_day();
    int month = date_.get_month();

    int beginHour = time_.getBeginHour();
    int beginMinute = time_.getBeginMinute();
    int endHour = time_.getEndHour();
    int endMinute = time_.getEndMinute();

    int timeSlotBegin;
    int timeSlotEnd;
    int check = 0;

    //converting to timeslot 
    if(beginMinute == 0)
    {
        timeSlotBegin = (beginHour * 2);
    }
    else
    {
        timeSlotBegin = (beginHour * 2) + 1;
    }

    if(endMinute == 0)
    {
        timeSlotEnd = (endHour * 2);
    }
    else
    {
        timeSlotEnd = (endHour * 2) + 1;
    }

     int numberOfTimeSlots = (timeSlotEnd - timeSlotBegin)+1;
    
    //checks if slot is appointed
    if (date_.get_month() == 5)
    {
        check = May[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
        if (check != 0)
        {
            May[day].cancel_appointment(timeSlotBegin, timeSlotEnd);
            cout << "Appointment(s) Cancelled." << endl;
        }
    else
        cout << "No appointment is booked in the selected timerange." << endl;
    }
    else if (date_.get_month() == 6)
      {
        check = June[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
        if (check != 0)
        {
            June[day].cancel_appointment(timeSlotBegin, timeSlotEnd);
            cout << "Appointment(s) Cancelled." << endl;
        }
    else
        cout << "No appointment is booked in the selected timerange." << endl;
    }
    else if (date_.get_month() == 7)
      {
        check = July[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
        if (check != 0)
        {
            July[day].cancel_appointment(timeSlotBegin, timeSlotEnd);
            cout << "Appointment(s) Cancelled." << endl;
        }
    else
        cout << "No appointment is booked in the selected timerange." << endl;
    }
    else if (date_.get_month() == 8)
      {
        check = August[day].get_if_appointed(timeSlotBegin, timeSlotEnd);
        if (check != 0)
        {
            August[day].cancel_appointment(timeSlotBegin, timeSlotEnd);
            cout << "Appointment(s) Cancelled." << endl;
        }
    else
        cout << "No appointment is booked in the selected timerange." << endl;
    }
    return true;
}

bool Calendar::query(const Date& date, const TimeRange& time)
{
    TimeRange myTime = time;
    Date myDate = date;
    
    int check = 0;
    int day = myDate.get_day();

    int beginHour = myTime.getBeginHour();
    int beginMinute = myTime.getBeginMinute();
    int endHour = myTime.getEndHour();
    int endMinute = myTime.getEndMinute();

    int timeslotBegin;
    int timeslotEnd;

    if (beginMinute == 0)
    {
        timeslotBegin = (beginHour * 2);
    }
    else
    {
        timeslotBegin = (beginHour * 2) + 1;
    }
    if (endMinute == 0)
    {
        timeslotEnd = (endHour * 2);
    }
    else
    {
        timeslotEnd = (endHour * 2) + 1;
    }

    int numberOfSlots = (timeslotEnd - timeslotBegin);
    //cout << "number slots: " << numberOfSlots;
   
    if (myDate.get_month() == 5)
    {
       check=May[day].get_if_appointed(timeslotBegin, timeslotEnd);
    }
    else if (myDate.get_month() == 6)
    {
        check=June[day].get_if_appointed(timeslotBegin, timeslotEnd);
    }
    else if (myDate.get_month() == 7)
    {
        check=July[day].get_if_appointed(timeslotBegin, timeslotEnd);
    }
    else if (myDate.get_month() == 8)
    {
        check=August[day].get_if_appointed(timeslotBegin, timeslotEnd);
    }
    if (check == 0)
    {
        cout << "The selected appointments are free to book." << endl;
        return true;
    }
    else if(check==numberOfSlots)
    {
        cout << "The selected appointment range is fully booked." << endl;
        return false;
    }
    else
    {
        cout << "The selected appointment range is partially booked." << endl;
        return false;
    }
    
}

void Calendar::printFreeTimeSlots(const Date &date)
{
    Date date_ = date;
    //int valid = date_.isValid();
    int month = date_.get_month();
    int day = date_.get_day();
    int available;

    //if(valid == 1)
    //{
        if(month == 5)
        {
            if(May[day].check_appointed() == 48)
            {
                available = 0; //no appointments available
                cout << "No available appointments for this day." << endl;
            }
            else
                May[day].printFreeTimeSlots();
        }
        else if(month == 6)
        {
            if(June[day].check_appointed() == 48)
            {
                available = 0;
                cout << "No available appointments for this day." << endl;
            }
            else
                June[day].printFreeTimeSlots();
        }
         else if(month == 7)
        {
            if(July[day].check_appointed() == 48)
            {
                available = 0;
                cout << "No available appointments for this day." << endl;
            }
            else
                July[day].printFreeTimeSlots();
        }
         else if(month == 8)
        {
            if(August[day].check_appointed() == 48)
            {
                available = 0;
                cout << "No available appointments for this day." << endl;
            }
            else
                August[day].printFreeTimeSlots();
        }
        else 
        {
            cout << "error in calendar printfreetimeslots" << endl;
        }
    //}
    //else
       // valid = 0;
        //cout << "invalid date entered." << endl;

}

ostream& operator <<(ostream& output, Calendar bookslots)
    {
        bookslots.printAllAppointed();
        return output; 
    }

void Calendar::printFreeDays()
{   //print May
    int has_appointments;
    for (int i = 0; i < 23; i++)
    {
       
        if (May[i].isWeekend() ==1) //if holiday or weekend don't print
        {
            //do nothing
        }
        else if(May[i].isHoliday() == 1)
        {
            //do nothing
        }
        else if (May[i].check_appointed() < 47)
        {
            May[i].get_date();
            cout << " has available appointments." << endl;
        }
        else
        {
            //do nothing
        }
    }

    //print june
    cout << endl;
    for (int i = 0; i < 31; i++)
    {
        has_appointments = June[i].check_appointed();
        if (June[i].isWeekend() == 1) //if holiday or weekend don't print
        {
            //do nothing
        }
        else if(June[i].isHoliday() == 1)
        {
            //do nothing
        }
        else if (has_appointments <47)
        {
            June[i].get_date();
            cout << " has available appointments." << endl;
        }
    }
    //print july
    cout << endl;
    for (int i = 0; i < 30; i++)
    {
        has_appointments = July[i].check_appointed();
        //if holiday or weekend don't print
        if (July[i].isWeekend() == 1)
        {
            //do nothing
        }
        else if(July[i].isHoliday() == 1)
        {
            //do nothing
        }
        else if (has_appointments <47)
        {
            July[i].get_date();
            cout << " has available appointments." << endl;
        }
    }
    //print August
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        has_appointments = August[i].check_appointed();
        //if holiday or weekend don't print
        if (August[i].isWeekend() == 1)
        {
            //do nothing
        }
        else if(August[i].isHoliday() == 1)
        {
            //do nothing
        }
        else if (has_appointments < 47)
        {
            August[i].get_date();
            cout << " has available appointments." << endl;
        }
    }
}

void Calendar::printAllAppointed()
{
    //May
    int check = 0;
    int last_timeSlot = 0;
    for(int i = 0; i<23; i++)
    {
            check = May[i].get_if_appointed2();
            if(check != 0)
            {
                for(int j = 0; j<48; j++)
                {
                    cout << "May " << i << ", 2022" << endl;
                    if(j%2 == 0)//if even time
                    {
                        cout << j/2 << ":00" << endl;
                        last_timeSlot = j;
                    }
                    else
                    {
                        cout << j/2 << ":30" << endl;
                        last_timeSlot = j;
                    }
                    if(last_timeSlot % 2 == 0)
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                    else
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                } 
            }
    }
    //June
     for(int i = 0; i<31; i++)
    {
            check = June[i].get_if_appointed2();
            if(check != 0)
            {
                for(int j = 0; j<48; j++)
                {
                    cout << "June " << i << ", 2022" << endl;
                    if(j%2 == 0)//if even time
                    {
                        cout << j/2 << ":00" << endl;
                        last_timeSlot = j;
                    }
                    else
                    {
                        cout << j/2 << ":30" << endl;
                        last_timeSlot = j;
                    }

                    if(last_timeSlot % 2 == 0)
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                    else
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                } 
            }
    }
    //july
     for(int i = 0; i<31; i++)
    {
            check = July[i].get_if_appointed2();
            if(check != 0)
            {
                for(int j = 0; j<48; j++)
                {
                    cout << "July " << i << ", 2022" << endl;
                    if(j%2 == 0)//if even time
                    {
                        cout << j/2 << ":00" << endl;
                        last_timeSlot = j;
                    }
                    else
                    {
                        cout << j/2 << ":30" << endl;
                        last_timeSlot = j;
                    }

                    if(last_timeSlot % 2 == 0)
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                    else
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                } 
            }
    }
    //August
   for(int i = 0; i<8; i++)
    {
            check = August[i].get_if_appointed2();
            if(check != 0)
            {
                for(int j = 0; j<48; j++)
                {
                    cout << "August " << i << ", 2022" << endl;
                    if(j%2 == 0)//if even time
                    {
                        cout << j/2 << ":00" << endl;
                        last_timeSlot = j;
                    }
                    else
                    {
                        cout << j/2 << ":30" << endl;
                        last_timeSlot = j;
                    }

                    if(last_timeSlot % 2 == 0)
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                    else
                    {
                        cout << (last_timeSlot/2)+1 << ":00" << endl;
                    }
                } 
            }
    }
}

