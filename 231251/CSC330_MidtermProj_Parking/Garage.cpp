#include <iostream>
#include "Garage.h"

using namespace std;

Garage::Garage()
{

}

Garage::Garage(int Floors, int CarsPerFloor, int Hourlyrate, int Monthlyfee)
{
	floors = Floors;
	carsperfloor = CarsPerFloor;
	hourlyrate = Hourlyrate;
	monthlyfee = Monthlyfee;
}

void Garage::readGarage(ifstream & garFile)
{
	string line;
	int nfloor = floors;
	while (nfloor--) {
		int ncars = carsperfloor;
		while (--ncars) {
			getline(garFile, line, ',');
			if (line[0] != ' ') {
				line = " " + line;
			}
			if (*(line.end() - 1) == '*') {
				line.erase(line.end() - 1);
				parkspot.push_back(make_pair(1, line));
			}
			else {
				parkspot.push_back(make_pair(0, line));
			}
		}
		getline(garFile, line, '\n');
		parkspot.push_back(make_pair(0, line));
	}	
}

void Garage::writeGarage(ofstream& garFile)
{
	for (int i = 0; i < floors; i++) {
		for (int j = 0; j < carsperfloor; j++) {
			garFile << parkspot[i * carsperfloor + j].second;
			if (parkspot[i*carsperfloor + j].first == 1) {
				garFile << "*";
			}
			if (j != carsperfloor - 1)
			garFile << ",";
		}
		garFile << endl;
	}
}

string Garage::findSpot(string type)
{	
	string spot;
	if (type == "emp") {
		auto it = parkspot.begin();
		for (; it != parkspot.begin() + 8; it++) {
			if (!it->first) {
				it->first = 1;
				spot = it->second;
				break;
			}
		}

	}
	else if (type == "mem") {
		auto it = parkspot.begin() + 8;
		for (; it != parkspot.begin() + 3 * carsperfloor; it++) {
			if (!it->first) {
				it->first = 1;
				spot = it->second;
				break;
			}
		}
	}
	else {
		auto it = parkspot.begin() + 3 * carsperfloor;
		for (; it != parkspot.end(); it++) {
			if (!it->first) {
				it->first = 1;
				spot = it->second;
				break;
			}
		}
	}

	return spot;
}

void Garage::clearSpot(string spot)
{
	for (auto & sp : parkspot) {
		if (sp.second == spot) {
			sp.first = 0;
			break;
		}
	}
}

void Garage::print()
{
	for (int i = 0; i < floors; i++) {
		cout << endl << i + 1 << " Floor: " << endl;
		for (int j = 0; j < carsperfloor; j++) {
			cout << parkspot[i * carsperfloor + j].second;
			if (parkspot[i * carsperfloor + j].first == 0) {
				cout << ": Free " << "\t";
			}
			else {
				cout << ": Occupied " << "\t";
			}

			if ((j + 1) % 4 == 0) {
				cout << endl;
			}
		}
	}
}
