#include "header.h"

int main() {

	vector<CustomerAccount> accs;
	vector<Procedure*> proc;
	vector<Pharmacy*> med;

	// hardcode some procedure and pharmacy items

	Procedure* ptr = new Procedure("Massage (back)", 20);
	proc.push_back(ptr);
	ptr = new Procedure("Cleaning", 30);
	proc.push_back(ptr);
	ptr = new Procedure("Massage (all body)", 50);
	proc.push_back(ptr);
	ptr = new Procedure("MRT", 40);
	proc.push_back(ptr);
	ptr = new Procedure("Analysis", 35);
	proc.push_back(ptr);

	Pharmacy* ptr2 = new Pharmacy("Oil (massage)", 10);
	med.push_back(ptr2);
	ptr2 = new Pharmacy("Vitamins", 10);
	med.push_back(ptr2);
	ptr2 = new Pharmacy("Antibiotics", 15);
	med.push_back(ptr2);
	ptr2 = new Pharmacy("Anesthetist", 15);
	med.push_back(ptr2);
	ptr2 = new Pharmacy("Care tools", 5);
	med.push_back(ptr2);

	int choice = 0;

	while (choice != 8) {
		
		mainMenu(accs, proc, med);
		cin >> choice;
		cin.ignore();

		while (choice < 0 || choice > 8)
		{
			cout << "Wrong choice, try again" << endl;
			mainMenu(accs, proc, med);
			cin >> choice;
		}

		int val;
		string word;
		CustomerAccount* selected = nullptr;

		switch (choice)
		{
		case 1:
			careIn(accs, proc, med);
			cin.ignore();
			break;
		case 2:
			careMenu(accs, proc);
			break;
		case 3:
			medMenu(accs, med);
			break;
		case 4: {
			selected = searchMenu(accs, selected);

			if (selected == nullptr) {
				cout << "---Customer was not found---" << endl;
			}
			else {
				cout << "---Customer was found---" << endl;
				selected->PrintData(cout);
			}
			break;
		}
		case 5:
			sortAcc(accs);
			break;
		case 6:
			outData(accs, cout);
			break;
		case 7:
			ofstream os("output.txt");
			outData(accs, os);
			os.close();
			break;
		}

	}

	return 0;
}