#include <iostream>
using namespace std;
class Node
{
public:
    string url;
    Node *next;
    Node(string data) : url(data) {}
};
class StackLinkedList
{
private:
    Node *top;

public:
    StackLinkedList() : top(nullptr) {}

    void push(string data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            Node *temp = top;
            cout << "POP: " << temp->url << endl;
            delete temp;
            top = top->next;
        }
    }

    void peek()
    {
        if (top == nullptr)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            Node *temp = top;
            cout << "Peek: " << temp->url << endl;
        }
    }
    void display()
    {
        if (top == nullptr)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            Node *temp = top;
            int count = 0;
            while (temp != nullptr)
            {
                count++;
                cout << "url " << count << ":" << temp->url << endl;
                temp = temp->next;
            }
        }
    }
};

class StackArray
{
    static const int Max = 5;
    string arr[Max];
    int top;

public:
    StackArray() : top(-1) {}
    void push(string data)
    {
        if (top == Max - 1)
        {
            cout << "Array is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == 0)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            cout << "POP: " << arr[top] << endl;
            top--;
        }
    }
    void peek()
    {
        if (top == 0)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            cout << "Peek: " << arr[top] << endl;
        }
    }
    void display()
    {
        if (top == 0)
        {
            cout << "No element Exit" << endl;
        }
        else
        {
            int count = 0;
            for (int i = top; i >= 0; i--)
            {
                count++;
                cout << "url " << count << ":" << arr[i] << endl;
            }
        }
    }
};
int main()
{
    int choose, types;
    string url;
    cout << "----------Mention Choice-----------: " << endl;
    cout << "Choice 1 - Stack with Array" << endl;
    cout << "Choice 2 - Stack with LinkedList" << endl;
    cout << "Choose: ";
    cin >> choose;
    if (choose == 1 || choose == 2)
        cout << "Valid Choice";
    else
        cout << "Invalid Choice" << endl;
    StackArray a1;
    StackLinkedList l1;
    do
    {
        cout << "Menu: " << endl;
        cout << "1. Visit newPage" << endl;
        cout << "2. Go Back " << endl;
        cout << "3. Show Current " << endl;
        cout << "4. Show History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Process: ";
        cin >> types;
        cin.ignore();
        switch (types)
        {
        case 1:
            cout << "URL: ";
            getline(cin, url);

            if (choose == 1)
                a1.push(url);
            else
                a1.push(url);
            break;
        case 2:
            if (choose == 1)
                a1.pop();
            else
                a1.pop();
            break;
        case 3:
            if (choose == 1)
                a1.peek();
            else
                a1.peek();
            break;
        case 4:
            if (choose == 1)
                a1.display();
            else
                a1.display();
            break;
        case 5:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice";
            break;
        }

    } while (types != 5);

    return 0;
}