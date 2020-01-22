#ifndef _CALLDB_H_
#define _CALLDB_H_

#include <fstream>
#include <string>
#include <iostream>
#include <cctype>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include <iomanip>

using namespace std;

// Stores raw information about one call
struct CALL {
	string start;
	string phonenum;
	string duration;
};

// Get Duration of call as an int
unsigned int GetDurationCall(CALL& call);

// Get formatted start time of call
string GetStartCall(CALL& call);

// Get country code of call
string GetCountryCodeCall(CALL& call);

// Get local phone number of call
string GetPhoneNumberCall(CALL& call);

// Maximum number calls in call database
const int MAXCALLS = 15;
// Call database
struct CALLDB {
	CALL callLog[MAXCALLS]; // Stores calls in database
	unsigned int numCalls; // Number of calls stored
};

// Initializes call database to have store no calls
void InitCallDB(CALLDB& calldb);

// Load database with calls stored in a file
unsigned int LoadCallDB(CALLDB& calldb, istream& fin);

// Get count of call records
unsigned int GetCountCallDB(CALLDB& calldb);

// Retrieve call records
bool GetCallInCallDB(CALLDB& calldb, unsigned int index, CALL& call);

// Return first index >= of call w/ matching phone number prefix, or -1
int FindByPhonePrefixInCallDB(CALLDB& calldb, unsigned int startIndex, string prefix);

#endif