#include <iostream>
using namespace std;

class Box
{
    double length;
    double width;
    double height;

public:
    Box()
    {
        length = 2;
        width =2;
        height = 2;
    }

    Box(int value)
    {
        this->length = value;
        this->width = value;
        this->height = value;
    }

    Box(int length, int width, int height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    void calcVolume()
    {
        cout << "\n\nVolume of Box = " << length * width * height << endl;
    }
};

int menu()
{
    int ch;
    cout << "\n-----MENU-----" << endl;
    cout << "0.EXIT" << endl;
    cout << "1. Calculate Volume with default values  " << endl;
    cout << "2. Calculate Volume with length,width and height with same value  " << endl;
    cout << "3. Calculate Volume with different length,width and height values " << endl;

    cout << "\n\nENTER YOUR CHOICE - ";
    cin >> ch;

    return ch;
}

int main()
{
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            Box b1;
            b1.calcVolume();
        }
        break;

        case 2:
        {
            Box b2(7);
            b2.calcVolume();
        }
        break;

        case 3:
        {
            Box b3(5,10,15);
            b3.calcVolume();
        }
        break;

        default:
        {
            cout<<"\n\nInvalid Input";
        }
            break;
        }
    }
}