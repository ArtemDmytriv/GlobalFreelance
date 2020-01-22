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

        public static void StartMenu()
        {
            Console.WriteLine("Choose an option between 1 and 2.");
            Console.WriteLine("1 - Enter New Information.");
            Console.WriteLine("2 - Search For A Student.");
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

        public static void EnterStudents(int num)
        {
            listOfName = new string[num];
            listOfLastName = new string[num];
            listOfId = new int[num];

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
                    Console.WriteLine($"Student Name: {listOfName[i]}; Student Last Name: {listOfLastName[i]}; Student ID: {listOfId[i]};");
                    return;
                }
            }
            Console.WriteLine("This ID Is Not Found.");
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