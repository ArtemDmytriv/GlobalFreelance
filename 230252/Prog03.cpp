#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

class Heap {
private:
	list<double> List;
public:
	Heap();
	void Insert(double num);
	void Delete(double num);
	void Change(double num, double to);
	void Print(ostream& os);
};

Heap::Heap() {

}

void Heap::Insert(double num) {
	List.push_back(num);
}

void Heap::Delete(double num) {
	List.remove(num);
}

void Heap::Change(double num, double to) {
	for (double& item : List) {
		if (item == num) {
			item = to;
		}
	}
}

void Heap::Print(ostream& os) {
	list<double>::iterator ptr = List.begin();
	for (int i = 0; i < List.size(); i++) {
		if (i != List.size() - 1) {
			os << *ptr << ", ";
		}
		else {
			os << *ptr;
		}
		ptr++;
	}
	os << endl;
}


int main() {

	Heap* ptr = new Heap;
	Heap& list1 = *ptr;

	ifstream in("input.txt", ios::in);
	ofstream out("output.txt", ios::out);
	char ch;
	double num1;
	double num2;

	while (in >> ch) {
		switch (ch) {
		case 'I': in >> num1;
			list1.Insert(num1);
			break;
		case 'D': in >> num1;
			list1.Delete(num1);
			break;
		case 'C': in >> num1 >> num2;
			list1.Change(num1, num2);
			break;
		case 'P': list1.Print(out);
			break;
		default: break;
		}
	}

	delete ptr;
	return 0;
}
