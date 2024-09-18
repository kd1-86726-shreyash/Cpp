#include <iostream>
using namespace std;

double amount;

class inSufficientFundsException
{
    string message;

public:
    inSufficientFundsException(string message)
    {
        this->message = message;
    }

    void display()
    {
        cout << message << endl;
    }
};

enum EaccountType
{
    Saving = 1,
    Current,
    Dmat
};

class Account
{
    int accno;
    EaccountType ea;
    double balance = 0;

public:
    Account()
    {
    }

    Account(int accno, EaccountType ea, double balance)
    {
        this->accno = accno;
        this->ea = ea;
        this->balance = balance;
    }

    void accept()
    {
        int choice;

        cout << "\n1. SAVING ACCOUNT - " << endl;
        cout << "2. CURRENT ACCOUNT - " << endl;
        cout << "3. DMAT ACCOUNT - " << endl;
        cout << "\nEnter Account Type - " << endl;
        cin >> choice;
        ea = EaccountType(choice);
        cout << "Enter Account Number - ";
        cin >> accno;
        cout << "Enter Account Balance - ";
        cin >> balance;
    }

    void display()
    {
        cout << "Account Number - " << accno << endl;
        switch ((ea))
        {
        case Saving:
        {
            cout << "\nSaving Account !" << endl;
        }
        break;
        case Current:
        {
            cout << "\nCurrent Account !" << endl;
        }
        break;
        case Dmat:
        {
            cout << "\nDMAT Account !" << endl;
        }
        break;

        default:
        {
            cout << "Invalid Choice !" << endl;
        }
        break;
        }
        cout << "Balance - " << balance << endl;
    }

    void deposit()
    {
        cout << "Enter the Amount To Deposit - ";
        cin >> amount;
        if (amount < 0)
            throw inSufficientFundsException("\nCant Depsite amount Less than or Equal to Zero !");
        else
        {
            balance += amount;
            cout << "Balance = " << balance << endl;
        }
    }
    void withdraw()
    {
        cout << "Enter the Amount To Withdraw - ";
        cin >> amount;
        if (amount > balance)
            throw inSufficientFundsException("\nInsufficient Balance cant Withdraw Money !");
        else
        {
            balance -= amount;
            cout << "Balance = " << balance << endl;
        }
    }

    void checkBalance()
    {
        cout << "Balance = " << balance << endl;
    }
};

int main()
{
    int ch;
    int index = 0;

    Account *arr[5];

    do
    {
        cout << "\n\n0.EXIT" << endl;
        cout << "1. CREATE ACCOUNT " << endl;
        cout << "2. SHOW ACCOUNT " << endl;
        cout << "3. DEPOSIT" << endl;
        cout << "4. WITHDRAW" << endl;
        cout << "5. CHECK BALANCE" << endl;

        cout << "Enter Your Choice - ";
        cin >> ch;

        switch (ch)
        {
        case 0:
        {
            cout << "Exited Successfully !" << endl;
        }
        break;
        case 1:
        {
            if (index < 5)
            {
                arr[index] = new Account;
                arr[index]->accept();
            }
        }
        break;

        case 2:
        {
            arr[index]->display();
        }
        break;

        case 3:
        {
            try
            {
                arr[index]->deposit();
            }
            catch (inSufficientFundsException e)
            {
                e.display();
            }
        }
        break;

        case 4:
        {
            try
            {
                arr[index]->withdraw();
            }
            catch (inSufficientFundsException e)
            {
                e.display();
            }
        }
        break;

        case 5:
        {
            arr[index]->checkBalance();
        }
        break;

        default:
        {
            cout << "Invalid Input !" << endl;
        }
        break;
        }
    } while (ch != 0);
}
