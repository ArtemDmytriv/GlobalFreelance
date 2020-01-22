// Class: Employee
// Inherits from Person
//

#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Employee : public Person
{
public:
	Employee();
	Employee(string, string, string);
	//void readEmployees(ifstream &empFile); // read in employee database
	virtual void print();
	bool IsValidEmpid(string);
	bool IsValidPass(string);

private:
	string emplid;
	string password;
};