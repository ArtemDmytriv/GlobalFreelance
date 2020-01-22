#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Member.h"

using namespace std;

class Apartment
{
public:
	Apartment();
	Apartment(string, string); // cant figure out the person * part, displays ccccccc for the tenants name from file
	Apartment & ApartmentRead(ifstream & apFile, vector<Member> & mems); // read in apartment database
	bool roomNumCheck(string); // will be used to check if the number entered by the number matches
	void setPerson(Person * pers);
	virtual void print();

private:
	string aptno;
	string avail;
	Person * pers;
};