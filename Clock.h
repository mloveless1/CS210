/*
*
* CS-210 Project One
* Name: Malcolm Loveless
* Date 9/14/2022
*
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
using std::to_string;
class Clock
{

private:

	int hours;
	int minutes;
    int seconds;

public:
    Clock() {
        setHours(0);
        setMinutes(0); 
        setSeconds(0);
    }
    Clock(int hours, int minutes, int seconds) {
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }
	// Getter and Setter methods
	void setHours(int h) {
		hours = h;
	}
	int getHours() {
		return hours;
	}
	void setMinutes(int m) {
		minutes = m;
	}
	int getMinutes() {
		return minutes;
	}
	void setSeconds(int s) {
		seconds = s;
	}
	int getSeconds() {
		return seconds;
	}
    string formatNumbers(int num) {
        string formattedNum;
        if (num < 10) {
            formattedNum = "0" + to_string(num);
        }
        else {
            formattedNum = to_string(num);
        }
        return formattedNum;
    }
    // Update the hour according to current time, anything over 12 will reset the hour to 1
    void updateHour() {
        if (getHours() == 23) {
            setHours(0);
        }
        else {
            setHours(getHours() + 1);
        }
    }
    // Update the minute according to the current time. If the minute is 59, it will update the hour.
    void updateMinute() {
        if (getMinutes() == 59) {
            updateHour();
            setMinutes(0);
        }
        else {
            setMinutes(getMinutes() + 1);
        }
    }
    void updateSecond() {
        if (getSeconds() == 59) {
            updateMinute();
            setSeconds(0);
        }
        else {
            setSeconds(getSeconds() + 1);
        }
    }
    // Here we build the string of our 12Hr clock.
    string twelveTime() {
        // String and int variables to build our string
        int newHour = getHours();
        string amOrPm;
        string hour;
        string minute;
        string second;
        // Check if it's AM or PM from 12th to 23rd hour
        bool evening = (getHours() > 11 && getHours() < 24);
        if (evening) {
            amOrPm = " PM";
        }
        else {
            amOrPm = " AM";
        }
        // Make sure our 12 hour clock resets to 1 after every 12th hour
        if (evening && newHour != 12) {
            newHour = getHours() - 12;
        }
        // The zero hour is 12AM
        if (getHours() == 0) {
            newHour = 12;
        }

        // Format our numbers 
        hour = formatNumbers(newHour);
        minute = formatNumbers(getMinutes());
        second = formatNumbers(getSeconds());
        
        // Return our time in string form here in the form of hh:mm:ss
        string time = hour + ":" + minute + ":" + second + amOrPm;
        return time;

    }

    // Here we build the string of our 24Hr clock.
    string twentyFourTime() {
        // String variables to build our string
        string hour;
        string minute;
        string second;
        // Check if it's AM or PM from 12th to 23rd hour
        
        // Add prefix of 0 to single digit numbers
        hour = formatNumbers(getHours());
        minute = formatNumbers(getMinutes());
        second = formatNumbers(getSeconds());
        
        // Return our time in string form here in the form of hh:mm:ss
        string time = hour + ":" + minute + ":" + second;
        return time;

    }
};

