// Title: Lab 1 - PhoneCalls.cpp
//
// Purpose: read in a list of phone call records from a file, and output them
// in a more user - friendly format to the standard output(cout).
//
// Course : CSC2430
//
// Name: Kai Thai
//
// Date : 04/09/ 2019
//

//header files
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>

using namespace std;



// Converts one string parameter into integer
// Params: string which is a valid integer
// Returns: an integer equivalent
int stringToInteger(string strInput) {
	return stoi(strInput);
}


// Checks that input string represents valid time
// Params: string in format hhmmss
// Returns: true if the parameter is a valid call start time
//			- Should be 6 digits long
//			- First 2 digits: Hour, between 00 and 23
//			- Middle 2 digits: Minute, between 00 and 59
//			- Last 2 digits: Second, between 00 and 59
//			false otherwise
bool isTimeValid(string startTime) {

	int timeHour, timeMinute, timeSecond;

	// check that string is exactly 6 digits long
	if (startTime.length() != 6) {
		return false;
	}

	// check that the string contains only digits.
	for (size_t i = 0; i < startTime.length(); i++) {
		if (!isdigit(startTime[i])) {
			return false;
		}
	}

	// check first 2 digits: Hour, between 00 and 23
	timeHour = stringToInteger(startTime.substr(0, 2));
	if (timeHour < 0 || timeHour > 23) {
		return false;
	}

	// check middle 2 digits: Minute, between 00 and 59
	timeMinute = stringToInteger(startTime.substr(2, 2));
	if (timeMinute < 0 || timeMinute > 59) {
		return false;
	}

	// check last 2 digits: Second, between 00 and 59
	timeSecond = stringToInteger(startTime.substr(4, 2));
	if (timeSecond < 0 || timeSecond > 59) {
		return false;
	}

	// pass all checks
	return true;
}


// Checks that input string represents valid phone number
// Params: string representation of phone number
// Returns: true if the parameter is a valid phone number
//			- Should be 12 characters long
//			- Starting with +1, +33, or +852
//			false otherwise
bool isPhoneNumValid(string phoneNumber) {

	// check that phone number is 12 characters long
	if (phoneNumber.length() != 12) {
		return false;
	}

	// check that number Starting with +1, +33, or +852
	return (phoneNumber.substr(0, 2) == "+1" || phoneNumber.substr(0, 3) == "+33" || phoneNumber.substr(0, 4) == "+852");
}


// Checks that input string represents valid duration
// Params: string representation of duration
// Returns: true if the parameter is a valid duration string
//			- Should be less than 10 characters long
//			- consisting of number digits between 0 and 9
//			false otherwise
bool isDurationValid(string inputDuration)
{
	// check that Duration is less than 10 characters long
	if (inputDuration.length() > 9) {
		return false;
	}

	// check that Duration consists of number digits between 0 and 9
	for (size_t i = 0; i < inputDuration.length(); i++) {
		if (!isdigit(inputDuration[i])) {
			return false;
		}
	}

	// pass all checks
	return true;
}


// Produce user friendly version of call start time
// Params: string of exactly 6 characters in format hhmmss
// Returns: new string formatted HH:MM:SS
string formatTime(string inputTime) {
	string CallHour = inputTime.substr(0, 2);
	string CallMinutes = inputTime.substr(2, 2);
	string CallSeconds = inputTime.substr(4, 2);
	string formattedTime = CallHour + ":" + CallMinutes + ":" + CallSeconds;
	return formattedTime;
}


// Produce user friendly 3-alpha country code string for provided phone number
// Params: string representation of phone number
// Returns: Country code "NA" for country code +1,
//			Country code "FR" for country code +33,
//			Country code "HK" for country code +852,
//			"ERROR" for others
string getCountry(string phoneNumber)
{
	//if country code is +1 return NA
	if (phoneNumber.substr(0, 2) == "+1") {
		return "NA";
	}
	//if country code is +33 return FR
	else if (phoneNumber.substr(0, 3) == "+33") {
		return "FR";
	}
	//if country code is +852 return HK
	else if (phoneNumber.substr(0, 4) == "+852") {
		return "HK";
	}
	////if country code is not +1 or +33 or +852 return error
	else {
		return "ERROR";
	}
}


// Produce formatted local phone number string
// Params: string representation of phone number
// Returns: Returns a formatted local phone number string
//		Country code +1  :  "(XXX)-XXX-XXXX"
//		Country code +33 :  "0X XX XX XX XX"
//		Country code +852:  "XXXX XXXX"
// 		for others : "ERROR"
string getLocalPhone(string phoneNumber)
{
	//if country code is +1 formatted phone number will be "(XXX)-XXX-XXXX"
	if (phoneNumber.substr(0, 2) == "+1") {
		return string("(") + phoneNumber.substr(2, 3)
			+ string(")") + "-" + phoneNumber.substr(5, 3)
			+ "-" + phoneNumber.substr(8, 4);
	}
	//if country code is +33 formatted phone number will be  "0X XX XX XX XX"
	else if (phoneNumber.substr(0, 3) == "+33") {
		return "0" + phoneNumber.substr(3, 1) + " " + phoneNumber.substr(4, 2) + " "
			+ phoneNumber.substr(6, 2) + " " + phoneNumber.substr(8, 2) + " " + phoneNumber.substr(10, 2);
	}
	//if country code is +852 formatted phone number will be "XXXX XXXX"
	else if (phoneNumber.substr(0, 4) == "+852") {
		return phoneNumber.substr(4, 4) + " " + phoneNumber.substr(8, 4);
	}
	//if country code is not +1 or +33 or +852 return error
	else {
		return "ERROR";
	}
}

int main()

{
	//File read and ask for user input.
	ifstream fileCheck;
	string fileName, fileLine;
	cout << "File Name:";
	//store user input into fileName
	cin >> fileName;
	//open user input file
	fileCheck.open(fileName);
	//read file line by line
	getline(cin, fileName);

	//check if file is sucessfully opened.
	//if it failed to open output message and end program
	if (!fileCheck.is_open()) {
		cout << "Failed to open file " << endl;
		return -1;
	}
	cout << left << setw(10) << "Time" << setw(9) << "Country" << setw(16) << "Phone Number" << "Duration" << endl;

	//get file line by line untill end of file
	while (!fileCheck.eof()) {

		//if fileCheck line is readable and can be stored into fileLine
		//and the size is greater than 1
		if (getline(fileCheck, fileLine) && fileLine.size() > 1) {
			//initializing variable
			string callTime, phoneNumber, callDuration;
			// Read each field of the line
			istringstream fileInput(fileLine);
			fileInput >> callTime;
			fileInput >> phoneNumber;
			fileInput >> callDuration;

			//check if time valid and print call time in hh:mm:ss format
			if (isTimeValid(callTime)) {
				cout << left << setw(10) << (formatTime(callTime));
			}
			else {
				cout << left << setw(10) << "ERROR";
			}

			// check if phone number valid and print country and phone number
			if (isPhoneNumValid(phoneNumber)) {
				cout << left << setw(9) << (getCountry(phoneNumber));
				cout << left << setw(16) << (getLocalPhone(phoneNumber));
			}
			else {
				cout << left << setw(9) << "ERROR" << setw(16) << "ERROR";
			}


			// check if duration valid and print duration in hh:mm format
			if (isDurationValid(callDuration)) {
				int inputMinutes, inputSeconds;
				inputSeconds = stringToInteger(callDuration);
				inputMinutes = inputSeconds / 60;
				inputSeconds = inputSeconds % 60;

				cout << right << inputMinutes << ":" << setw(2) << setfill('0') << inputSeconds << setfill(' ');
			}
			else {
				cout << "-1:-1";
			}
			//print a new line at end of line
			cout << endl;
		}


	}
	return 0;
}


