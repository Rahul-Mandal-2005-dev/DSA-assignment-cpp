#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL) {}

    void insert(int val)
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
};

int preference(char c)
{
    if (c =="^")
}
string Infix_to_Postfix(string infix)
{
    string postfix;
    Stack stack;
    for ()
}
int main()
{

    return 0;
}