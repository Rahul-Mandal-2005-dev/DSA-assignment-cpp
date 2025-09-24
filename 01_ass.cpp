#include <iostream>
#include <string>
using namespace std;
void Input_books(string name[], float code[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Book name " << i + 1 << ": ";
        getline(cin, name[i]);
        cout << "Book ID " << i + 1 << ": ";
        cin >> code[i];
        cin.ignore();
        cout<<"\n";
    }
}
void Display_books(string name[], float code[], int size)
{
    cout<<"Sr No\t\tBooks\t\tBooks ID"<<endl;
    for (int i = 0; i < size; i++)
    {
       cout<<i+1<<"\t\t"<<name[i]<<"\t\t"<<code[i]<<endl;
    }
}
int linear_searching(string name[], string target, int n)
{
    bool boolean = true;
    for (int i = 0; i < n; i++)
    {
        if (name[i] == target)
        {
            return i;
            boolean = false;
            break;
        }
    }
    if (boolean)
    {
        return -1;
    }
}
int binary_searching(float name[], int target, int n)
{
    int left = 0, right = n - 1;
    bool boolean = true;
    for (int i = 0; i < n; i++)
    {
        int mid = (int)(left + right) / 2;
        if (name[mid] == target)
        {
            return mid;
            boolean = false;
            break;
        }
        else if (name[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (boolean)
    {
        return -1;
    }
}
int main()
{
    string name[1000];
    float code[1000];
    int size, method, target1;
    string target;
    cout << "Enter Number of Book: ";
    cin >> size;
    cin.ignore();
    cout << "Input Books/ID -" << endl;
    Input_books(name, code, size);
    cout << "Books Display -" << endl;
    Display_books(name, code, size);

    cout << "------------------------------------";
    cout << "\nSearching the Book by name/ID\n"
         << "method 1 - linear search\n"
         << "method 2 - binary search\n";
    cout << "------------------------------------";
    cout << "\nEnter method: ";
    cin >> method;
    cout << "------------------------------------" << endl;
    cin.ignore();
    if (method == 1)
    {
        cout << "Book name: ";
        getline(cin, target);
        int idx = linear_searching(name, target, size);
        if (idx != -1)
        {
            cout << "Result -\nBook name: " << name[idx] << "\nBook ID: " << code[idx];
        }
        else
        {
            cout << "Result - \nBook is not available";
        }
    }
    else if (method == 2)
    {
        cout << "Book ID: ";
        cin >> target1;
        int idx = binary_searching(code, target1, size);
        if (idx != -1)
        {
            cout << "Result -\nBook name: " << name[idx] << "\nBook ID: " << code[idx];
        }
        else
        {
            cout << "Result - \nBook is not available";
        }
    }
    else
    {
        cout << "Invalid Method";
    }
    return 0;
}