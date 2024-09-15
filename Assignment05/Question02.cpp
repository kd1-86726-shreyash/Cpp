#include <iostream>
using namespace std;

class Student
{
    const int rollno;
    string name;
    string gender;
    static int generate_rollno;
    int marks[3];

public:
    Student() : rollno(++generate_rollno)
    {
        name = "";
        gender = "";
    }

    Student(string name, string gender) : rollno(++generate_rollno)
    {
        this->name = name;
        this->gender = gender;
    }

    int getRollno()
    {
        return this->rollno;
    }

    void acceptStudent()
    {
        cout << "\n Enter Name of Student - ";

        cin >> name;
        cout << "\n Enter Gender of Student - ";

        cin >> gender;
        cout << "\nEnter Marks Of 3 Students - ";
        for (int i = 0; i < 3; i++)
        {
            cout << "\nEnter Marks of Subject " << i + 1 << " - ";
            cin >> marks[i];
        }
    }

    void percentage()
    {
        float totalMarks = 0;
        double per;

        for (int i = 0; i < 3; i++)
        {
            totalMarks += marks[i];
        }
        per = (totalMarks * 100) / 300;
        cout << per << endl;
    }

    void displayStudents()
    {
        cout << "\n\n" << rollno << "\t\t" << name << "\t\t" << gender << "\t\t";
    }
};

int search(Student **s)
{
    int rollNumber;
    cout << "\nEnter The Roll Number You Want To Search - ";
    cin >> rollNumber;

    for (int i = 0; i < 5; i++)
    {
        if (rollNumber == s[i]->getRollno())
        {
            return i;
        }
    }
    return -1;
}

int Student::generate_rollno = 100;

int menu()
{
    int ch;

    cout << "\n----Menu----" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Accept Student Data " << endl;
    cout << "2. Display Student Data " << endl;
    cout << "3. Search Student Roll no " << endl;

    cout << "\nEnter Your Choice - ";
    cin >> ch;
    return ch;
}

int main()
{
    Student *s1[5];
    int choice;

    for (int i = 0; i < 5; i++)
    {
        s1[i] = new Student();
    }

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            for (int i = 0; i < 5; i++)
            {
                s1[i]->acceptStudent();
            }
        }
        break;
        case 2:
        {
            cout << "\nRollNo\t\tName\t\tGender\t\tPercentage";
            for (int i = 0; i < 5; i++)
            {
                s1[i]->displayStudents();
                s1[i]->percentage();
            }
        }
        break;

        case 3:
        {
            int index;
            index = search(s1);
            if (index != -1)
            {
                cout <<"Roll Number "<< s1[index]->getRollno() << " Found at " << index << " Index " << endl;
            }
            else
            {
                cout << "Roll Number Not Found!" << endl;
            }
        }
        break;

        default:
            break;
        }
    }

    return 0;
}

int main1()
{
    Student *s1[5];

    for (int i = 0; i < 3; i++)
    {
        s1[i]->acceptStudent();
    }
    for (int i = 0; i < 3; i++)
    {
        s1[i]->displayStudents();
        s1[i]->percentage();
    }

    int index;
    index = search(s1);
    cout << index << endl;

    // s1.acceptStudent();
    // s1.displayStudents();
}