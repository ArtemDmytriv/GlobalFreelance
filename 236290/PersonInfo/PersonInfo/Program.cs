using System;
using System.IO;
// access to class Person
using PersonInfo;

namespace PersonInfo
{
    class Program
    {
        static void PrintMenu() // func to print main menu
        {
            System.Console.WriteLine("1) PrintAllPerson");
            System.Console.WriteLine("2) Filter(Search)");
            System.Console.WriteLine("3) Quit");
        }
        static internal void Sort(Person [] list, int num) // func that sorting list by first name and last name (bubble sort)
        {
            Person temp; // needed to swap

            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num - 1; j++)
                {
                    int compRes = string.Compare(list[j].FirstName, list[j + 1].FirstName); // standard string method to compare
                    if (compRes > 0) // 
                    {
                        temp = list[j + 1];
                        list[j + 1] = list[j];
                        list[j] = temp;
                    }
                    else if (compRes == 0) // if equal names, compare last names
                    {
                        compRes = string.Compare(list[j].LastName, list[j + 1].LastName);
                        if (compRes > 0) // 
                        {
                            temp = list[j + 1];
                            list[j + 1] = list[j];
                            list[j] = temp;
                        }
                    }
                }
            }

        }
        static void Main(string[] args)
        {
            // Reading data from file PersonInfo.txt
            System.Console.WriteLine("Loading data from file... ");
            string[ ] line = File.ReadAllLines("PersonInfo.txt");
            MatchingDemo MD = new MatchingDemo(line);
            System.Console.WriteLine("Loading data successful");

            PrintMenu(); // print menu
            int ch = Convert.ToInt32(System.Console.ReadLine()); // user input number (from menu)

            while (ch != 3) // 3 means: Quit
            {
                if(ch == 1) // 1 means: Print all Persons
                {
                    MD.Print();
                }
                else if(ch == 2) // 2 means: Filter by some sign (Gander, Age, ...)
                {
                    // Menu for searching
                    System.Console.WriteLine("Filter (Search) by...");
                    System.Console.WriteLine("1) Gander");
                    System.Console.WriteLine("2) Age");
                    System.Console.WriteLine("3) Salary");
                    System.Console.WriteLine("4) HaveKids");
                    System.Console.WriteLine("5) Go Back");

                    int ch2 = Convert.ToInt32(System.Console.ReadLine()); // user enters number of sign (1 - Gander, 2 - Age, ...) 
                    System.Console.WriteLine("Enter request");
                    string request = System.Console.ReadLine(); // user enters request

                    switch (ch2) // compare types
                    {
                        case 1:                           
                            MD.SearchBy(MatchingDemo.searchTypes.GAN, request); 
                            break;
                        case 2:
                            MD.SearchBy(MatchingDemo.searchTypes.AGE, request);
                            break;
                        case 3:                            
                            MD.SearchBy(MatchingDemo.searchTypes.SALARY, request);
                            break;
                        case 4:                            
                            MD.SearchBy(MatchingDemo.searchTypes.HAVEKID, request);
                            break;
                        case 5:
                            break;
                    }
                }
                else // if user input no 1, no 2, no 3
                {
                    System.Console.WriteLine("Unknown operation");
                }

                PrintMenu(); // Print menu again
                ch = Convert.ToInt32(System.Console.ReadLine()); // and reads user command
            }

        }
    }

    class MatchingDemo // Class that contain list of Persons
    {
        public enum searchTypes { GAN, AGE, SALARY, HAVEKID}; 
        private int num; // field that 
        public int Num {
            get { return num; }
        }
        public Person [] PersonList;
        public MatchingDemo()
        {
            num = 0;
        }
        public MatchingDemo(string [] lines) // constructor
        {
            num = Convert.ToInt32(lines[0]); // first line in file must have onlu number of person
            PersonList = new Person[num]; // dynamic allocation 
            
            for (int i = 1; i < num + 1; i++)
            {
                string[] data = lines[i].Split(' '); // All Person data separated by space ' '
                Person temp = new Person(data[0], data[1], data[2], data[3], data[4], data[5]); // make new Person with all data from file
                PersonList[i - 1] = temp; // save to list
            }

            Program.Sort(PersonList, num);
        }
      
        public void Print() // method that print all persons
        {
            System.Console.WriteLine("| Full list by descending order |");
            foreach (var p in PersonList){
                p.Print();
            }
            System.Console.WriteLine("---------------------------------");
        }
        public void SearchBy(searchTypes type, string request) // method to search, take also type of search(Gander, Age, Salary ...)
        {
            bool flag = false; // for "no mathing found"
            switch (type)
            {
                case searchTypes.GAN:
                    foreach (var p in PersonList)
                    {
                        if (p.Gender == request)
                        {
                            flag = true;
                            p.Print();
                        }
                    }
                    break;
                case searchTypes.AGE:
                    foreach (var p in PersonList)
                    {
                        if (p.Age == Convert.ToInt32(request))
                        {
                            flag = true;
                            p.Print();
                        }
                    }
                    break;
                case searchTypes.SALARY:
                    foreach (var p in PersonList)
                    {
                        if (p.Salary == Convert.ToDouble(request))
                        {
                            flag = true;
                            p.Print();
                        }
                    }
                    break;
                case searchTypes.HAVEKID:
                    foreach (var p in PersonList)
                    {
                        if (p.Havekids == Convert.ToBoolean(request))
                        {
                            flag = true;
                            p.Print();
                        }
                    }
                    break;
                default:
                    break;
            }

            if (!flag) // if flag is false, that means "no matching found" 
            {
                System.Console.WriteLine("No Matching Found");
            }
        }
    }
}
