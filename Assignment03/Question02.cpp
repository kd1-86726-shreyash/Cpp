/*
#include <iostream>

class Tollbooth
{
    unsigned int carCount;
    double cashTotal;
    unsigned int payingCarCount;
    unsigned int noPayCarCount;

public:
    Tollbooth() : carCount(0), cashTotal(0.0), payingCarCount(0), noPayCarCount(0) {}

    void payingCar()
    {
        carCount++;
        cashTotal += 0.50;
        payingCarCount++;
    }

    void nopayCar()
    {
        carCount++;
        noPayCarCount++;
    }

    void printOnConsole() const
    {
        std::cout << "Total number of cars: " << carCount << std::endl;
        std::cout << "Total amount of money collected: Rs" << cashTotal << std::endl;
        std::cout << "Number of paying cars: " << payingCarCount << std::endl;
        std::cout << "Number of non-paying cars: " << noPayCarCount << std::endl;
    }
};

int main()
{
    Tollbooth tollbooth;

    tollbooth.payingCar();
    tollbooth.nopayCar();
    tollbooth.payingCar();

    tollbooth.printOnConsole();

    return 0;
}
*/

#include <iostream>
using namespace std;

int payingCar;
int nonPayingCars;

class TollBooth
{
    unsigned int totalCars;
    double totalMoney;

public:
    TollBooth()
    {
        totalCars = 0;
        totalMoney = 0;
    }

    TollBooth(unsigned int totalCars, double totalMoney)
    {
        this->totalCars = totalCars;
        this->totalMoney = totalMoney;
    }

    void payingCars()
    {
        payingCar++;
        totalCars += 1;
        totalMoney += 50;
    }

    void nopayCar()
    {
        nonPayingCars++;
        totalCars += 1;
        totalMoney += 0;
    }

    void printonConsole()
    {
        cout << "\n\nTotal Cars = " << totalCars << endl;
        cout << "Total Amount Collected  = Rs" << totalMoney << endl;
        cout << "Paying Cars = " << payingCar << endl;
        cout << "NonPaying Cars = " << nonPayingCars << endl;
    }
};

int menu()
{
    int ch;

    cout << "\n\n---Menu---" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ADD PAYING CARS" << endl;
    cout << "2. ADD NON-PAYING CARS" << endl;
    cout << "3. TOTAL AMOUNT COLLECTION" << endl;

    cout << "\n\nENTER YOUR CHOICE - ";
    cin >> ch;

    return ch;
}

int main()
{
    int choice;
    TollBooth t1;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            t1.payingCars();
        }
        break;

        case 2:
        {
            t1.nopayCar();
        }
        break;

        case 3:
        {
            t1.printonConsole();
        }
        break;
        default:
        cout<<"Invalid Input !";
            break;
        }
    }
}
