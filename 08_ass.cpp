#include <iostream>
using namespace std;
#define size 10
class Employee
{
public:
    int empID;
    string name;
    float salary;
    bool isEmpty;
    Employee() : empID(-1), name(""), salary(0.0), isEmpty(true) {}
};

class HashMap
{
    Employee HashTable[size];
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    void insert(Employee e)
    {
        int index = hashFunction(e.empID);
        while (!HashTable[index].isEmpty)
        {
            index = (index + 1) % 10;
        }
        HashTable[index] = e;
        HashTable[index].isEmpty = false;
        cout << "Employee insert at index " << index << endl;
    }
    void search(int empID)
    {
        int index = hashFunction(empID);
        int start = index;
        while (!HashTable[index].isEmpty)
        {
            if (HashTable[index].empID == empID)
            {
                cout << "Employee Found -> name = " << HashTable[index].name;
                cout << " | salary = " << HashTable[index].salary << endl;

                return;
            }
            index = (index + 1) % 10;
            if (start == index)
                break;
        }
        cout << "Employee Not found" << endl;
    }

    void remove(int empId)
    {
        int index = hashFunction(empId);
        int start = index;
        while (!HashTable[index].isEmpty)
        {
            if (HashTable[index].empID == empId)
            {
                HashTable[index].isEmpty = true;
                cout << "Employee Delete at index : " << index << endl;
                return;
            }
            index = (index + 1) % 10;
            if (start == index)
                break;
        }
        cout << "Employee not found" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            bool con = true;
            cout << "Index : " << i;
            if (!HashTable[i].isEmpty)
            {
                cout << " | empId : " << HashTable[i].empID;
                cout << " | name : " << HashTable[i].name;
                cout << " | salary : " << HashTable[i].salary;
                cout << endl;
                con = false;
            }
            if (con)
                cout << "[empty]" << endl;
        }
    }
};
int main()
{
    HashMap h1;
    Employee e;
    int num;
    do
    {
        cout << "1-Insert" << endl
             << "2-Search" << endl
             << "3-Delete" << endl
             << "4-Display" << endl
             << "5-Exit" << endl;
        cout << "Input Operation: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            cout << "Enter empId: ";
            cin >> e.empID;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, e.name);
            cout << "Enter salary: ";
            cin >> e.salary;
            h1.insert(e);
            break;
        case 2:
            cout << "Enter empId: ";
            cin >> e.empID;
            h1.search(e.empID);
            break;
        case 3:
            cout << "Enter empId: ";
            cin >> e.empID;
            h1.remove(e.empID);
            break;
        case 4:
            h1.display();
            break;
        case 5:
            cout << "exit" << endl;
            break;

        default:
            cout << "Invalid index" << endl;
            break;
        }

    } while (num != 5);

    return 0;
}