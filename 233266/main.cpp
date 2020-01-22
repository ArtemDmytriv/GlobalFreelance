//main.cpp
#include <iostream>
#include <fstream>
using namespace std;
#define MAXSTUDENTS 1024
int fibonacciSearch(int* students, int element, int num_students);
void addStudent(int student, int* students);
// void addStudents(int* student, int* students); // Uncomment to implement bonus

/******************************************************
 * last2f_under returns the last two fibonacci numbers
 * less than or equal to num
 * E.g., if num = 25, f2 = 21 and f1 = 13
 * *****************************************************/
void last2f_under(int &f1, int &f2, const int num)
{
	f1 = 0; f2 = 1;
	while(f2 <= num)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;
	}
}
int read_n_count(string filename, int* students)
{
	ifstream fin(filename);
	int index = 0;
	while(!fin.eof() && index < MAXSTUDENTS)
	{
		fin >> students[index];
		index++;
	}
	return index;
}
int main()
{
	int* students = new int[MAXSTUDENTS];
	int num_students = read_n_count("students.txt", students);
	gen_random();
	/******************************************************* *
	 * TODO: Implement your code here:
	 * 1. Take user input - student ID
	 * 2. Search for the student using fibonacciSearch
	 * 3. Take user input to add student to the list
	 * 4. Add the student using addStudent
	 ******************************************************/
	delete [] students;
	return 0;
}
