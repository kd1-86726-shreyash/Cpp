#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
    double price;

public:
    Product()
    {
    }

    Product(int id, string title, double price)
    {
        this->id = id;
        this->price = price;
        this->title = title;
    }

    int getPrice()
    {
        return price;
    }

    virtual void accept()
    {
        cout << "Enter ID - ";
        cin >> id;
        cout << "Enter Title - ";
        cin >> title;
        cout << "Enter Price - ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "ID = " << id << endl;
        cout << "Title = " << title << endl;
        cout << "Price = " << price << endl;
    }
};
class Book : public Product
{
    string bookAuthor;

public:
    Book()
    {
    }

    Book(int id, string title, string bookAuthor, double price) : Product(id, title, price)
    {

        this->bookAuthor = bookAuthor;
    }

    void accept()
    {
        Product::accept();
        cout << "Enter Book Author - ";
        cin >> bookAuthor;
    }
    void display()
    {
        Product::display();
        cout << "Book Author = " << bookAuthor << endl;
    }
};

class Tape : public Product
{

    string tapeArtist;

public:
    Tape()
    {
    }

    Tape(int id, string title, string tapeArtist, double price) : Product(id, title, price)
    {

        this->tapeArtist = tapeArtist;
    }

    void accept()
    {
        Product::accept();
        cout << "Enter Tape Artist - ";
        cin >> tapeArtist;
    }

    void display()
    {
        Product::display();
        cout << "Tape Artist = " << tapeArtist << endl;
    }
};

int menu()
{
    int ch;
    cout << "\n\n----Menu----" << endl;
    cout << "0. EXIT " << endl;
    cout << "1. ADD BOOK" << endl;
    cout << "2. ADD TAPE " << endl;
    cout << "3. Display Final Bill" << endl;

    cout << "\nEnter Your Choice - ";
    cin >> ch;
    return ch;
}

void finalPrice(Product **ptr,int index)
{
    double dprice = 0;
    double totalPrice = 0;

    for (int i = 0; i < index; i++)
    {
        if (typeid(*ptr[i]) == typeid(Book))
        {
            dprice = ptr[i]->getPrice() - (ptr[i]->getPrice() * .10);
        }
        else
        {
            dprice = ptr[i]->getPrice() - (ptr[i]->getPrice() * .05);
        }
        totalPrice += dprice;
    }

    cout << "\n\nFinal Bill = " << totalPrice << endl;
}

int main()
{
    Product *arr[3];
    int index = 0;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if (index < 3)
            {
                arr[index] = new Book;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Your Cart is FUll , Cant add the book - " << endl;
            }
        }
        break;
        case 2:
        {
            if (index < 3)
            {
                arr[index] = new Tape;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Your Cart is FUll , Cant add the Tape - " << endl;
            }
        }
        break;

        case 3:
        {
            finalPrice(arr,index);
        }

        default:
            break;
        }
    }
}