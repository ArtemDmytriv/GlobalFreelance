#include "header.h"

void CustomerAccount::PrintData(ostream& os) {
	os << "FullName - " << fullName << endl;
	os << "Was Stayed " << stayedDays << " days" << endl;
	os << "DailyRate = " << dailyRate << "$ per day" << endl;

	os << "Procedures:" << endl;
	for (int i = 0; i < procedures.size(); i++) {
		os << procedures[i]->getName() << " - " << procedures[i]->getPrice() << " $" << endl;
	}
	os << "Pharmacy:" << endl;
	for (int i = 0; i < mediacations.size(); i++) {
		os << mediacations[i]->getName() << " - " << mediacations[i]->getPrice() << " $" << endl;
	}
	os << "TotalSum = " << this->totalSum() << " $" << endl;
}

double CustomerAccount::totalSum() {
	double sum = stayedDays * dailyRate;
	for (int i = 0; i < procedures.size(); i++) {
		sum += procedures[i]->getPrice();
	}
	for (int i = 0; i < mediacations.size(); i++) {
		sum += mediacations[i]->getPrice();
	}
	return sum;
}


void mainMenu(vector<CustomerAccount>& acc, vector<Procedure*>& proc, vector<Pharmacy*>& med)
{
	cout << "--------- MainMenu ---------" << endl;
	cout << "Enter (1) Check IN Care Facility with proper paperwork." << endl;
	cout <<	"Enter (2) Enter Type of Care" << endl;
	cout << "Enter (3) Enter medications or items needed(Could be a SPA)" << endl;
	cout << "Enter (4) search for Customer by name or number" << endl;
	cout << "Enter (5) sort customers by name or number" << endl;
	cout << "Enter (6) Check OUT - print Date, Name and total charges to screen. " << endl;
	cout << "Enter (7) Check OUT - print Date, Name and total charges to screen output file. (receipt)" << endl;
	cout << "Enter (8) to Quit" << endl;
}

void careIn(vector<CustomerAccount>& accs, vector<Procedure*>& proc, vector<Pharmacy*>& med) {
	string FullName;
	int number;
	int stayedDay;
	double rate;

	cout <<" Enter full name : " << endl;
	getline(cin, FullName);
	cin.clear();
	cout << " Enter ID number : ";
	cin >> number;
	cin.clear();
	cout << " Enter number of stayed days : ";
	cin >> stayedDay;
	cin.clear();
	cout << " Enter daily rate : ";
	cin >> rate;
	cin.clear();
	cout << endl;
	CustomerAccount* cust = new CustomerAccount(FullName, number, stayedDay, rate);
	

	cout << "List of avaliable mediacations:" << endl;
	for (int i = 0; i < med.size(); i++) {
		cout << i + 1 <<") " << med[i]->getName() << " - " << med[i]->getPrice() << endl;
	}
	cout << "Enter number of procedure to add, or (0) to continue" << endl;
	int choice;
	cin >> choice;
	while (choice != 0) {
		cust->addMed(med[choice - 1]);
		cin >> choice;
	}

	cout << "List of avaliable procedures:" << endl;
	for (int i = 0; i < proc.size(); i++) {
		cout << i + 1 <<") " << proc[i]->getName() << " - " << proc[i]->getPrice() << endl;
	}
	cout << "Enter number of procedures to add, or (0) to continue" << endl;
	cin >> choice;
	while (choice != 0) {
		cust->addProc(proc[choice - 1]);
		cin >> choice;
	}

	accs.push_back(*cust);
}

void careMenu(vector<CustomerAccount>& accs, vector<Procedure*>& proc)
{
	char ch;
	string word;
	cout << "Do you want to add new procedure. (y) or (n)" << endl;
	cin >> ch;
	cin.get();

	if (ch == 'y') {
		cout << "Enter name of procedure: ";
		getline(cin, word);
		double price;
		cout << "Enter price: ";
		cin >> price;
		Procedure* newproc = new Procedure(word, price);
		proc.push_back(newproc);
	}

	double price;
	int choice;

	cout << "List of avaliable procedures:" << endl;
	for (int i = 0; i < proc.size(); i++) {
		cout << i + 1 <<") " << proc[i]->getName() << " - " << proc[i]->getPrice() << endl;
	}
	cout << "Enter number of procedures to change, or (0) to continue" << endl;
	
	cin >> choice;
	cin.get();
	while (choice != 0) {
		cout << "Enter new price" << endl;
		cin >> price;
		proc[choice - 1]->setPrice(price);
		cout << "Enter number of procedures to change, or (0) to continue" << endl;
		cin >> choice;
	}

}

void medMenu(vector<CustomerAccount>& accs, vector<Pharmacy*>& med)
{
	char ch;
	string word;
	cout << "Do you want to add new mediacation. (y) or (n)" << endl;
	cin >> ch;
	cin.get();

	if (ch == 'y') {
		cout << "Enter name of mediacation: ";
		getline(cin, word);
		double price;
		cout << "Enter price: ";
		cin >> price;
		Pharmacy* newphar = new Pharmacy(word, price);
		med.push_back(newphar);
	}

	double price;
	int choice;

	cout << "List of avaliable procedures:" << endl;
	for (int i = 0; i < med.size(); i++) {
		cout << i + 1 <<") "<< med[i]->getName() << " - " << med[i]->getPrice() << endl;
	}
	cout << "Enter number of mediacations to change, or (0) to continue" << endl;

	cin >> choice;
	cin.get();
	while (choice != 0) {
		cout << "Enter new price" << endl;
		cin >> price;
		med[choice - 1]->setPrice(price);
		cout << "Enter number of mediacations to change, or (0) to continue" << endl;
		cin >> choice;
	}

}

CustomerAccount* searchMenu(vector<CustomerAccount> & accs, CustomerAccount * selected) {
	
	int val;
	string word;
	
	cout << "Search by \n (1) name" << endl;
	cout << " (2) ID number" << endl;
	cin >> val;
	cin.get();
	getline(cin, word);
	if (val == 1) {
		selected = searchAcc(accs, word);
	}
	else if (val == 2 && stoi(word)) {
		selected = searchAcc(accs, stoi(word));
	}
	else {
		cout << "Wrong choice";
	}

	return selected;
}
CustomerAccount * searchAcc(vector<CustomerAccount>& acc, string fullname)
{
	for (unsigned int i = 0; i < acc.size(); i++) {
		if (acc[i].getName() == fullname) {
			return &acc[i];
		}
	}
	return nullptr;
}
CustomerAccount * searchAcc(vector<CustomerAccount>& acc, int number)
{
	for (unsigned int i = 0; i < acc.size(); i++) {
		if (acc[i].getNumber() == number) {
			return &acc[i];
		}
	}
	return nullptr;
}

void sortAcc(vector<CustomerAccount>& acc)
{
	int val;
	string word;

	cout << "Sort by \n (1) name" << endl;
	cout << " (2) ID number" << endl;
	cin >> val;
	cin.get();

	if (val == 1) {
		sort(acc.begin(), acc.end(), NameComp);
	}
	else if (val == 2) {
		sort(acc.begin(), acc.end(), NameComp);
	}
	else {
		cout << "Wrong choice" << endl;
	}
}
bool NameComp(CustomerAccount& first, CustomerAccount& second) {
	return first.getName() < second.getName();
}
bool NumComp(CustomerAccount& first, CustomerAccount& second) {
	return first.getNumber() < second.getNumber();
}


void outData(vector<CustomerAccount>& accs, ostream& os)
{
	os << endl << "--Customers data--" << endl << endl;
	for (int i = 0; i < accs.size(); i++) {
		os << i + 1 << ") ----------------------------" << endl;
		accs[i].PrintData(os);
	}
}


