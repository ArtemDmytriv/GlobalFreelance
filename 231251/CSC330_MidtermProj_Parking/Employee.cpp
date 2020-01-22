// Employee Implementation File
//

#include <iostream>
#include "Person.h"
#include "Employee.h"
#include <string>

Employee::Employee()
{

}

Employee::Employee(string inName, string inEmplid, string inPassword) : Person(inName)
{
	emplid = inEmplid;
	password = inPassword;
}

void Employee::print()
{
	cout << "Employee Name: " << Person::getName() << ", Employee ID: " << emplid << ", Password: " << password << endl;
}

bool Employee::IsValidEmpid(string empid)
{
	if (empid == emplid)
		return true;
	else
		return false;
}

bool Employee::IsValidPass(string pass)
{
	if (pass == password)
		return true;
	else
		return false;
}
