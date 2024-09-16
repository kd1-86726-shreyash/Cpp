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

int main()
{
    Employee *e = new SalesManager;
    e->accept();
    e->display();
}