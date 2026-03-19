#ifndef DATETIME_H
#define DATETIME_H

/**
 - @file datetime.h
 - @brief Utility functions for retrieving system date and time.
          This file handles the conversion of raw system clock data 
          into human-readable formats (Year, Month, Day, etc.).
 */

#include <ctime>

/**
 - @brief Fetches the current local system time.
 - @return tm* A pointer to a 'tm' struct containing raw time data.
 - @note This pointer is passed to the other functions in this file 
         to avoid calling the system clock multiple times.
 */
tm *getCurrentDateAndTime();

/**
 - @brief Extracts the current year from the provided time struct.
 - @param timeNow: A reference to the current time structure.
 - @return int: The current year (e.g., 2026).
 */
int getCurrentYear(const tm &timeNow);

/**
 - @brief Extracts the current month (1-12).
 - @param timeNow: A reference to the current time structure.
 - @return int: The current month where January is 1.
 */
int getCurrentMonth(const tm &timeNow);

/**
 - @brief Extracts the current day of the month (1-31).
 - @param timeNow: A reference to the current time structure.
 - @return int: The current day.
 */
int getCurrentDay(const tm &timeNow);

/**
 - @brief Extracts the current hour (0-23).
 - @param timeNow: A reference to the current time structure.
 - @return int: The current hour in 24-hour format.
 */
int getCurrentHour(const tm &timeNow);

/**
 - @brief Extracts the current minutes (0-59).
 - @param timeNow: A reference to the current time structure.
 - @return int: The current minutes.
 */
int getCurrentMinute(const tm &timeNow);

/**
 - @brief Extracts the current seconds (0-59).
 - @param timeNow: A reference to the current time structure.
 - @return int: The current seconds.
 */
int getCurrentSecond(const tm &timeNow);

#endif