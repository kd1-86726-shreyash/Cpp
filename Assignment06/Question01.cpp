#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "\nEnter Day - ";
        cin >> day;
        cout << "Enter Month - ";
        cin >> month;
        cout << "Enter Year - ";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        name = "";
        address = "";
    }

    Person(string name, string addresss, int day, int month, int year) : dob(day, month, year)
    {
        this->name = name;
        this->address = address;
    }

    void acceptperson()
    {
        cout << "Enter Name Of Person - ";
        cin >> name;
        cout << "Enter Address of Person - ";
        cin >> address;
        cout << "Enter Birthdate - ";
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout << "\nName =\t\t\t" << name << endl;
        cout << "Address =\t\t " << address << endl;
        cout << "Birthdate =\t\t ";
        dob.displayDate();
    }
};

class Employee : public Person
{
    int id;
    double salary;
    string dept;
    Date doj;

public:
    Employee()
    {
        id = 0;
        salary = 0;
        dept = "";
    }

    Employee(int id, double salary, string dept, int day, int month, int year) : doj(day, month, year)
    {
        this->id = id;
        this->salary = salary;
        this->dept = dept;
    }

    void acceptEmployee()
    {
        acceptperson();
        cout << "Enter Employee Id - ";
        cin >> id;
        cout << "Enter Employee Salary - ";
        cin >> salary;
        cout << "Enter Employee Department - ";
        cin >> dept;
        cout << "Enter Joining Date - ";
        doj.acceptDate();
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "ID =\t\t\t " << id << endl;
        cout << "Salary =\t\t " << salary << endl;
        cout << "Department =\t\t " << dept << endl;
        cout << "Date of Joining =\t\t ";
        doj.displayDate();
    }
};

int menu()
{
    int ch;

    cout << "\n----Menu----" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Accept Employee " << endl;
    cout << "2. Display Person " << endl;

    cout << "\nEnter Your Choice - ";
    cin >> ch;
    return ch;
}

int main()
{

    Employee e;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            e.acceptEmployee();
        }
        break;
        case 2:
        {
            cout << "\n\n--- Employee Details ---" << endl;
            e.displayEmployee();
        }
        break;

        default:
            break;
        }
    }

    return 0;
}