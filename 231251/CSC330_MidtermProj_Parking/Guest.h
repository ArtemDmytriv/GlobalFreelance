// Class: Guest
// Inherits from Person
//

#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Guest : public Person
{
public:
	Guest();
	Guest(string, int);
	string getLicenseP();
	void setLicenseP(string);
	string getTicket();
	void setTicket(string);
	virtual void print();

private:
	int timereserved;
	string lplate;
	string ticket;
};