#include "calldb.h"

// Get Duration of call as an int
unsigned int GetDurationCall(CALL& call){
	return stoi(call.duration);
}

// Get formatted start time of call
string GetStartCall(CALL& call){
	return call.start;
}

// Get country code of call
string GetCountryCodeCall(CALL& call){
	//if country code is +1 return NA
	if (call.phonenum.substr(0, 2) == "+1") {
		return "NA";
	}
//if country code is +33 return FR
	else if (call.phonenum.substr(0, 3) == "+33") {
		return "FR";
	}
	//if country code is +852 return HK
	else if (call.phonenum.substr(0, 4) == "+852") {
		return "HK";
	}
	////if country code is not +1 or +33 or +852 return error
	else {
		return "ERROR";
	}
	}

// Get local phone number of call
string GetPhoneNumberCall(CALL& call) {
	//if country code is +1 formatted phone number will be "(XXX)-XXX-XXXX"
	if (call.phonenum[1] == '1') {
		return string("(") + call.phonenum.substr(2, 3)
			+ string(")") + "-" + call.phonenum.substr(5, 3)
			+ "-" + call.phonenum.substr(8, 4);
	}
	//if country code is +33 formatted phone number will be  "0X XX XX XX XX"
	else if (call.phonenum.substr(0, 3) == "+33") {
		return "0" + call.phonenum.substr(3, 1) + " " + call.phonenum.substr(4, 2) + " "
			+ call.phonenum.substr(6, 2) + " " + call.phonenum.substr(8, 2) + " " + call.phonenum.substr(10, 2);
	}
	//if country code is +852 formatted phone number will be "XXXX XXXX"
	else if (call.phonenum.substr(0, 4) == "+852") {
		return call.phonenum.substr(4, 4) + " " + call.phonenum.substr(8, 4);
	}
	//if country code is not +1 or +33 or +852 return error
	else {
		return "ERROR";
	}
}

// Initializes call database to have store no calls
void InitCallDB(CALLDB& calldb){
	calldb.numCalls = 0;
}

// Load database with calls stored in a file
unsigned int LoadCallDB(CALLDB& calldb, istream& fin){
	CALL temp;
	while(!fin.eof()){
		getline(fin, temp.start, ' ');
	}
}

// Get count of call records
unsigned int GetCountCallDB(CALLDB& calldb) {
	return calldb.numCalls;
}

// Retrieve call records
bool GetCallInCallDB(CALLDB& calldb, unsigned int index, CALL& call) {
	if (index >= 0 && index < calldb.numCalls) {
		call = calldb.callLog[index];
		return true;
	}
	return false;


}

// Return first index >= of call w/ matching phone number prefix, or -1
int FindByPhonePrefixInCallDB(CALLDB& calldb, unsigned int startIndex, string prefix) {
	for (int i = startIndex; i < calldb.numCalls; i++) {
		if (calldb.callLog[i].phonenum.find(prefix, 0) != string::npos) return i;
	}
	return -1;
}
