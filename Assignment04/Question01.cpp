#include <iostream>
using namespace std;

class Time
{
    int hrs;
    int mins;
    int secs;

public:
    Time()
    {
        hrs = 0;
        mins = 0;
        secs = 0;
    }

    Time(int h, int m, int s)
    {
        this->hrs = h;
        this->mins = m;
        this->secs = s;
    }

    void setHrs(int hrs)
    {
        this->hrs = hrs;
    }
    void setMins(int mins)
    {
        this->mins = mins;
    }
    void setSecs(int secs)
    {
        this->secs = secs;
    }

    int getHours()
    {
        return hrs;
    }
    int getMins()
    {
        return mins;
    }
    int getSecs()
    {
        return secs;
    }

    void acceptTime()
    {
        cout << "\n\nEnter Hours - ";
        cin >> hrs;
        cout << "Enter Minutes - ";
        cin >> mins;
        cout << "Enter Seconds - ";
        cin >> secs;
    }

    void displayTime()
    {
        cout << "\nTime = " << hrs << " : " << mins << " : " << secs << endl;
    }
};

int main()
{
    Time *arr[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = new Time();
        arr[i]->acceptTime();
    }

    for (int i = 0; i < 5; i++)
    {
        arr[i]->displayTime();
    }

    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}