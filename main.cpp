//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "calendar.hpp"
#include <math.h>
using namespace std;


int main() {
  int input = 0;
  int error = 0;
  int valid = 0;
  int check = 0;
  int  check2 = 0;

  int month;
  int day;
  int beginHour;
  int beginMinute;
  int endHour;
  int endMinute;

  //string str = '';

  Date date;
  Date temp_date;
  TimeRange time;
  TimeRange temp_time;
  Calendar calendar;

  temp_date.set_appointed(); //sets all to zero.

  //ERROR WITH 4 BOOKING APPOINTMENT KEEPS SAYS APPOINTMENT PARTIALLY BOOKED DIDNT GET TTIME TO CHECK ERROR.


  calendar.initializingArrays();

   //do {//while input is not 7
       do {//Outputs all the options the user can take
           cout << "\n\n\nWhat would you like to do today?" << endl;
           cout << "1.) Print out all booked appointments. " << endl;
           cout << "2.) Print out all days that have free time slots which have not been booked." << endl;
           cout << "3.) Print out all free time slots for a given day which have not been booked." << endl;
           cout << "4.) Book an appointment." << endl;
           cout << "5.) Query an appointment" << endl;
           cout << "6.) Cancel an appointment." << endl;
           cout << "7.) Exit Program. " << endl;
           cout << "Please enter a number corresponding to the option." << endl;
           cin >> input;
           if (input == 1)
           {
            error = 0;
            cout << "You have chosen: to print out all booked appointments." << endl;
            calendar.printAllAppointed();
           }
           if(input == 2) 
           {
            error = 0;
            cout << "You have chosen: to print out all days that have free time slots which have not been booked. "<< endl;
            calendar.printFreeDays();
           }
           if(input == 3)
           {
              error = 0;
              cout << "You have chosen: to print all free time slots for a given day which have not been booked. "<< endl;

              //get month and day for which user would like slots
              do
              {
                check = 0;
                cout << "\nNow, you will be asked to enter a month and a day for which you would like to see free time slot." << endl;
                cout << "This statement will re-run if an invalid date is entered." << endl;
                cout << "Enter a month a number: ";
                cin >> month; // user input
                cout << "Enter a day as a number: ";
                cin >> day;

                temp_date.set_date(month,day); //set date


                check = temp_date.isValid(); //check if date is valid
            }while(check == 0);
            calendar.printFreeTimeSlots(temp_date); // works now
            //temp_date.printFreeTimeSlots(); works but of date class preferably need the one from calendar class
           }
           if(input == 4)
           {
              error = 0;
              cout << "You have chosen: Book an appointment. "<< endl;

              do
              {
                check = 0;
                cout << "\nNow, you will be asked to enter a month and a day for your appointment." << endl;
                cout << "This statement will re-run if an invalid date is entered." << endl;
                cout << "Enter a month a number: ";
                cin >> month; // user input
                cout << "Enter a day as a number: ";
                cin >> day;

                temp_date.set_date(month,day); //set date

                check = temp_date.isValid(); //check if date is valid
            }while(check == 0);

             //printing available time for this appointment
            //cout << "The available times for this date are: " << endl;
            //calendar.printFreeTimeSlots(temp_date);

            do
            {
              //getting user input for time and checking if valid
              cout << "\nNow, you will be asked to enter a beginning and end time for your appointment." << endl;
              cout << "This statement will re-run if an invalid time is entered." << endl;
              cout << "\nWhat hour would you like your booking to start? ";
              cin >> beginHour; // user input

              cout << "\nWhat minute would you like your booking tot start? ";
              cin >> beginMinute; // user input

              cout << "\nWhat hour would you like your booking to end? ";
              cin >> endHour; // user input

              cout << "\nWhat minute would you like your booking to end? ";
              cin >> endMinute; // user input

              temp_time.set(beginHour, beginMinute, endHour, endMinute); // set time

              check2 = temp_time.isValid(); //check if time is valid

            } while (check2 == 0);
          
            //booking appointment
            calendar.book(temp_date, temp_time);

          }
else if(input==5)
          {
            error = 0;
            cout<< "\nYou have chosen: Query an appointment." << endl;
            do
              {
                check = 0;
                cout << "\nNow, you will be asked to enter a month and a day that you would like to query." << endl;
                cout << "This statement will re-run if an invalid date is entered." << endl;

                cout << "Enter a month a number: ";
                cin >> month; // user input
                cout << "Enter a day as a number: ";
                cin >> day;

                temp_date.set_date(month,day); //set date

                check = temp_date.isValid(); //check if date is valid
            }while(check == 0);

            do
            {
              //getting user input for time and checking if valid
              cout << "\nNow, you will be asked to enter a beginning and end time for your appointment." << endl;
              cout << "This statement will re-run if an invalid time is entered." << endl;

              cout << "\nWhat hour would you like your booking to start? ";
              cin >> beginHour; // user input
              cout << "\nWhat minute would you like your booking to start? ";
              cin >> beginMinute; // user input
              cout << "\nWhat hour would you like your booking to end? ";
              cin >> endHour; // user input
              cout << "\nWhat minute would you like your booking to end? ";
              cin >> endMinute; // user input

              temp_time.set(beginHour, beginMinute, endHour, endMinute); // set time

              check2 = temp_time.isValid(); //check if time is valid

            } while (check2 == 0);

            calendar.query(temp_date,temp_time);
          }

           else if(input == 6)
          {
            error = 0;
            cout<< "\n You have chosen: Cancel an appointment." << endl;
            do
              {
                check = 0;
                cout << "\nNow, you will be asked to enter a month and a day that you would like to cancel your appointment for." << endl;
                cout << "This statement will re-run if an invalid date is entered." << endl;

                cout << "Enter a month a number: ";
                cin >> month; // user input
                cout << "Enter a day as a number: ";
                cin >> day;

                temp_date.set_date(month,day); //set date

                check = temp_date.isValid(); //check if date is valid
            }while(check == 0);

            do
            {
              //getting user input for time and checking if valid
              cout << "\nNow, you will be asked to enter a beginning and end time for the appointment you would like to cancel." << endl;
              cout << "This statement will re-run if an invalid time is entered." << endl;

              cout << "\nWhat hour did your appointment booking start? ";
              cin >> beginHour; // user input
              cout << "\nWhat minute did your appointment your booking start? ";
              cin >> beginMinute; // user input
              cout << "\nWhat hour did your appointment booking  end? ";
              cin >> endHour; // user input
              cout << "\nWhat minute did your appointment booking  end? ";
              cin >> endMinute; // user input

              temp_time.set(beginHour, beginMinute, endHour, endMinute); // set time

              check2 = temp_time.isValid(); //check if time is valid

            } while (check2 == 0);

            calendar.cancel(temp_date,temp_time);
          
          }
          else if(input == 7)
          {
            cout << "You have chosen: Exit the program." << endl;
            exit(1);
          }
          else
          {
            valid = 0;
          }
        
          
      
  } while (valid == 0);
  return 0;
}
          




