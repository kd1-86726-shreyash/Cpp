#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1900;
        cout << "Initial Date = " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter Day - ";
        cin >> day;
        cout << "Enter Month - ";
        cin >> month;
        cout << "Enter Year - ";
        cin >> year;
    }

    void printDateOnConsole()
    {
        cout << "\nDate = " << day << " / " << month << " / " << year << endl;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        else
            return false;
    }
};

int menu()
{
    int ch;
    cout << "\n\n0. EXIT" << endl;
    cout << "1. Intial Date" << endl;
    cout << "2. Accept Date" << endl;
    cout << "3. Print Date" << endl;
    cout << "4. Check Leap Year" << endl;

    cout << "\nEnter Your choice - ";
    cin >> ch;
    return ch;
}

int main()
{
    int choice;
    bool b;
    Date dt1;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            dt1.initDate();
        }
        break;

        case 2:
        {
            dt1.acceptDateFromConsole();
        }
        break;

        case 3:
        {
            dt1.printDateOnConsole();
        }
        break;

        case 4:
        {
            b = dt1.isLeapYear();
            if (b)
            {
                cout << "\nIs a Leap Year!";
            }
            else
            {
                cout << "\nIs not a Leap year";
            }
        }
        break;

        default:
        {
            cout << "Invalid Input!";
        }
        break;
        }
    }

    return 0;
}
