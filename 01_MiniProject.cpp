#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char val) : data(val), next(NULL) {}
};

class Stack
{
    Node *top;

public:
    Stack() : top(NULL) {}

    void insert(char val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (!top)
            return;
        Node *temp = top;
        top = temp->next;
        delete temp;
    }

    bool empty()
    {
        return top == NULL;
    }
    char stacktop()
    {
        return top->data;
    }
};
int preferences(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return 0;
}

string InfixToPostfix(string Infix)
{
    string res;
    Stack s1;
    for (char x : Infix)
    {
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
            res += x;

        else if (x == '(')
            s1.insert(x);

        else if (x == ')')
        {
            while (!s1.empty() && s1.stacktop() != '(')
            {
                res += s1.stacktop();
                s1.pop();
            }
            if (!s1.empty())
                s1.pop();
        }
        else
        {
            while (!s1.empty() && preferences(s1.stacktop()) >= preferences(x))
            {
                res += s1.stacktop();
                s1.pop();
            }
            s1.insert(x);
        }
    }
    while (!s1.empty())
    {
        res += s1.stacktop();
        s1.pop();
    }
    return res;
}

int main()
{
    string Infix;
    cout<<"Infix : ";
    cin>>Infix;
    string Postfix = InfixToPostfix(Infix);
    cout <<"Postfix : "<<Postfix;
    return 0;
}