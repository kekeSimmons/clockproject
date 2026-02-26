/*
 * Author: Keke Simmons
 * Date: 26 January 2026
 * Project: CS 210 Project One – Chada Tech Clocks
 * Description:
 *   Header file for the Clock class. Defines the interface
 *   for managing and displaying 12-hour and 24-hour time formats.
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

/*
 * Clock class
 * Manages time storage and formatting for 12-hour and 24-hour clocks
 */
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

    void normalizeTime(); // Ensures valid time values

public:
    Clock(int h, int m, int s);

    void addHour();
    void addMinute();
    void addSecond();

    std::string get24HourTime() const;
    std::string get12HourTime() const;
};

#endif
