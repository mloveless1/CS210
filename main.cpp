/*
* 
* CS-210 Project One
* Name: Malcolm Loveless
* Date 9/14/2022
* 
*/

#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
using std::to_string;

string repeatingAsterisk(int n) {
	string asterisks;
	// Concat asterisks to a string the amount of times given
	for (int i = 0; i < n; i++) {
		asterisks = asterisks + "*";
	}
	return asterisks;
}
void displayMenu() {
	// Menu here
	cout << repeatingAsterisk(25);
	cout << "\n* " << "1- Add One Hour" << setfill(' ') << setw(8) << "*" << endl;
	cout << "* " << "2- Add One Minute" << setfill(' ') << setw(6) << "*" << endl;
	cout << "* " << "3- Add One Second" << setfill(' ') << setw(6) << "*" << endl;
	cout << "* " << "4- Exit Program" << setfill(' ') << setw(8) << "*" << endl;
	cout << repeatingAsterisk(25);
	cout << endl;
}
void displayTwelve(Clock clock) {
	// Display twelve hour clock (test)
	cout << repeatingAsterisk(25);
	cout << "\n*" << setfill(' ') << setw(18) << "12-Hour Clock" << setw(6) << "*" << endl;
	cout << "*" << setfill(' ') << setw(18) << clock.twelveTime() << setw(6) << "*" << endl;
	cout << repeatingAsterisk(25);
	cout << endl;
}
void displayTwentyFour(Clock clock) {
	// Test
	cout << repeatingAsterisk(25) << setfill(' ') << repeatingAsterisk(25);
	cout << endl;
}
void displayClocks(Clock clock) {
	/*Line by line build of both clocks. Header -> Title -> Clock -< Footer*/
	// Left Header
	cout << left << setw(25) << repeatingAsterisk(25);
	// Right Header
	cout << right << setfill(' ') << setw(32) << repeatingAsterisk(25) << endl;
	// Left Title
	cout << "*" << setfill(' ') << setw(18) << "12-Hour Clock" << setw(6) << "*";
	// Right Title
	cout << right << setfill(' ') << setw(8) << "*" << setw(18) << "24-Hour Clock" << setw(6) << "*" << endl;
	// Left Clock (Time)
	cout << "*" << setfill(' ') << setw(18) << clock.twelveTime() << setw(6) << "*";
	//Right Clock (Time)
	cout << right << setfill(' ') << setw(8) << "*" << setw(16) << clock.twentyFourTime() << setw(8) << "*" << endl;
	// Left Footer
	cout << left << setw(25) << repeatingAsterisk(25);
	// Right Footer
	cout << right << setfill(' ') << setw(32) << repeatingAsterisk(25) << endl;
	cout << endl;
}
// Passed the reference of the clock object to the menu, wasn't updating time before.
bool menuSelections(int selection, Clock &clock) {
	// Switch statement to process selections
	switch (selection) {
	case 1:
		clock.updateHour();
		break;
	case 2:
		clock.updateMinute();
		break;
	case 3:
		clock.updateSecond();
		break;
	case 4:
		cout << "\nYou've exited the program.\n\n";
		return false;
		break;
	default:
		cout << "\nInvalid selection try again.\n";
		break;
	}
	return true;
}
int main() {
	// Get current time to intialize our clock
	time_t currentTime = time(0);
	struct tm newTime;
	localtime_s(&newTime, &currentTime);

	// Set variable for menu loop and menu selection, intialize clock
	bool acceptingInput = true;
	int selection;
	Clock clock(newTime.tm_hour, newTime.tm_min, newTime.tm_sec);

	// Menu loop 
	while (acceptingInput) {
		// Display clocks and menu here
		displayClocks(clock);
		displayMenu();
		// Prompt for input
		cout << "\nEnter your menu selection: " << endl;
		// Handle input and type mismatch 
		cin >> selection;
		if (!cin<<selection) {
			// Error message, clear bad input flag and discard input then go back to top of loop
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "\n You must enter a number for menu selections \n" << endl;
			continue;
		}
		// Get input and determine whether or not the loop will continue
		acceptingInput = menuSelections(selection, clock);
	}
	return 0;
}