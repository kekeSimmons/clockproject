/*
 * Author: Keke Simmons
 * Date: 26 January 2026
 * Project: CS 210 Project One – Chada Tech Clocks
 * Description:
 *   Implementation file for the Clock class. Contains logic
 *   for time manipulation and formatted output.
 */

#include "Clock.h"
#include <iomanip>
#include <sstream>

/*
 * Constructor initializes clock values
 */
Clock::Clock(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalizeTime();
}

/*
 * Ensures time values remain within valid ranges
 */
void Clock::normalizeTime() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }

    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }

    hours %= 24;
}

/*
 * Adds one hour to the clock
 */
void Clock::addHour() {
    hours = (hours + 1) % 24;
}

/*
 * Adds one minute to the clock
 */
void Clock::addMinute() {
    minutes++;
    normalizeTime();
}

/*
 * Adds one second to the clock
 */
void Clock::addSecond() {
    seconds++;
    normalizeTime();
}

/*
 * Returns formatted 24-hour time
 */
std::string Clock::get24HourTime() const {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds;
    return out.str();
}

/*
 * Returns formatted 12-hour time
 */
std::string Clock::get12HourTime() const {
    std::ostringstream out;
    int displayHour = hours % 12;
    displayHour = (displayHour == 0) ? 12 : displayHour;

    out << std::setfill('0') << std::setw(2) << displayHour << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds
        << (hours < 12 ? " AM" : " PM");

    return out.str();
}
