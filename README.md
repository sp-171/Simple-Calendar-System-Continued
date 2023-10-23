# ENSC251-LAB2-Simple-Calendar-System-Continued
This program is a continuation of the Simple Calendar System. A second repository was created as both projects were part of separate labs.


This is also a simple calendar system, where one can book, query, and delete appointments. 

The program runs on the following assumptions:
1) The dates supported in the calendar system are from May 9, 2022 to Aug 8, 2022, i.e., the Summer term of 2022.
2) No appointment can be made on weekends and holidays.
3) The time format for each day is using the 24-hour format, from 0:00 to 24:00. We only care about the hour and minute field and ignore the second field.
4) An appointment in the calendar system can only be made at multiples of 30 minutes, and it only supports the same day appointment. For example, May 9th 9:00 to 9:30 appointment is valid, May 9th 10:00 to 12:30 is also valid, May 9th 10:10 to 10:30 is invalid because 10:10 is not a multiple of 30 minutes, May 9th 19:00 to May 10th 9:00 is invalid because it crosses two days.
