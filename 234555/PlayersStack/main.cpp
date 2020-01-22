#include <iostream>
#include <fstream>

#include "Players.h"



//void writeNumbers(vector < Integer* > &iNumbers);
//void writeNumbers(vector < Double* > &dNumbers);

int main(){
	Players players;
	ifstream infile("avgs.txt");

// Check whether file exists and you are able to open it. If not return from the program by printing proper message

	if(infile.is_open()){
			string name;
			float avg;

	while(infile >> name >> avg){
		players.addPlayer(name, avg);
	}

	players.printLowest();
	players.printHighest();

	}
	else{
		cout<<"unable to open the file: "<<endl;
	}

}






//	cout << "1) Add Integers" << endl;
//	cout << "2) Subtract Integers" << endl;
//	cout << "3) Multiply Integers" << endl;
//	cout << "4) Divide Integers" << endl;
//	cout << "5) Add Doubles" << endl;
//	cout << "6) Subtract Doubles" << endl;
//	cout << "7) Multiply Doubles" << endl;
//	cout << "8) Divide Doubles" << endl;
//	cout << "9) Quit \n" << endl;
//
//	while (true)
//	{
//		char command;
//		cin >> command;
//
//		switch (command)
//		{
//		case '1':
//		{
//			cout << "Input two integers: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Integer i1(a);
//				Integer i2(b);
//
//				cout << "The sum is: " << (i1 + i2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '2':
//		{
//			cout << "Input two integers: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Integer i1(a);
//				Integer i2(b);
//
//				cout << "The difference is: " << (i1 - i2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '3':
//		{
//			cout << "Input two integers: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Integer i1(a);
//				Integer i2(b);
//
//				cout << "The product is: " << (i1 * i2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '4':
//		{
//			cout << "Input two integers: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Integer i1(a);
//				Integer i2(b);
//
//				cout << "The quotient is: " << (i1 / i2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '5':
//		{
//			cout << "Input two doubles: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Double d1(a);
//				Double d2(b);
//
//				cout << "The summation is: " << (d1 + d2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '6':
//		{
//			cout << "Input two doubles: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Double d1(a);
//				Double d2(b);
//
//				cout << "The difference is: " << (d1 - d2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '7':
//		{
//			cout << "Input two doubles: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Double d1(a);
//				Double d2(b);
//
//				cout << "The product is: " << (d1 * d2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '8':
//		{
//			cout << "Input two doubles: \n";
//			string a, b;
//			cin >> a >> b;
//
//			try
//			{
//				Double d1(a);
//				Double d2(b);
//
//				cout << "The quotient is: " << (d1 / d2).toString() << endl;
//			}
//			catch (Number::NumberException& ex)
//			{
//				cout << ex.getMessage() << endl;
//			}
//			break;
//		}
//
//		case '9':
//		{
//			cout << "Goodbye!";
//			return 0;
//		}
//
//		default:
//		{
//			cout << "\nUnknown error!\n";
//			break;
//		}
//		}
//	}
//
//	//-----------------------------------------------------------------------------------------------------------------------------//
//
//    string file = "Numbers.txt";
//    ifstream filein(file.c_str());
//
//    if (!filein.is_open())
//    {
//        cout << "Error finding the file, please make sure it is saved inside the project folder.\n";
//        return 0;
//    }
//    else
//    {
//        cout << "Reading the " << file << " file" <<endl;
//    }
//
//    string number;
//    vector < Integer* > iNumbers;
//    vector < Double* > dNumbers;
//
//    while (filein >> number)
//    {
//        Double* testDouble = new Double(number);
//        Integer* testInteger = new Integer(number);
//
//		if (!dynamic_cast <Number*> (testInteger)->isNaN())
//		{
//			delete testDouble;
//			iNumbers.push_back(testInteger);
//		}
//		else if (!dynamic_cast <Number*> (testDouble)->isNaN())
//		{
//			delete testInteger;
//			dNumbers.push_back(testDouble);
//		}
//		else
//		{
//			delete testDouble;
//			delete testInteger;
//		}
//	}
//
//    filein.close();
//
//    writeNumbers(iNumbers);
//    writeNumbers(dNumbers);
//
//    for (size_t i = 0; i < iNumbers.size(); i++)
//    {
//        delete iNumbers[i];
//    }
//    for (size_t i = 0; i < dNumbers.size(); i++)
//    {
//        delete dNumbers[i];
//    }
//    return 0;
//}
//
//
//
//
//
//
//void writeNumbers(vector < Integer* > &iNumbers)
//{
//	string file = "Integers.txt";
//	ofstream fileout(file.c_str());
//
//	cout << "Printing Integers to the " << file << " file" << endl;
//
//	for (size_t i = 0; i < iNumbers.size(); i++)
//	{
//		fileout << iNumbers[i]->toString() << endl;
//	}
//
//	fileout.close();
//}
//
//void writeNumbers(vector < Double* > &dNumbers)
//{
//	string file = "Doubles.txt";
//	ofstream fileout(file.c_str());
//
//	cout << "Printing Doubles to the " << file << " file" << endl;
//
//	for (size_t i = 0; i < dNumbers.size(); i++)
//	{
//		fileout << dNumbers[i]->toString() << endl;
//	}
//
//	fileout.close();
