#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
#include <fstream>
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
        node* left;
        node* right;
        int height;
    };

    node* root;
    string searchData;
    bool done = false;

    node* insert(string x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    void inorder(node* t)
    {
        if (t == NULL || done)
          return;

        inorder(t->left);
        if (this->searchData == t->data)
        {
          cout << "Email found!!!\n";
          done = true;
          return;
        }

        inorder(t->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(string x)
    {
        root = insert(x, root);
    }


    void display()
    {
        inorder(root);
        cout << endl;
    }

    void search(string data)
    {
        searchData = data;
        inorder(root);
        if (done)
          done = false;
        else
          cout << "Email not found!!!\n";
    }

};

int main()
{
  cout << "1. Set A\n"
       << "2. Set B\n"
       << "3. Set C\n"
       << "->";
  int cmd, size;
  string setName;
  cin >> cmd;
  switch(cmd)
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

  auto start = std::chrono::high_resolution_clock::now();
  BST avl;
  ifstream read;
  string data;
  read.open(setName+".txt");
  for (int i=0; i<size; i++)
  {
    getline(read, data);
    avl.insert(data);
  }
  read.close();
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

  cout << "\nInsert Time: " << microseconds << " microseconds.\n";

  cout << "\nLoading Search Data:\n";
  setName += " Found";
  read.open(setName+".txt");
  for (int i=0; i<20; i++)
  {
    start = std::chrono::high_resolution_clock::now();
    getline(read, data);
    cout << "Searching for \"" << data <<"\" ...\n";
    avl.search(data);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << "Total Search Time: " << microseconds << " microseconds\n\n";
  }

  return 0;
}
