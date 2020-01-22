#include <iostream>
#include <fstream>
#include <string>
#include <ctime> // for srand - member development maybe
#include <cstdlib> // for srand - generate random ticket for guest
#include <iomanip>
#include <vector>
#include "Apartment.h"
#include "Garage.h"
#include "Person.h"
#include "Member.h"
#include "Employee.h"
#include "Guest.h"

using namespace std;

void MemberGarMenu(Garage & gar, vector<Apartment> & apartBuild, vector<Member> & members);
void EmployeeGarMenu(Garage & gar, vector<Employee> & employees);
void HourlyRateMenu();
void GuestMenu(Garage& gar);

int main(int argc, char * argv[])
{

	// cin entry options for users
	string userChoice;
	int guestticket = 0; // random number generated for guest parking

	// For memberList.txt
	ifstream memFile;
	string MemberFile;
	MemberFile = argv[1];
	memFile.open(MemberFile);

	// For apartmentBuilding.txt
	ifstream apFile;
	string ApartFile;
	ApartFile = argv[2];
	apFile.open(ApartFile);

	// For Employee.txt
	ifstream empFile;
	string EmployeeFile;
	EmployeeFile = argv[3];
	empFile.open(EmployeeFile);


	// For Garage.txt
	ifstream garFile;
	string GarageFile;
	GarageFile = argv[4];
	garFile.open(GarageFile, ios::in);

	if (memFile.fail())
	{
		cerr << "Error Opening MemberList database!" << endl;
		exit(1);
	}

	if (apFile.fail())
	{
		cerr << "Error Opening Apartment Building database!" << endl;
		exit(1);
	}

	if (empFile.fail())
	{
		cerr << "Error Opening Employee database!" << endl;
		exit(1);
	}

	if (garFile.fail())
	{
		cerr << "Error Opening Garage database!" << endl;
		exit(1);
	}

	// variables to use to read database input
	string name;
	string aptno;
	string avail;
	string id;
	string password;
	string restofline;

	////////////// MEMBER TXT READ IN
	vector <Member> members;
	while (!memFile.eof())
	{
		getline(memFile, restofline, ':');
		getline(memFile, restofline, ' ');
		getline(memFile, name);
		getline(memFile, restofline, ':');
		getline(memFile, restofline, ' ');
		getline(memFile, id);
		memFile.ignore(1);
		Person * member = new Member(name, id);
		members.push_back(Member(name, id));
	}
	cout << "Total Members: " << members.size() << endl;
	Person * member = new Member(); // needs to be redeclared outside loop

	vector <Member>::iterator indexItm;
	for (indexItm = members.begin(); indexItm != members.end(); indexItm++)
	{
		indexItm->print();
	}

	////////////// APARTMENT TXT READ IN
	vector <Apartment> apartBuild;
	
	while (!apFile.eof()) {
		Apartment * apart = new Apartment;
		apart->ApartmentRead(apFile, members);
		apartBuild.push_back(*apart);
	}
	vector <Apartment>::iterator indexItap;
	for (indexItap = apartBuild.begin(); indexItap != apartBuild.end(); indexItap++)
	{
		indexItap->print();
	}

	////////////// EMPLOYEE TXT READ IN
	vector <Employee> employees;
	while (!empFile.eof())
	{
		getline(empFile, restofline, ':');
		getline(empFile, restofline, ' ');
		getline(empFile, name);
		getline(empFile, restofline, ':');
		getline(empFile, restofline, ' ');
		getline(empFile, id);
		getline(empFile, restofline, ':');
		getline(empFile, restofline, ' ');
		getline(empFile, password);
		empFile.ignore(1);
		Person * employee = new Employee(name, id, password);
		employees.push_back(Employee(name, id, password));
	}
	Person * employee = new Employee();
	
	vector <Employee>::iterator indexIte;
	for (indexIte = employees.begin(); indexIte != employees.end(); indexIte++)
	{
		indexIte->print();
	}


	////////////// GARAGE TXT READ IN
	
	Garage gar(5, 16, 15, 300);
	gar.readGarage(garFile);

	///////////////////////////////////
	
	garFile.close();
	memFile.close();
	apFile.close();
	empFile.close();

	// -------------------------MENU FOR USER-------------------------
	cout << "Greetings user! Welcome to the CSC 332 Parking Garage." << endl;
	do {

		bool flag;

		cout << "Please choose from the following options:" << endl;
		cout << "1) Guest Parking" << endl;
		cout << "2) Member Parking" << endl;
		cout << "3) Employee Parking" << endl;
		cout << "4) Garage info" << endl;
		cout << "5) Exit" << endl;

		getline(cin, userChoice);
		
		if (userChoice == "1")
		{
			GuestMenu(gar);

		}

		else if (userChoice == "2")
		{
			MemberGarMenu(gar, apartBuild, members);
		}

		else if (userChoice == "3")
		{
			EmployeeGarMenu(gar, employees);
		}

		else if (userChoice == "4")
		{
			cout << "Printing Garage info: " << endl;
			gar.print();
		}

		else if (userChoice == "5")
		{
			cout << "Take care & come back soon!" << endl;

			ofstream garOutFile;
			garOutFile.open(GarageFile, ios::out);
			gar.writeGarage(garOutFile);
			garOutFile.close();

			
			exit(0);
		}
		else
			cout << "You entered an invalid command, please try again.\n" << endl;

	} while (userChoice != "5");

	exit(0);
}

void GuestMenu(Garage& gar) {
	int choice;
	do {
		cout << "\nGuestMenu\n";
		cout << "1) Get spot\n";
		cout << "2) Free spot\n";
		cout << "3) return\n";
		cin >> choice;
		cin.get();
	} while (choice < 1 || choice > 3);
	
	string userChoice;
	int timereserv, ticket;
	string spot;
	Guest* guest;
	switch (choice)
	{
	case 1:
		HourlyRateMenu();
		cout << "How long would you like to stay here for?" << endl;
		cin >> timereserv;
		cin.get();
		cout << "Please enter you first and last name." << endl;
		getline(cin, userChoice);
		guest = new Guest(userChoice, timereserv);
		cout << "Great, now please enter your license plate #:" << endl;
		getline(cin, userChoice);
		guest->setLicenseP(userChoice);
		cout << "Thank you, please wait while we generate a ticket # for you..." << endl;
		srand(time(0));
		ticket = rand() % 1000;
		guest->setTicket(to_string(ticket));
		cout << "Please leave this ticket on your dashboard. " << ticket << endl;
		cout << "Your parkspot is " << gar.findSpot("gst") << endl;
		break;
	case 2:
		cout << "Enter number of spot to free\n";
		cin >> spot;
		cin.get();
		spot = " " + spot;
		gar.clearSpot(spot);
		break;
	case 3:
		return;
	default:
		return;
	}
	
}

void EmployeeGarMenu(Garage & gar, vector<Employee> & employees) {
	int choice;
	cout << "\nEmployeeGarageMenu\n1) Get a spot\n2) Free a spot\n3) Return\n";
	cin >> choice;
	while (choice < 0 && choice > 4) {
		cout << "Invalid input, try again\n";
		cout << "1) Get a spot\n2) Free a spot\n3) Return\n";
		cin >> choice;
	}
	cin.get();
	int flag;
	string userChoice;
	string spot;
 
	switch (choice) {
	case 1: {
		flag = 0;
		cout << "Welcome employee, please enter your Employee ID." << endl;
		getline(cin, userChoice);
		for (auto emp : employees) {
			if (emp.IsValidEmpid(userChoice)) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			flag = 0;
			cout << "Now enter your password." << endl;
			getline(cin, userChoice);
			for (auto emp : employees) {
				if (emp.IsValidPass(userChoice)) {
					cout << "Welcome to garage " << emp.getName() << endl;
					cout << "Your parkspot: " << gar.findSpot("emp") << endl;
					cin.get();
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "Invalid password" << endl;
			}
		}
		else {
			cout << "Invalid EmpID" << endl;
		}
		break;
	}
	case 2: {
		cout << "\nPlease enter your spot: ";
		cin >> spot;
		cin.get();
		spot = " " + spot;
		gar.clearSpot(spot);
		cout << "Spot " << spot << " now is free\n\n";
		break;
	}

	default: return;
	}
}

void MemberGarMenu(Garage & gar, vector<Apartment> & apartBuild, vector<Member> & members) {
	int choice;

	cout << "\nMemberGarageMenu\n1) Get a spot\n2) Free a spot\n3) Return\n";
	cin >> choice;
	while (choice < 0 && choice > 4) {
		cout << "Invalid input, try again\n";
		cout << "1) Get a spot\n2) Free a spot\n3) Return\n";
		cin >> choice;
	}
	cin.get();
	int flag;
	string userChoice;
	string spot;

	switch (choice) {
	case 1: {

		flag = 0;
		cout << "Welcome member, please enter your room number." << endl;
		getline(cin, userChoice);
		for (auto apart : apartBuild) {
			if (apart.roomNumCheck(userChoice)) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			flag = 0;
			cout << "Now enter your member id code." << endl;
			getline(cin, userChoice);
			for (auto mem : members) {
				if (mem.memidCheck(userChoice)) {
					cout << "Welcome to garage " << mem.getName() << endl;
					cout << "Your parkspot: " << gar.findSpot("mem") << endl;

					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "Invalid ID" << endl;
			}
		}
		else {
			cout << "Invalid room number" << endl;
		}
		break;
	}
	case 2: {
		cout << "\nPlease enter your spot: ";
		cin >> spot;
		cin.get();
		spot = " " + spot;
		gar.clearSpot(spot);
		cout << "Spot " << spot << " now is free\n\n";
		break;
	}

	default: return;
	}

}


void HourlyRateMenu()
{
	cout << "Guest Parking Rates Menu:" << endl;
	cout << "1 hour = $15" << setw(20) << "2 hours = $30" << setw(19) << "3 hours = $45" << endl;
	cout << "4 hours = $60" << setw(19) << "5 hours = $75" << setw(19) << "6 hours = $90" << endl;
	cout << "7 hours = $105" << setw(19) << "8 hours = $120" << setw(19) << "9 hours = $135" << endl;
	cout << "10 hours = $150" << setw(19) << "11 hours = $165" << setw(19) << "12 hours = $180" << endl;
	cout << "13 hours = $195" << setw(19) << "14 hours = $210" << setw(19) << "15 hours = $225" << endl;
	cout << "16 hours = $240" << setw(19) << "17 hours = $255" << setw(19) << "18 hours = $270" << endl;
	cout << "19 hours = $285" << setw(19) << "20 hours = $300" << setw(19) << "21 hours = $315" << endl;
	cout << "21 hours = $330" << setw(19) << "21 hours = $345" << setw(19) << "24 hours = $360" << endl;
	cout << "Please enter the hour number only." << endl;
}