#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void Input(string name[],float salary[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nEmployee name " << i + 1 << " : ";
        getline(cin, name[i]);
        cout << "Employee salary: " << i + 1 << " : ";
        cin >> salary[i];
        cin.ignore();
    }
}

void Display(string name[],float salary[],int size)
{
    cout<<"Sr No\t\tEmployee\t\tSalary"<<endl;
    for (int i = 0; i < size; i++)
    {
       cout<<i+1<<"\t\t"<<name[i]<<"\t\t"<<salary[i]<<endl;
    }
}

void FinalDisplay(string name[],float salary[],int size)
{
    cout<<"Sorted - "<<endl;
    cout<<"Sr No\t\tEmployee\t\tSalary"<<endl;
    for (int i = 0; i < size; i++)
    {
       cout<<i+1<<"\t\t"<<name[i]<<"\t\t"<<salary[i]<<endl;
    }

}
void bubble_sort(string name[], float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap(name[j], name[j + 1]);
            }
    }
}

void selection_sort(string name[], float salary[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smaller = i;
        for (int j = i + 1; j < n; j++)
        {
            if (salary[smaller] < salary[j])
            {
                smaller = j;
            }
        }
        swap(salary[smaller], salary[i]);
        swap(name[smaller], name[i]);
    }
}

void insertion_sort(string name[], float salary[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = salary[i];
        string current1 = name[i];
        int j = i - 1;
        while (j >= 0 && current > salary[j])
        {
            salary[j + 1] = salary[j];
            name[j + 1] = name[j];
            j--;
        }
        salary[j + 1] = current;
        name[j + 1] = current1;
    }
}
int partition(string name[], float salary[], int start, int end)
{
    int idx = start - 1;
    int pivot = salary[end];
    for (int i = start; i < end; i++)
    {
        if (salary[i] >= pivot)
        {
            idx++;
            swap(salary[idx], salary[i]);
            swap(name[idx], name[i]);
        }
    }
    idx++;
    swap(salary[end], salary[idx]);
    swap(name[end], name[idx]);
    return idx;
}
void quick_sort(string name[], float salary[], int start, int end)
{
    if (start < end)
    {
        int pivot_idx = partition(name, salary, start, end);
        quick_sort(name, salary, start, pivot_idx - 1);
        quick_sort(name, salary, pivot_idx + 1, end);
    }
}

using namespace std;
int main()
{

    string name[1000];
    float salary[1000];
    int method, size;
    bool boolean = true;
    cout << "Enter the size of employee/salary: ";
    cin >> size;
    cin.ignore();
    Input(name,salary,size);
    Display(name,salary,size);

    cout<<"----------------------------------------"<<endl;
    cout << "Arrange the employee by there salary" << endl;
    cout<<"----------------------------------------"<<endl;
    cout << "method 1 - Bubble sort" << endl
    << "method 2 - Selection sort" << endl
    << "method 3 - Insertion sort" << endl
    << "method 4 - Quick sort" << endl;
    cout<<"----------------------------------------"<<endl;
    cout<< "Enter method: ";
    cin >> method;
    cout<<"----------------------------------------"<<endl;
    switch (method)
    {
        case 1:
            cout<<"Bubble sort - "<<endl;
            bubble_sort(name, salary, size);
            cout<<"----------------------------------------"<<endl;
            break;
        case 2:
            cout<<"Selection sort - "<<endl;
            selection_sort(name, salary, size);
            cout<<"----------------------------------------"<<endl;
            break;
        case 3:
            cout<<"Insertion sort - "<<endl;
            insertion_sort(name, salary, size);
            cout<<"----------------------------------------"<<endl;
            break;
        case 4:
            {
            cout<<"Quick sort - "<<endl;
            int start = 0, end = size - 1;
            quick_sort(name, salary, start, end);
            cout<<"----------------------------------------"<<endl;
            break;
            }
        default:
            cout<<"Invalid Choice"<<endl;
            boolean = false;
            break;
    }
    if(boolean)
    FinalDisplay(name,salary,size);
    return 0;
}