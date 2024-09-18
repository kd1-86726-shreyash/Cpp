#include <iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
    }

    Employee(int id, double salary)
    {
        this->id = id;  
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter Employee ID - ";
        cin >> id;
        cout << "Enter Employee Salary - ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "\nEmployee ID = " << id << endl;
        cout << "Employee Salary = " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter Bonus - ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus = " << bonus << endl;
    }

public:
    Manager()
    {
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission = " << commission << endl;
    }

public:
    Salesman()
    {
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        this->setBonus(bonus);
        this->setCommission(commission);
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};

int addEmployee()
{
    int ch;

    cout << "\n\n---Menu---" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Accept Manager - " << endl;
    cout << "2. Accept Salesman - " << endl;
    cout << "3. Accept Salesmanager - " << endl;

    cout << "\nEnter Your Choice - ";
    cin >> ch;

    return ch;
}

int menu()
{
    int ch;

    cout << "\n\n---Menu---" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Accept Employee - " << endl;
    cout << "2. Count of Employee with Respect to Designation " << endl;
    cout << "3. Display Managers - " << endl;
    cout << "4. Display Salesman - " << endl;
    cout << "5. Display SalesManager - " << endl;

    cout << "\n\nEnter Your Choice - ";
    cin >> ch;

    return ch;
}

void countEmployees(Employee **arr, int index)
{
    int mcount = 0, scount = 0, smcount = 0;

    for (int i = 0; i < index; i++)
    {
        if (typeid(*arr[i]) == (typeid(Manager)))
        {
            mcount++;
        }
        else if (typeid(*arr[i]) == (typeid(Salesman)))
        {
            scount++;
        }
        else
        {
            smcount++;
        }
    }

    cout << "\n\nManager as a Employee - " << mcount << endl;
    cout << "Salesman as a Employee - " << scount << endl;
    cout << "SalesManager as a Employee - " << smcount << endl;
}

int main()
{
    Employee *arr[5];
    int index = 0;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int ch;
            while ((ch = addEmployee()) != 0)
            {
                switch (ch)
                {
                case 1:
                {
                    if (index < 5)
                    {
                        arr[index] = new Manager;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full , Cant Add More Employees !" << endl;
                    }
                }
                break;
                case 2:
                {
                    if (index < 5)
                    {
                        arr[index] = new Salesman;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full , Cant Add More Employees !" << endl;
                    }
                }
                break;
                case 3:
                {
                    if (index < 5)
                    {
                        arr[index] = new SalesManager;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full , Cant Add More Employees !" << endl;
                    }
                }
                break;

                default:
                {
                    cout << "Invalid Input !" << endl;
                }
                break;
                }
            }
        }
        break;

        case 2:
        {
            countEmployees(arr, index);
        }
        break;

        case 3:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
        }
        break;

        case 4:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                }
            }
        }
        break;

        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                }
            }
        }
        break;

        default:
        {
            cout << "Invalid Input!" << endl;
        }
        break;
        }
    }
}
