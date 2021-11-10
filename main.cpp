#include <iostream>
using namespace System;

namespace Lab5Lecture10Inheritance
{
    class Person
    {
    public:
        string name;

    public:
        School school;

    public:
        void Sleep()
        {
            Console.WriteLine("This person sleeps. ");
        }
    };
    class School
    {
    };
    class Student : Person
    {

    public:
        Student(string n, School s)
        {
            name = n;
            school = s;
        }

    public:
        void Study()
        {
            Console.WriteLine("The student is studying");
        }
    };
    class Employee : Person
    {
    };
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            Student studentA = new Student();
            studentA.Sleep();
            studentA.Study();

            Employee employeeA = new Employee();
            employeeA.Sleep();
        }
    };
}