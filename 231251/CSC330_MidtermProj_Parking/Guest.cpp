// Guest Implementation File
//

#include <iostream>
#include "Person.h"
#include "Guest.h"
#include <string>
#include <vector>

Guest::Guest()
{
	timereserved = 0;
}

Guest::Guest(string inName, int inTimeReserved) : Person(inName)
{
	timereserved = inTimeReserved;
}

string Guest::getLicenseP()
{
	return lplate;
}

void Guest::setLicenseP(string lp)
{
	lplate = lp;
}

string Guest::getTicket()
{
	return ticket;
}

void Guest::setTicket(string Tk)
{
	ticket = Tk;
}

void Guest::print()
{
	cout << "Guest Name: " << Person::getName() << ", License Plate #: " << lplate << endl;
}