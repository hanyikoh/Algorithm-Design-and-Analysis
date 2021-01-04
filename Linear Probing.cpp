#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono> // C++11
#include <ctime>
#include <list>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>
// #include <HashTable.cpp>
using namespace std;

class Email
{
public:
   int rollno;
   string name;
   Email(){};
};

class MyHashTable
{
   Email **arr;
   int size;
   int count;

public:
   MyHashTable(int s)
   {
      count = 0;
      size = s;
      arr = new Email *[size];

      for (int i = 0; i < size; i++)
         arr[i] = nullptr;
   }
   int hashIt(int n)
   {
      return n % size;
   };

   void insertItem(int key, string value)
   {
      if (count == size)
      {
         cout << " Hash full";
         return;
      }
      int hashIndex = hashIt(key);
      while (arr[hashIndex] != nullptr)
      {
         hashIndex = (hashIndex + 1) % size;
      }
      arr[hashIndex] = new Email();
      arr[hashIndex]->rollno = key;
      arr[hashIndex]->name = value;
      count++;
   };

   string getItem(int key)
   {
      if (count == 0)
      {
         return "Empty";
      }
      int hashIndex = hashIt(key);
      int temp = hashIndex;

      while (true)
      {
         if (arr[hashIndex] == nullptr)
         {
            hashIndex = (hashIndex + 1) % size;
         }
         else if (arr[hashIndex]->rollno != key)
         {
            hashIndex = (hashIndex + 1) % size;
         }
         else
            break;

         if (hashIndex == temp)
         {
            temp = -1;
            break;
         }
      }

      if (temp == -1)
      {
         return "Not Found";
      }
      else
      {
         return arr[hashIndex]->name;
      }
   }

   void deleteItem(int key)
   {
      if (count == 0)
      {
         cout << "Hash is empty";
      }
      int hashIndex = hashIt(key);
      int temp = hashIndex;
      while (true)
      {
         if (arr[hashIndex] == nullptr)
         {
            hashIndex = (hashIndex + 1) % size;
         }
         else if (arr[hashIndex]->rollno != key)
         {
            hashIndex = (hashIndex + 1) % size;
         }
         else
            break;

         if (hashIndex == temp)
         {
            temp = -1;
            break;
         }
      }

      if (temp == -1)
      {
         cout << "Not Found";
      }
      else
      {
         delete arr[hashIndex];
         arr[hashIndex] = nullptr;
         count--;
      }
   }

   void displayAll()
   {
      for (int i = 0; i < size; i++)
      {
         if (arr[i] != nullptr)
         {
            cout << "HASH_TABLE[" << i << "]: key => " << arr[i]->rollno << " value => " << arr[i]->name << endl;
         }
      }
   }

   // ~MyHashTable(){
   //    for(int i = 0; i < size; i++){
   //       if(arr[i] != nullptr){
   //          cout <<"deleting key = > " << arr[i]->rollno << " value = >" << arr[i]->name << endl;
   //          delete arr[i];
   //          arr[i] = nullptr;
   //       }
   //    }
   // }
};

int main()
{
   fstream myfile1;
   vector<string> vectEmail;
   vector<string> vectEmailFound;
   string line;
   myfile1.open("email_100.txt"); //opening the file.
   if (myfile1.is_open())         //if the file is open
   {
      while (!myfile1.eof()) //while the end of file is NOT reached
      {
         getline(myfile1, line);    //get one line from the file
         vectEmail.push_back(line); //output loop statement
      }
      myfile1.close(); //closing the file
   }
   else
      cout << "Unable to open file";

   vectEmail.pop_back();

   MyHashTable mht(vectEmail.size() * 1.5);

   int sum_ascii;
   auto insetStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmail.size(); i++)
   {
      for (char c : vectEmail[i])
      {
         sum_ascii += c;
      };
      mht.insertItem(mht.hashIt(sum_ascii), vectEmail[i]);
      sum_ascii = 0;
   }
   auto insetEnd = chrono::system_clock::now();
   double nanotime_insertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
   double millitime_insertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();

   mht.displayAll();
   myfile1.open("Email Found.txt");
   if (myfile1.is_open()) //if the file is open
   {
      while (!myfile1.eof()) //while the end of file is NOT reached
      {
         getline(myfile1, line);         //get one line from the file
         vectEmailFound.push_back(line); //output loop statement
      }
      myfile1.close(); //closing the file
   }
   else
      cout << "Unable to open file found";

   // vectEmailFound.pop_back();
   cout << "VECT FOUND SIZE: " << vectEmailFound.size() << endl;
   sum_ascii = 0;
   auto searchStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmailFound.size(); i++)
   {
      for (char c : vectEmailFound[i])
      {
         sum_ascii += c;
      };
      cout << "ITEM " << mht.getItem(mht.hashIt(sum_ascii)) << " At"
           << " Key => " << mht.hashIt(sum_ascii) << endl;
      sum_ascii = 0;
   }
   auto searchEnd = chrono::system_clock::now();
   double nanotime_searchTaken = chrono::duration_cast<chrono::nanoseconds>(searchEnd - searchStart).count();
   double millitime_searchTaken = chrono::duration_cast<chrono::milliseconds>(searchEnd - searchStart).count();

   cout << "\n";
   cout << "Total Nanoseconds for Inserting " << vectEmail.size() << " Emails: " << nanotime_insertTaken << " nanoseconds";
   cout << "\n";
   cout << "Average Nanoseconds for Inserting " << vectEmail.size() << " Email: " << nanotime_insertTaken / vectEmail.size() << " nanoseconds";
   cout << "\n";
   cout << "Total Milliseconds for Inserting " << vectEmail.size() << " Email: " << millitime_insertTaken << " milliseconds";
   cout << "\n";
   cout << "Average Milliseconds for Inserting " << vectEmail.size() << " Email: " << millitime_insertTaken / vectEmail.size() << " milliseconds";
   cout << "\n";

   cout << "\n";
   cout << "Total Nanoseconds for Searching " << vectEmail.size() << " Emails: " << nanotime_searchTaken << " nanoseconds";
   cout << "\n";
   cout << "Average Nanoseconds for Searching " << vectEmail.size() << " Email: " << nanotime_searchTaken / vectEmail.size() << " nanoseconds";
   cout << "\n";
   cout << "Total Milliseconds for Searching " << vectEmail.size() << " Email: " << millitime_searchTaken << " milliseconds";
   cout << "\n";
   cout << "Average Milliseconds for Searching " << vectEmail.size() << " Email: " << millitime_searchTaken / vectEmail.size() << " milliseconds";
   cout << "\n";
}