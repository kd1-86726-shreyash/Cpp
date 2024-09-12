
#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *stk;

public:
    Stack()
    {
        size = 5;
        top = -1;
        stk = new int[5];
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool peek(int &ele)
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty !" << endl;
            return false;
        }
        else
        {
            ele = stk[top];
            return true;
        }
    }

    bool push(int &ele)
    {
        if (isFull())
        {
            cout << "OverFlow Condition - Stack is Full !" << endl;
            return false;
        }
        else
        {
            this->stk[++top] = ele;
            return true;
        }
    }

    bool pop(int &ele)
    {
        if (isEmpty())
        {
            cout << "UnderFlow Condition - Stack is Empty!" << endl;
            return false;
        }
        else
        {
            ele = this->stk[top--];
            return true;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack If Empty - No elements to display!";
        }
        else
        {
            cout << "Elements in the stack - ";
            for (int i = 0; i <= top; i++)
            {
                cout << stk[i] << endl;
            }
        }
    }
};

int menu()
{
    int ch;

    cout << "\n\n---Menu---" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. PUSH" << endl;
    cout << "2. POP" << endl;
    cout << "3. PEEK" << endl;
    cout << "4. DISPLAY" << endl;

    cout << "\n\nEnter Your Choice - ";
    cin >> ch;

    return ch;
}

int main()
{
    int choice;
    Stack st;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter Element To Push - ";
            cin >> element;
            if (st.push(element))
            {
                cout << element << " is Added In Stack!" << endl;
            }
        }
        break;
        case 2:
        {
            int element;
            if (st.pop(element))
            {
                cout << element << " deleted sucessfully!" << endl;
            }
        }
        break;
        case 3:
        {
            int element;
            if (st.peek(element))
            {
                cout << element << " is at the Top ELement !" << endl;
            }
        }
        break;
        case 4:
        {
            st.display();
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