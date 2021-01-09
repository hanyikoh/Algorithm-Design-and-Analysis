#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class BST
{
    struct node
    {
        string data;
        node *left;
        node *right;
        int height;
    };

    node *root;
    int data;
    BST *left, *right;
    bool emailFound = false;

public:
    // Default constructor.
    BST()
    {
        root = NULL;
    }

    // Parameterized constructor.
    // BST(string value);

    // Insert function.
    void Insert(string value)
    {
        root = Insert(root, value);
    }

    node *Insert(node *root, string value)
    {
        if (!root)
        {
            // Insert the first node, if root is NULL.
            root = new node;
            root->data = value;
            root->height = 0;
            root->left = root->right = NULL;
        }

        if (value > root->data)
        {
            root->right = Insert(root->right, value);
        }
        else
        {
            // Insert left node data, if the 'value'
            // to be inserted is greater than 'root' node data.

            // Process left nodes.
            root->left = Insert(root->left, value);
        }

        // Return 'root' node, after insertion.
        return root;
    }

    // Inorder traversal.
    void Inorder(node *, string searchData);

    void search(string data)
    {
        string searchData = data;
        Inorder(root, searchData);
        // if (emailFound)
        //   emailFound = false;
        // else
        //   cout << "Email not found!!!\n";
        if (!emailFound)
            cout << "Email not found!!!\n";
    }
};

void BST ::Inorder(node *root, string searchData)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left, searchData);
    if (root->data == searchData)
    {
        cout << searchData << " Found!" << endl;
    };
    Inorder(root->right, searchData);
}

// Driver code
int main()
{
    cout << "1. Set A\n"
         << "2. Set B\n"
         << "3. Set C\n"
         << "->";
    int cmd, size;
    string setName;
    cin >> cmd;
    switch (cmd)
    {
    case 1:
        size = 100;
        setName = "email_100";
        break;
    case 2:
        size = 100000;
        setName = "email_100000";
        break;
    case 3:
        size = 500000;
        setName = "email_500000";
        break;
    default:
        cout << "Invalid Input!!!\n\n";
    }
    cout << size;
    auto start = std::chrono::high_resolution_clock::now();
    BST avl;
    ifstream read;
    string data;
    read.open(setName + ".txt");
    for (int i = 0; i < size; i++)
    {
        cout << "HI";
        getline(read, data);
        cout << data;
        avl.Insert(data);
    }
    read.close();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    cout << "\nInsert Time: " << microseconds << " microseconds.\n";

    cout << "\nLoading Search Data:\n";
    setName += " Found";
    read.open(setName + ".txt");
    for (int i = 0; i < 20; i++)
    {
        start = std::chrono::high_resolution_clock::now();
        getline(read, data);
        cout << "Searching for \"" << data << "\" ...\n";
        avl.search(data);
        elapsed = std::chrono::high_resolution_clock::now() - start;
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        cout << "Total Search Time: " << microseconds << " microseconds\n\n";
    }

    return 0;
}
