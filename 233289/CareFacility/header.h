#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class CustomerAccount;
class Procedure;
class Pharmacy;


void mainMenu(vector<CustomerAccount>& accs, vector<Procedure*>& proc, vector<Pharmacy*>& med);
void careIn(vector<CustomerAccount>& accs, vector<Procedure*>& proc, vector<Pharmacy*>& med);
void careMenu(vector<CustomerAccount>& accs, vector<Procedure*>& proc);
void medMenu(vector<CustomerAccount>& accs, vector<Pharmacy*>& med);

CustomerAccount* searchMenu(vector<CustomerAccount>& accs, CustomerAccount* selected);
CustomerAccount * searchAcc(vector<CustomerAccount>& acc, string fullname);
CustomerAccount * searchAcc(vector<CustomerAccount>& acc, int number);

void sortAcc(vector<CustomerAccount>& acc);
bool NameComp(CustomerAccount&, CustomerAccount&);
bool NumComp(CustomerAccount&, CustomerAccount&);

void outData(vector<CustomerAccount>& acc, ostream& os);

class CustomerAccount {
private:
	string fullName;
	int number;

	int stayedDays;
	double dailyRate;

	vector<Procedure*> procedures;
	vector<Pharmacy*> mediacations;
public:
	CustomerAccount() : fullName("none"), number(0), stayedDays(0), dailyRate(0) {}
	CustomerAccount(string n, int num, int d, double r) : fullName(n), number(num), stayedDays(d), dailyRate(r) {}
	
	void PrintData(ostream& os);

	void addMed(Pharmacy* med) {
		mediacations.push_back(med);
	}
	void addProc(Procedure* proc) {
		procedures.push_back(proc);
	}

	string getName() {
		return fullName;
	}
	int getNumber() {
		return number;
	}
	int gerStayedDays() {
		return stayedDays;
	}
	double getRate() {
		return dailyRate;
	}

	double totalSum();
};

class Procedure {
private:
	string name;
	double price;
public:

	Procedure(): name("None"), price(0.0) {}
	Procedure(string name, double price = 0.0) : name(name), price(price) {}
	~Procedure() {}

	string getName() const {
		return name;
	}
	double getPrice() const {
		return price;
	}

	void setName(string name){
		this->name = name;
	}
	void setPrice(double p) {
		price = p;
	}
};

class Pharmacy {
private:
	string name;
	double price;
public:

	Pharmacy() : name("None"), price(0.0) {}
	Pharmacy(string name, double price = 0.0) : name(name), price(price) {}
	~Pharmacy() {}

	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}

	void setName(string name) {
		this->name = name;
	}
	void setPrice(double p) {
		price = p;
	}
};


