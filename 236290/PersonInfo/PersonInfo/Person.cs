using System;
using System.Collections.Generic;
using System.Text;

namespace PersonInfo
{
    class Person
    {
        // all fields have automatic properties 
        public string FirstName { get; set; }
        public string LastName { get; set; }
        private int age;
        public int Age {
            get { return age; }
            set { age = value > 0 ? value : 0; }
        }
        public string Gender { get; set; }
        public double Salary { get; set; }
        public bool Havekids { get; set; }
        public Person (string nm, string lm, string age, string gender, string salary, string havekids) // constructor
        {
            // setting all fields
            FirstName = nm;
            LastName = lm;
            Age = Convert.ToInt32(age);
            Gender = gender;
            Salary = Convert.ToDouble(salary);
            if (havekids[0] == '0' || havekids[0] == 'f' || havekids[0] == 'F')
            {
                Havekids = false;
            }
            else
            {
                Havekids = true;
            }
        }

        // method to print formatted data about Person
        public void  Print()
        {
            System.Console.WriteLine("{0, -8} {1, -10}| age {2, -5}| gen ({3, -5})| Salary {4, -8}| HaveKids {5, -5}"
                , FirstName, LastName, Age, Gender, Salary, Havekids);
        }
    }
}
