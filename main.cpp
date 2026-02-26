/*
 * Author: Keke Simmons
 * Date: 26 January 2026
 * Project: CS 210 Project One – Chada Tech Clocks
 * Description:
 *   Main driver file for the Chada Tech clock application.
 *   Handles user input, menu selection, and program control flow.
 */

#include <iostream>
#include "Clock.h"

using namespace std;

/*
 * Displays the menu options
 */
void displayMenu() {
    cout << "\n********** MENU **********\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
    cout << "**************************\n";
}

/*
 * Displays both clocks simultaneously
 */
void displayClocks(const Clock& clock) {
    cout << "\n**************************\n";
    cout << "*   12-Hour Clock  *  " << clock.get12HourTime() << endl;
    cout << "*   24-Hour Clock  *  " << clock.get24HourTime() << endl;
    cout << "**************************\n";
}

int main() {
    int hours, minutes, seconds;
    int choice = 0;

    // Get initial time from user
    cout << "Enter initial hours (0-23): ";
    cin >> hours;
    cout << "Enter initial minutes (0-59): ";
    cin >> minutes;
    cout << "Enter initial seconds (0-59): ";
    cin >> seconds;

    Clock clock(hours, minutes, seconds);

    // Main program loop
    while (choice != 4) {
        displayClocks(clock);
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}
