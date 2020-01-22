// Class: Person
//
//

#pragma once
#include <iostream>

using namespace std;

class Person
{
public:
	Person();
	Person(string);
	virtual string getName();
	//virtual void setName(string);
	virtual int getTotal();
	virtual void setTotal(int);
	virtual void print() = 0;

private:
	int total;
	string name;

};