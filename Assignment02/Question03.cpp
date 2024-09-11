#include <iostream>
using namespace std;

namespace Stud
{
    class Student
{
    int rollno;
    string name;
    double marks;

public:
    void initStudent()
    {
        rollno = 0;
        name = " ";
        marks = 0.0;
        cout << "---Inital--- \nRollNO - " << rollno << "\nName - " << name << "\nMarks - " << marks << endl;
    }

    void acceptStudentFromConsole()
    {
        cout << "\nEnter Roll_No of Student - ";
        cin >> rollno;
        cout << "Enter Name of Student - ";
        cin >> name;
        cout << "Enter Marks Of Student - ";
        cin >> marks;
    }

    void printStudentOnConsole()
    {
        cout << "Roll_No = " << rollno << endl;
        cout << "Name = " << name << endl;
        cout << "Marks = " << marks << endl;
    }
};
} 

int menu()
{
    int ch;
    cout << "\n\n----- MENU -----";
    cout << "\n\n0. EXIT" << endl;
    cout << "1. Initial Student" << endl;
    cout << "2. Accept Student" << endl;
    cout << "3. Print Student" << endl;

    cout << "\nEnter Choice - ";
    cin >> ch;
    return ch;
}

using namespace Stud;
int main()
{
    int choice;
    Student s1;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            s1.initStudent();
        }
        break;

        case 2:
        {
            s1.acceptStudentFromConsole();
        }
        break;

        case 3:
        {
            s1.printStudentOnConsole();
        }
        break;

        default:
        {
            cout << "Invalid Input !";
        }
        break;
        }
    }
}
