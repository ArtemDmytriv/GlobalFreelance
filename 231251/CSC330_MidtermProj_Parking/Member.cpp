// Guest Implementation File
//
#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"
#include "Member.h"

Member::Member()
{
	memid = "";
}

Member::Member(string inName) : Person(inName)
{
}

Member::Member(string inName, string inMemid) : Person(inName)
{
	memid = inMemid;
}

//Member::Member(string inName, string inMemid, Apartment &inNo) : Person(inName)
//{
//	number = inNo;
//	memid = inMemid;
//}

string Member::getMemid()
{
	return memid;
}

bool Member::memidCheck(string inMemid) // need function to work
{
	if (memid == inMemid)
		return true;
	else
		return false;
}

void Member::print()
{
	cout << "Tenant name: " << Person::getName() << ", ID: " << memid << endl;
}