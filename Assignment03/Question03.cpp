#include <iostream>

using namespace std;

class Address
{
    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        building = " ";
        street = " ";
        city = " ";
        pin = 0;
    }

    Address(string building, string street, string city, int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void setBuilding(string b)
    {
        this->building = b;
    }

    string getBuiding()
    {
        return this->building;
    }

    void setStreet(string s)
    {
        this->street = s;
    }

    string getStreet()
    {
        return this->street;
    }
    void setCity(string c)
    {
        this->city = c;
    }

    string getCity()
    {
        return this->city;
    }

    void setPin(int p)
    {
        this->pin = p;
    }

    int getPin()
    {
        return this->pin;
    }

    void acceptAddress()
    {
        cout << "\nEnter BuldingName - " << endl;
        getchar();
        getline(cin, this->building);
       // cin>>building;
        cout << "Enter StreetName - " << endl;
        getchar();
        getline(cin, this->street);
        //cin>>street;
        cout << "Enter CityName - " << endl;
        getchar();
        getline(cin, this->city);
        //cin>>city;
        cout << "Enter Pincode - " << endl;
        cin >> this->pin;
        if (pin < 0)
        {
            cout << "\n\nPincode Cannot Be Negative !" << endl;
        }
    }

    void displayAddress()
    {
        cout << "Address = " << building << "," << street << "," << city << "," << pin << endl;
    }
};

int menu()
{
    int ch;
    cout << "\n\n---MENU---" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ACCEPT ADDRESS" << endl;
    cout << "2. DIsplay ADDRESS" << endl;

    cout << "\n\nENTER YOUR CHOICE - ";
    cin >> ch;

    return ch;
}
int main()
{
    Address a1;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            a1.acceptAddress();
        }
        break;

        case 2:
        {
            a1.displayAddress();
        }
        break;

        default:
        {
            cout << "Invalid Input!";
        }
        break;
        }
    }
}
