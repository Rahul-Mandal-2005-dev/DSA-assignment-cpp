#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), right(NULL), left(NULL) {}
};
class BinarySearchTree
{
private:
    Node *root;
    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        else if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        else
            cout << "NO Duplicate element" << endl;

        return root;
    }

    Node *InOrderMin(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
    Node *del(Node *root, int key)
    {
        if (!root)
            return root;
        else if (key < root->data)
            root->left = del(root->left, key);
        else if (key > root->data)
            root->right = del(root->right, key);
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = InOrderMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }

        return root;
    }
    bool searching(Node *root, int target)
    {
        if (!root)
            return false;

        if (root->data == target)
            return true;

        else if (target < root->data)
            return searching(root->left, target);

        else
            return searching(root->right, target);
    }
    void inOrder(Node *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << "--->";
        inOrder(root->right);
    }
    void preOrder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << "--->";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node *root)
    {
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "--->";
    }

public:
    BinarySearchTree() : root(NULL) {}
    void insert(int val)
    {
        root = insert(root, val);
    }

    void inOrder()
    {
        inOrder(root);
        cout << "None" << endl;
    }
    void preOrder()
    {
        preOrder(root);
        cout << "None" << endl;
    }
    void postOrder()
    {
        postOrder(root);
        cout << "None" << endl;
    }

    void del(int key)
    {
        root = del(root, key);
    }

    void searching(int key)
    {
        bool boolean = searching(root, key);
        if (boolean)
            cout << key << " Found" << endl;
        else
            cout << key << " Not Found" << endl;
    }

    void BFS()
    {
        if (!root)
            return;

        Node *arr[100];
        int head = 0, tail = 0;
        arr[tail] = root;
        tail++;
        while (head < tail)
        {
            Node *curr = arr[head];
            head++;
            cout << curr->data << "--->";
            if (curr->left)
                arr[tail++] = curr->left;
            if (curr->right)
                arr[tail++] = curr->right;
        }
        cout<<"None"<<endl;
    }
};
int main()
{
    BinarySearchTree b1;
    b1.insert(30);
    b1.insert(20);
    b1.insert(10);
    b1.insert(60);
    b1.insert(45);
    b1.insert(40);
    b1.insert(50);
    b1.inOrder();
    b1.del(10);
    b1.searching(20);
    b1.inOrder();
    b1.preOrder();
    b1.postOrder();
    b1.BFS();

    return 0;
}