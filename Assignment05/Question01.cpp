#include <iostream>
using namespace std;

enum MENU
{
    ACCEPT = 1,
    DISPLAY
};

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

    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    void acceptDate()
    {
        cout << "\nEnter Day -";
        cin >> day;
        cout << "Enter Month - ";
        cin >> month;
        cout << "Enter Year - ";
        cin >> year;
    }
    void displayDate()
    {
        cout << " " << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    string name;
    string address;
    Date birthdate;

public:
    Person()
    {
        name = "";
        address = "";
    }

    Person(string name, string address, int day, int month, int year)
    {
        this->name = name;
        this->address = address;
        this->birthdate.setDay(day);
        this->birthdate.setMonth(month);
        this->birthdate.setYear(year);
    }

    void acceptPerson()
    {
        getchar();
        cout << "\n\nEnter Name of Person - ";
        getline(cin, name);
        cout << "Enter Address of Person - ";
        getline(cin, address);
        cout << "Enter BirthDate of Person - " << endl;
        birthdate.acceptDate();
    }

    void displayPerson()
    {
        cout << "\n\nName = " << name << endl;
        cout << "Address = " << address << endl;
        cout << "BirthDate = ";
        birthdate.displayDate();
    }
};

int main()
{
    Person p1;

    int choice;
    do
    {
        cout << "\n\n---MENU---" << endl;
        cout << "1 . ACCEPT" << endl;
        cout << "2. DISPLAY " << endl;

        cout << "\nENTER YOUR CHOICE - ";
        cin >> choice;

        switch (choice)
        {
        case ACCEPT:
        {
            p1.acceptPerson();
        }
        break;
        case DISPLAY:
        {
            p1.displayPerson();
        }
        break;

        default:
        {
            cout << "Invalid Input !";
        }
        break;
        }
    } while (choice!=0);
}
