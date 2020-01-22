// Class: Member
// Inherits from Person
//

#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Member : public Person
{
public:
	Member();
	Member(string);
	Member(string, string);
	//Member(string, string, Apartment&);
	//void readMembers(ifstream &empFile); // read in employee database
	string getMemid();
	virtual void print();
	bool memidCheck(string); //

private:
	string memid;
	//Apartment number;
};