//main.cpp
#include <iostream>
#include <iomanip>
#include <algorithm> // for func min(a, b)
#include <fstream>

using namespace std;

#define MAXSTUDENTS 1024

int fibonacciSearch(int* students, int element, int num_students);
int addStudent(int* students, int student, int & num_students, int startPos = 0);
void addSortedStudents(int* students, int* newstudents, int& num_students, int num_newstudents);

// void addStudents(int* student, int* students); // Uncomment to implement bonus

/******************************************************
 * last2f_under returns the last two fibonacci numbers
 * less than or equal to num
 * E.g., if num = 25, f2 = 21 and f1 = 13
 * *****************************************************/

void last2f_under(int& f1, int& f2, const int num) {
	f1 = 0; f2 = 1;
	while (f2 <= num)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;
	}
}

int read_n_count(string filename, int* students) {
	ifstream fin(filename);
	int index = 0;
	while (!fin.eof() && index < MAXSTUDENTS)
	{
		fin >> students[index];
		index++;
	}
	return index;
}

int main() {
	int* students = new int[MAXSTUDENTS];
	int num_students = read_n_count("students.txt", students);
	
	/******************************************************* *
	* TODO: Implement your code here:
	* 1. Take user input - student ID
	* 2. Search for the student using fibonacciSearch
	* 3. Take user input to add student to the list
	* 4. Add the student using addStudent
	******************************************************/
	
	// Searching

	int id;
	cout << "Search. Enter ID student: ";
	cin >> id;
	int pos = fibonacciSearch(students, id, num_students);
	if (pos != -1) {
		cout << "Student was found" << endl;
		cout << "Pos = "<< pos << endl;
	}
	else {
		cout << "Student was not found" << endl;
	}
	cout << endl;
	
	//

	// Adding one student

	int student;
	cout << "Enter ID student to add: ";
	cin >> student;
	addStudent(students, student, num_students);

	cout << "------New Student Array------" << endl;
	for (int i = 0; i < num_students; i++) {
		cout << setw(3) << i + 1 << ") " << students[i] << endl;
	}
	cout << endl;
	
	//

	// Adding sorted array of student;

	int* newstudents = new int[MAXSTUDENTS];
	int num_newstudents = read_n_count("newstudents.txt", newstudents);
	cout << "Adding students from newstudents.txt" << endl;
	addSortedStudents(students, newstudents, num_students, num_newstudents);

	cout << "------New Student Array------" << endl;
	for (int i = 0; i < num_students; i++) {
		cout << setw(3) << i + 1 << ") " << students[i] << endl;
	}
	cout << endl;
	
	//

	delete [] students;
	delete [] newstudents;
	return 0;
} 

int fibonacciSearch(int* students, int element, int num_students) {
		int fib1, fib2;

		last2f_under(fib1, fib2, num_students);
		int fib = fib1 + fib2;

		int offset = -1;

		while (fib > 1)
		{
			int i = min(offset + fib1, num_students - 1);

			if (students[i] < element)
			{
				fib = fib2;
				fib2 = fib1;
				fib1 = fib - fib2;
				offset = i;
			}
			else if (students[i] > element)
			{
				fib = fib1;
				fib2 = fib2 - fib1;
				fib1 = fib - fib2;
			}
			else return i;
		}

		// comparing the last element with element 
		if (fib2 && students[offset + 1] == element)
			return offset + 1;

		//element not found. return -1
		return -1;
	}
int addStudent( int* students, int student, int & num_students, int startPos) {
	students += startPos;

	int fib1, fib2;

	last2f_under(fib1, fib2, num_students - startPos);
	int fib = fib1 + fib2;

	int offset = -1;

	while (fib > 1)
	{
		int i = min(offset + fib1, num_students - startPos - 1);

		if (students[i] < student)
		{
			fib = fib2;
			fib2 = fib1;
			fib1 = fib - fib2;
			offset = i;
		}
		else if (students[i] > student)
		{
			fib = fib1;
			fib2 = fib2 - fib1;
			fib1 = fib - fib2;
		}
		else {
			cout << "Student " << student << " is already in array" << endl;
			return i;
		}
	}

	int insertPos = offset + 1;
	int temp = students[insertPos];
	num_students++;

	// shift array from insertPos to the right
	for (int i = num_students - startPos - 1; i > insertPos; i--) {
		students[i] = students[i - 1];
	}

	students[insertPos] = student;
	return insertPos;
}
void addSortedStudents(int* students, int* newstudents, int& num_students, int num_newstudents) {
	int startPos = 0;
	for (int i = 0; i < num_newstudents; i++) {
		startPos = addStudent(students, newstudents[i], num_students, startPos);
	}
}