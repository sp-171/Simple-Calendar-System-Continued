#include <iostream>
#include "time.hpp"
using namespace std;

TimeRange::TimeRange()
{
  //default constructor
  //sets all to 0
  beginHour = 0;
  beginMinute = 0;
  endHour = 0;
  endMinute = 0;
};
  
TimeRange::TimeRange(int in_beginHour, int in_beginMinute, int in_endHour, int in_endMinute)
{ //constructor
  beginHour = in_beginHour;
  beginMinute = in_beginMinute;
  endHour = in_endHour;
  endMinute = in_endMinute;
}

void TimeRange:: set(int hour1, int minute1, int hour2, int minute2){
    beginHour = hour1;
    beginMinute = minute1;
    endHour = hour2;
    endMinute = minute2;
  }

// checking if the time range they gave is valid
  int TimeRange::isValid()
  {
    if ((beginHour >= 0) && (beginHour <= 24))    
    {
      if ((endHour >= 0) && (endHour <= 24))  
      {
        if ((beginMinute == 0) || (beginMinute == 30))
        {
          if((endMinute ==0) || (endMinute == 30))
          {
            if(endHour > beginHour) //end hour must be greater than begin hour but less than 25
            {
              return 1;
            }
            else if (beginHour == endHour)
              {
                if(endMinute == 30)
                  return 1; //return true
              }
               
          }
        }
      }
    }
    return 0;
  }

  // defining getter functions
  int TimeRange::getBeginHour(){
    return beginHour; 
  }

  int TimeRange::getBeginMinute(){
    return beginMinute; 
  }

  int TimeRange::getEndHour(){
    return endHour;
  }

  int TimeRange::getEndMinute(){
    return endMinute;
  }

void TimeRange::output(ostream &outs)
{
    // outputs class information
    outs << "Begin hour: " << beginHour << endl;
    outs << "Begin minute: " << beginMinute << endl;
    outs << "End hour: " << endHour << endl;
    outs << "End minute: " << endMinute << endl;
    return;
}
    
int TimeRange::TimeIndex(int hour1, int minute1)
{
    // changes time to an index for class function
    int index = hour1 * 2;
    if (minute1 == 30)
    {
        index++;
    }
    return index;
}




