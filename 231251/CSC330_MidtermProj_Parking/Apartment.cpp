#include <iostream>
#include <fstream>
#include "Apartment.h"
#include <string>

using namespace std;

Apartment::Apartment()
{
	aptno = "";
	avail = "";
}

Apartment::Apartment(string inAptno, string inAvail)
{
	aptno = inAptno;
	avail = inAvail;
}

Apartment & Apartment::ApartmentRead(ifstream & apFile, vector<Member> & mems)
{
		string restofline, name;

		getline(apFile, aptno, ':');
		getline(apFile, restofline, ' ');
		getline(apFile, avail, ':');
		getline(apFile, restofline, ' ');
		getline(apFile, name);
		//Apartment * apartInfo = new Apartment(aptno, avail);
		if (name != "N/A") {
			for (int i = 0; i < mems.size(); i++) {
				if (mems[i].getName() == name) {
					this->setPerson(&mems[i]);
					break;
				}
			}
		}
		return *this;
		
}

bool Apartment::roomNumCheck(string inAptno) // need function to work
{
	if (aptno == inAptno)
		return true;
	else
		return false;
}

void Apartment::setPerson(Person * pers)
{
	this->pers = pers;
}

void Apartment::print()
{
	cout << "Apartment Room: " << aptno << ", Availability: " << avail << ", Tenant: ";
	if (pers != nullptr) {
		cout << pers->getName() << endl;
	}
	else {
		cout << "N/A" << endl;
	}
}