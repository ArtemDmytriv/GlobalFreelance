//Jake Ljubic
//0692552
//Final Project #1
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentList
{
    class Program
    {
        static string[] listOfName = null;
        static string[] listOfLastName = null;
        static int[] listOfId = null;
        static int[] listOfGrade = null;
        static int num = 0;
        public static void StartMenu()
        {
            Console.WriteLine("Choose an option between 1 and 5.");
            Console.WriteLine("1 - Enter New Information.");
            Console.WriteLine("2 - Search For A Student.");
            Console.WriteLine("3 - List of Students.");
            Console.WriteLine("4 - List of Students, who failed the exam.");
            Console.WriteLine("5 - List of Students, who passed the exam.");
            Console.WriteLine("6 - Compute Min, Max, Average grade.");
        }
        public static bool Check()
        {
            while (true)
            {
                string response = Console.ReadLine();
                if (response == "Yes")
                {
                    return true;
                }
                else if (response == "No")
                {
                    return false;
                }
                else
                {
                    Console.WriteLine("Choose Only 'Yes' OR 'No'");
                }
            }
        }
        public static int ConvertToIntSafe()
        {
            try
            {
                int number = Convert.ToInt32(Console.ReadLine());
                return number;
            }
            catch (Exception)
            {
                return 0;
            }
        }
        public static string ConvertToStringSafe()
        {
            while (true)
            {
                string name = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(name))
                {
                    Console.WriteLine("Please Enter A Non Empty String.");
                }
                else
                {
                    return name;
                }
            }
        }
        public static int ConvertToGradeSafe()
        {
            try
            {
                int grade = ConvertToIntSafe();
                if (grade >= 0 && grade <= 100)
                {
                    return grade;
                }
                else
                {
                    return 0;
                }
            }
            catch (Exception)
            {
                return 0;
            }
        }
        public static void EnterStudents(int Num)
        {
            num = Num; 
            listOfName = new string[num];
            listOfLastName = new string[num];
            listOfId = new int[num];
            listOfGrade = new int[num];

            for (int i = 0; i < num; i++)
            {
                Console.WriteLine("Enter Student Name.");
                string name = ConvertToStringSafe();
                listOfName[i] = name;

                Console.WriteLine("Enter Student Last Name.");
                string lastName = ConvertToStringSafe();
                listOfLastName[i] = lastName;

                Console.WriteLine("Enter Student ID.");
                int id = ConvertToIntSafe();
                listOfId[i] = id;

                Console.WriteLine("Enter Student Grade.");
                int grade = ConvertToGradeSafe();
                listOfGrade[i] = grade;
                Console.WriteLine("------------------------------------------");
            }
        }
        public static void FindStudent(int sd)
        {
            if (listOfName == null || listOfLastName == null || listOfId == null)
            {
                return;
            }
            for (int i = 0; i < listOfId.Length; i++)
            {
                if (sd == listOfId[i])
                {
                    Console.WriteLine($"Student Name: {listOfName[i]}; Student Last Name: {listOfLastName[i]}");
                    Console.WriteLine($"ID: {listOfId[i]}");
                    Console.WriteLine($"Grade: {listOfGrade[i]}");
                    if (listOfGrade[i] > 50) {
                        Console.WriteLine("Passed");
                    }
                    else {
                        Console.WriteLine("NotPassed");
                    }
                    return;
                }
            }
            Console.WriteLine("This ID Is Not Found.");
        }
        public static int FindMaxGrade()
        {
            int max = listOfGrade[0];
            for (int i = 1; i < num; i++)
            {
                if(listOfGrade[i] > max)
                {
                    max = listOfGrade[i];
                }
            }
            return max;
        }
        public static int FindMinGrade()
        {
            int min = listOfGrade[0];
            for (int i = 1; i < num; i++)
            {
                if (listOfGrade[i] < min)
                {
                    min = listOfGrade[i];
                }
            }
            return min;
        }
        public static double FindAvgGrade()
        {
            double avg = 0;
            foreach(int grade in listOfGrade)
            {
                avg += grade;
            }
            return (double)(avg / num); 
        }
        public static double GetPercPassed()
        {
            int count = 0;
            foreach (int grade in listOfGrade)
            {
                if (grade >= 50)
                {
                    count++;
                }
            }
            return ((double)count / num) * 100;
        }
        public static double GetPercFailed()
        {
            int count = 0;
            foreach(int grade in listOfGrade)
            {
                if(grade < 50)
                {
                    count++;
                }
            }
            return ((double)count / num) * 100;
        }
        public static int SumOfGrades()
        {
            int sum = 0;
            foreach(int item in listOfGrade)
            {
                sum += item;
            }
            return sum;
        }
        public static void DisplayList()
        {
            for(int i = 0; i < num; i++)
            {
                Console.WriteLine("---------------------------------");
                Console.WriteLine($"FullName: {listOfName[i]} {listOfLastName[i]}");
                Console.WriteLine($"ID: {listOfId[i]}");
                Console.WriteLine($"Grade: {listOfGrade[i]}");
            }
            Console.WriteLine("---------------------------------");
        }
        public static void DisplayPassed()
        {
            Console.WriteLine("Students, who passed the exam\n");
            for (int i = 0; i < num; i++)
            {
                if(listOfGrade[i] >= 50)
                {
                    Console.WriteLine("---------------------------------");
                    Console.WriteLine($"FullName: {listOfName[i]} {listOfLastName[i]}");
                    Console.WriteLine($"ID: {listOfId[i]}");
                    Console.WriteLine($"Grade: {listOfGrade[i]}");
                }
            }
            Console.WriteLine("---------------------------------");
            string text = String.Format("{0:F3}", GetPercPassed()); // Show 3 Decimel Points
            Console.WriteLine($"Percent of passed -  {text}");
        }
        public static void DisplayFailed()
        {
            Console.WriteLine("Students, who failed the exam\n");
            for (int i = 0; i < num; i++)
            {
                if (listOfGrade[i] < 50)
                {
                    Console.WriteLine("---------------------------------");
                    Console.WriteLine($"FullName: {listOfName[i]} {listOfLastName[i]}");
                    Console.WriteLine($"ID: {listOfId[i]}");
                    Console.WriteLine($"Grade: {listOfGrade[i]}");
                }
            }
            Console.WriteLine("---------------------------------");
            string text = String.Format("{0:F3}", GetPercFailed()); // Show 3 Decimel Points
            Console.WriteLine($"Percent of passed -  {text}"); 
        }

        static void Main(string[] args)
        {
            int num = 0;
            int sd = 0;

            while (true)
            {
                StartMenu();

                int number = ConvertToIntSafe();

                if (number == 1)
                {
                    Console.WriteLine("How Many Students Do You Have?");

                    num = ConvertToIntSafe();
                    if (num > 0)
                    {
                        EnterStudents(num);
                    }
                    else
                    {
                        Console.WriteLine("Enter A Number Greater Than ZERO.");
                        continue;
                    }
                }
                else if (number == 2)
                {
                    Console.WriteLine("Type The Student ID Of Your Choice.");

                    sd = ConvertToIntSafe();

                    FindStudent(sd);
                }
                else if (number == 3)
                {
                    DisplayList();
                    Console.WriteLine($"Sum of grades - {SumOfGrades()}");
                }
                else if (number == 4)
                {
                    DisplayPassed();
                }
                else if (number == 5)
                {
                    DisplayFailed();
                }
                else if (number == 6)
                {
                    Console.WriteLine($"Max grade - {FindMaxGrade()}");
                    Console.WriteLine($"Min grade - {FindMinGrade()}");
                    Console.WriteLine($"Avg grade - {FindAvgGrade()}");
                }
                else
                {
                    Console.WriteLine("Invalid Response.");
                    continue;
                }
                Console.WriteLine("Would You Like To Choose Another Option?");

                if (Check())
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            Console.Clear();
            Console.WriteLine("Thank You And Have A Good Day! :)");
            Console.ReadKey();
        }
    }
}