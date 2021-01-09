#include <iostream>
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
#include "email.cpp"
#include "avlTree.cpp"
#include "Priority Queue.cpp"

using namespace std;

void generateEmail();
void avlTree(string);
void priorityQueue(vector<string>);

int main()
{
    vector<string> vectEmail100;
    vector<string> vectEmail100000;
    vector<string> vectEmail500000;
    generateEmail();

    string line;
    ifstream myfile1("email_100.txt"); //opening the file.
    if (myfile1.is_open())             //if the file is open
    {
        while (!myfile1.eof()) //while the end of file is NOT reached
        {
            getline(myfile1, line);       //get one line from the file
            vectEmail100.push_back(line); //output loop statement
        }
        myfile1.close(); //closing the file
    }
    else
        cout << "Unable to open file";
    myfile1.close();
    myfile1.open("email_100000.txt"); //opening the file.
    if (myfile1.is_open())            //if the file is open
    {
        while (!myfile1.eof()) //while the end of file is NOT reached
        {
            getline(myfile1, line);          //get one line from the file
            vectEmail100000.push_back(line); //output loop statement
        }
        myfile1.close(); //closing the file
    }
    else
        cout << "Unable to open file";

    myfile1.close();

    myfile1.open("email_500000.txt"); //opening the file.
    if (myfile1.is_open())            //if the file is open
    {
        while (!myfile1.eof()) //while the end of file is NOT reached
        {
            getline(myfile1, line);          //get one line from the file
            vectEmail500000.push_back(line); //output loop statement
        }
        myfile1.close(); //closing the file
    }
    else
        cout << "Unable to open file";
    myfile1.close();
    vectEmail100.pop_back();
    vectEmail100000.pop_back();
    vectEmail500000.pop_back();

    int choice;
    while (true)
    {
        cout << "Please select a algorithm to run the program" << endl;
        cout << "1. HashTable " << endl;
        cout << "2. AVL" << endl;
        cout << "3. Priority Queue" << endl;
        cout << "4. End" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            avlTree("100");
            avlTree("100000");
            avlTree("500000");
            break;
        case 3:
            priorityQueue(vectEmail100);
            priorityQueue(vectEmail100000);
            priorityQueue(vectEmail500000);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please select again!" ;
            break;
        }
    };


    return 0;
}
