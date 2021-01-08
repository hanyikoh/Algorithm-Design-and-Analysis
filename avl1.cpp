#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
using namespace std;

struct AVLNode
{
    string Name;
    int Balance;
    AVLNode *LeftChild;
    AVLNode *RightChild;
};

AVLNode *InputData(ifstream &);
AVLNode *InsertData(AVLNode *, AVLNode *);
int FindBalance(AVLNode *);
void Traversal(AVLNode *);
AVLNode *LeftLeft(AVLNode *);
AVLNode *RightRight(AVLNode *);
AVLNode *LeftRight(AVLNode *);
AVLNode *RightLeft(AVLNode *);
void search(string);
void inorder(AVLNode *t);
bool emailFound = false;
string searchData;
AVLNode *Root = NULL;

void search(string data)
{
    searchData = data;
    inorder(Root);
    if (emailFound)
        emailFound = false;
    else
        cout << "Email not found!!!\n";
}

void inorder(AVLNode *t)
{
    if (t == NULL || emailFound)
        return;

    inorder(t->LeftChild);
    if (searchData == t->Name)
    {
        cout << "Email found!!!\n";
        emailFound = true;
        return;
    }

    inorder(t->RightChild);
}

int main()
{
    ifstream CheckFile; //ifstream checks for file existence
    char inputFileName[] = "100000.txt";
    CheckFile.open(inputFileName); //attempts to open read file, and tests for existence
    auto start = chrono::system_clock::now();
    if (!CheckFile)
        cout << "Input file does not exist." << endl
             << endl;
    else
        cout << "file opend" << endl;
    Root = InputData(CheckFile);
    // cout << "taversal:\n\n";
    //    Traversal(head);
    //cout << endl;

    // system("PAUSE");
    // return EXIT_SUCCESS;
    CheckFile.close();
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Duration for insert: " << duration.count() << "s\n";

    string data;
    cout << "\nLoading Search Data:\n";
    CheckFile.open("Email Found.txt");
    for (int i = 0; i < 10; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        getline(CheckFile, data);
        cout << "Searching for \"" << data << "\" ...\n";
        search(data);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        cout << "Total Search Time: " << microseconds << " microseconds\n\n";
    }
}

AVLNode *InputData(ifstream &InFile)
{
    Root = NULL;
    AVLNode *Leaf;
    while (!InFile.eof())
    {
        Leaf = new AVLNode;
        getline(InFile, Leaf->Name);
        Leaf->Balance = 0;
        Leaf->RightChild = Leaf->LeftChild = NULL;
        if (Root == NULL)
            Root = Leaf;
        Root = InsertData(Leaf, Root);
    }
    return Root;
}

AVLNode *InsertData(AVLNode *Leaf, AVLNode *Root)
{
    if (Root == NULL)
        return Leaf;
    else if (Leaf->Name < Root->Name)
    {
        Root->LeftChild = InsertData(Leaf, Root->LeftChild);
        if (FindBalance(Root->LeftChild) - FindBalance(Root->RightChild) == 2)
        {
            if (Leaf->Name < Root->LeftChild->Name)
                Root = LeftLeft(Root);
            else
                Root = LeftRight(Root);
        }
    }
    else if (Leaf->Name > Root->Name)
    {
        Root->RightChild = InsertData(Leaf, Root->RightChild);
        if (FindBalance(Root->RightChild) - FindBalance(Root->LeftChild) == 2)
        {
            if (Leaf->Name > Root->RightChild->Name)
                Root = RightRight(Root);
            else
                Root = RightLeft(Root);
        }
    }
    Root->Balance = max(FindBalance(Root->LeftChild), FindBalance(Root->RightChild)) + 1;
    return Root;
}

int FindBalance(AVLNode *Root)
{
    if (Root == NULL)
        return -1;
    else
        return Root->Balance;
}

AVLNode *LeftLeft(AVLNode *Rotate)
{
    AVLNode *Pivot = Rotate->LeftChild;
    Rotate->LeftChild = Pivot->RightChild;
    Pivot->RightChild = Rotate;
    Rotate->Balance = max(FindBalance(Rotate->LeftChild), FindBalance(Rotate->RightChild)) + 1;
    Pivot->Balance = max(FindBalance(Pivot->LeftChild), FindBalance(Rotate->RightChild)) + 1;
    return Pivot;
}

AVLNode *RightRight(AVLNode *Rotate)
{
    AVLNode *Pivot = Rotate->RightChild;
    Rotate->RightChild = Pivot->LeftChild;
    Pivot->LeftChild = Rotate;
    Rotate->Balance = max(FindBalance(Rotate->LeftChild), FindBalance(Rotate->RightChild)) + 1;
    Pivot->Balance = max(FindBalance(Pivot->RightChild), FindBalance(Rotate->LeftChild)) + 1;
    return Pivot;
}

AVLNode *LeftRight(AVLNode *RotateTop)
{
    RotateTop->LeftChild = RightRight(RotateTop->LeftChild);
    return LeftLeft(RotateTop);
}

AVLNode *RightLeft(AVLNode *RotateTop)
{
    RotateTop->RightChild = LeftLeft(RotateTop->RightChild);
    return RightRight(RotateTop);
}

void Traversal(AVLNode *Root)
{
    AVLNode *temp;
    if (Root != NULL)
    {
        Traversal(Root->LeftChild);        // print left subtree
        cout << "(" << Root->Name << ", "; // print this node
        if (Root->LeftChild == NULL)
            cout << "NULL, ";

        else
        {
            temp = Root->LeftChild;
            cout << temp->Name << ", ";
        }

        if (Root->RightChild == NULL)
            cout << "NULL, ";
        else
        {
            temp = Root->RightChild;
            cout << temp->Name << ", ";
        }

        int temp1 = (FindBalance(Root->RightChild) - FindBalance(Root->LeftChild));
        cout << temp1 << ")" << endl;
        Traversal(Root->RightChild); // print right subtree
    }
    return;
}
