#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class SingleLinkedList
{
    Node *head;

public:
    SingleLinkedList() : head(nullptr) {}
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void del(int target)
    {
        if (!head)
            return;
        if (head->data == target)
        {
            Node *delNode = head;
            cout << "del: " << head->data << endl;
            head = head->next;
            delete delNode;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != target)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            Node *delNode = temp->next;
            cout << "del: " << head->next->data << endl;
            temp->next = temp->next->next;
            delete delNode;
        }
    }
    void treverse()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
    void search(int target)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == target)
            {
                cout << "data: " << temp->data << "\tidx: " << pos << endl;
                break;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
    }
    void sorting()
    {
        for (Node *i = head; i->next; i = i->next)
        {
            for (Node *j = head; j->next; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }

    void concatenate(SingleLinkedList &list2)
    {
        if (!head)
        {
            head = list2.head;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = list2.head;
        list2.head = nullptr;
    }
};
int main()
{
    int choice, val;
    SingleLinkedList list1, list2;
    do
    {
        cout << "Menu" << endl
             << "1 insert at end" << endl
             << "2 delete at end" << endl
             << "3 treverse" << endl
             << "4 searching" << endl
             << "5 sorting" << endl
             << "6 concatenate" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "val : ";
            cin >> val;
            list1.insert(val);
            break;
        case 2:
            cout << "del data : ";
            cin >> val;
            list1.del(val);
            break;
        case 3:
            list1.treverse();
            break;
        case 4:
            cout << "search : ";
            cin >> val;
            list1.search(val);
            break;
        case 5:
            list1.sorting();
            break;
        case 6:
            cout << "Enter -1: stop" << endl;
            while (true)
            {
                cout << "val : ";
                cin >> val;
                if (val == -1)
                {
                    break;
                }
                list2.insert(val);
            } 
            list1.concatenate(list2);
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}