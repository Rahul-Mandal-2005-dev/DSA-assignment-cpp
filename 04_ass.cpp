#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    int priority;
    Node *next;
    Node(string data, int pri = 0) : name(data), next(NULL), priority(pri) {}
};
class NormalQueues
{
private:
    Node *head;
    Node *tail;

public:
    NormalQueues() : head(NULL), tail(NULL) {}

    void enqueue(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        Node *temp = head;
        cout << "POP: " << temp->name << endl;
        temp = temp->next;
        head = temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->name << "->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

class CircularQueues
{
private:
    Node *head;
    Node *tail;

public:
    CircularQueues() : head(NULL), tail(NULL) {}

    void enqueue(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void dequeue()
    {
        Node *temp = head;
        cout << "POP: " << temp->name << endl;
        temp = temp->next;
        head = temp;
        tail->next = head;
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->name << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "come back to head" << endl;
    }
};

class PriorityQueues
{
private:
    Node *head;

public:
    PriorityQueues() : head(NULL) {}
    void enqueue(string data, int pri)
    {
        Node *newNode = new Node(data, pri);
        if (head == NULL || pri < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node*temp = head;
            while(temp->next!= NULL && pri >=temp->next->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void dequeue()
    {
        Node *temp = head;
        cout << "POP: " << temp->name << endl;
        temp = temp->next;
        head = temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->name<<"("<<temp->priority<<")"<< "->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};
int main()
{
    NormalQueues n1;
    n1.enqueue("Rahul");
    n1.enqueue("Ranjan");
    n1.enqueue("Mandal");
    n1.display();
    n1.dequeue();
    n1.display();
    CircularQueues c1;
    c1.enqueue("Rahul");
    c1.enqueue("Ranjan");
    c1.enqueue("Mandal");
    c1.display();
    c1.dequeue();
    c1.display();
    PriorityQueues p1;
    p1.enqueue("Rahul",2);
    p1.enqueue("Ranjan",3);
    p1.enqueue("Mandal",1);
    p1.display();
    p1.dequeue();
    p1.display();

    return 0;
}