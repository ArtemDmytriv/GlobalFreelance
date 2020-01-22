// Title: Lab 2 - PhoneCalls.cpp
//
// Purpose: read in a list of phone call records from a file, and output them
// in a more user - friendly format to the standard output(cout).
//
// Course : CSC2430
//
// Name: Kai Thai
//
// Date : 05/02/ 2019
//



#include "CallDb.h"

int main()
{
	//initiate varible
	CALLDB calldb;
	InitCallDB(calldb);
	string fileName;
	string str;

	//request user to input file name
	cout << "File name :";
	getline(cin, fileName);
	ifstream fname(fileName.c_str());
	//check if file name is valid
	if (!fname.is_open())
	{
		cout << "Can't open '" + fileName + "'" << endl;
		return 0;
	}
	//initiate varible
	int dropped = LoadCallDB(calldb, fname);
	int totalDuration = 0;
	int callDuration = 0;
	//display read logs
	cout << "Log successfully read into database, " << calldb.numCalls << " records added";
	if (dropped != 0)
	{
		cout << ", dropped " << dropped;
	}
	cout << endl;
	cout << "Contents of Call Database" << endl;
	//if there is no read log
	if (calldb.numCalls == 0)
	{
		cout << "No Record" << endl;
		cout << endl;
	}
	//if there is read log
	else if (calldb.numCalls != 0)
		cout << left << setw(10) << "Time" << setw(9) << "Country" << setw(16) << "Phone Number" << "Duration" << endl;
	//read and display startTimeDate,endTimeDate, Ciuntry code,phone number, Duration 
	for (int i = 0; i < calldb.numCalls; i++) {
		cout << GetCallStart(calldb.callLog[i]) << "\t" << GetCallEnd(calldb.callLog[i]) << "\t" << GetCallCountryCode(calldb.callLog[i]);
		cout << "\t" << GetCallPhoneNumber(calldb.callLog[i]) << "\t";
		totalDuration += GetCallDuration(calldb.callLog[i]);
		callDuration += GetCallDuration(calldb.callLog[i]);
		cout.fill('0');
		cout << setw(2) << callDuration / 60 << ":" << setw(2) << callDuration % 60 << endl;
		callDuration = 0;
	}
	//display total duration of all the calls above
	cout.fill('0');
	if (calldb.numCalls != 0)
	{
		cout << setw(2) << "Total duration of all calls:\t" << totalDuration / 60 << ":" << totalDuration % 60 << endl;
	}
	bool endFlag = true;
	//run E164 prefix query
	while (endFlag = true) {
		string prefix;
		int startIndex = 0;
		totalDuration = 0;
		cout << "E164 prefix for query : ";
		getline(cin, prefix);
		//if its a enter end the program
		if (prefix.empty()) {
			return 0;
		}
		//if there is no record
		if (calldb.numCalls == 0)
		{
			cout << "No Record" << endl;
			cout << endl;
		}
		///read and display startTimeDate,endTimeDate, Ciuntry code,phone number, Duration of the requested E164 prefix
		while (FindByPhonePrefixInCallDB(calldb, startIndex, prefix) >= 0) {

			startIndex = FindByPhonePrefixInCallDB(calldb, startIndex, prefix);
			cout << GetCallStart(calldb.callLog[startIndex]) << "\t" << GetCallEnd(calldb.callLog[startIndex]) << "\t" << GetCallCountryCode(calldb.callLog[startIndex]);
			cout << "\t" << GetDurationCall(calldb.callLog[startIndex]) << "\t";
			totalDuration += GetDurationCall(calldb.callLog[startIndex]);
			cout << GetCallDuration(calldb.callLog[startIndex]) << endl;
			startIndex++;
			if (startIndex == 0)
			{
				cout << "No Record" << endl;
				cout << endl;
			}


		}
		//display total duration of all the calls above
		if (calldb.numCalls != 0)
		{
			cout << "Total duration of all calls:\t" << totalDuration / 60 << ":" << totalDuration % 60 << endl;
		}
	}
	return 0;
}
