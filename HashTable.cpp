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
#include "HT_Chaining.cpp"
#include "HT_LinearProbing.cpp"

void buildHashTable(HT_Chaining);

int main()
{
   fstream myfile1;
   vector<string> vectEmail;
   vector<string> vectEmailFound;
   string line;

  /********** ********** **********
   * user input
   ********** ********** **********/

   int fileChoice;
   string fileName;
   cout
   << "Choose email file\n"
   << "1. email_100.txt\n"
   << "2. email_100000\n"
   << "3. email_500000\n";
   cin >> fileChoice;
   cout << endl;

   if (fileChoice == 1){
    fileName = "email_100.txt";
   } else
   if (fileChoice == 2){
    fileName = "email_100000.txt";
   }else
   if (fileChoice == 3){
    fileName = "email_500000.txt";
   }else{
    cout << "error";
    return 0;
   }



  /********** ********** **********
   * io file
   ********** ********** **********/
   myfile1.open(fileName); //opening the file.
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
   {
       cout << "Unable to open file";
       return 0;
   }
   vectEmail.pop_back();



  /********** ********** **********
   * construct hash table
   ********** ********** **********/


   cout << "HashTable Chaining Method\n\n";
   HT_Chaining htc(vectEmail.size() * 0.9);
   cout << "\n\n\nHashTable Linear Probing Method\n\n";
   HT_LinearProbing htlp(vectEmail.size() * 1.5);


   buildHashTable(ht);

   //Only Display if fileChoice is email_100.txt
   if(fileChoice == 1){
      cout << ht << endl << endl;
      ht2.displayAll();
      cout << endl << endl;
   }


  /********** ********** **********
   * calculate hash table searching
   * && retrieval time
   ********** ********** **********/

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
   int sum_ascii = 0;
   auto searchStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmailFound.size(); i++)
   {
      for (char c : vectEmailFound[i])
      {
         sum_ascii += c;
      };
      cout << "ITEM " << ht.retrieve(sum_ascii) << " At"
           << " Key => " << ht.hashfunction(sum_ascii) << endl;
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

void builHashTable(HT_Chaining ht){

   int sum_ascii;
   auto insetStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmail.size(); i++)
   {
      for (char c : vectEmail[i])
      {
         sum_ascii += c;
      };
      ht.insertItem(sum_ascii, vectEmail[i]);
      sum_ascii = 0; //clear the sum_ascii
   }
   auto insetEnd = chrono::system_clock::now();
   double nanotime_htcInsertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
   double millitime_htcInsertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();
}

void builHashTable(HT_LinearProbing ht){

   int sum_ascii;
   auto insetStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmail.size(); i++)
   {
      for (char c : vectEmail[i])
      {
         sum_ascii += c;
      };
      ht.insertItem(sum_ascii, vectEmail[i]);
      sum_ascii = 0; //clear the sum_ascii
   }
   auto insetEnd = chrono::system_clock::now();
   double nanotime_htcInsertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
   double millitime_htcInsertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();
}
