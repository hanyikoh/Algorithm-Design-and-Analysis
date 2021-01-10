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
#include "HT_Chaining.h"
#include "HT_LinearProbing.h"

void displayData(string, vector<string>, double, double, double, double);

int main()
{
   fstream myfile1;
   vector<string> vectEmail;
   vector<string> vectEmailFound;
   vector<string> vectEmailNotFound;
   string line;

  /********** ********** **********
   * user input
   ********** ********** **********/

   int fileChoice;
   int findingEmailChoice;
   string fileName;
   string emailFound;
   string emailNotFound;
   cout
   << "Choose email file\n"
   << "1. email_100.txt\n"
   << "2. email_100000\n"
   << "3. email_500000\n";
   cin >> fileChoice;
   cout << endl;

   cout
   << "\n\nChoose email file\n"
   << "1. Email Found\n"
   << "2. Email Not Found\n";
   cin >> findingEmailChoice;
   cout << endl;


   if (fileChoice == 1){
    fileName = "email_100.txt";
       if(findingEmailChoice == 1){
           emailFound = "Email Found_100.txt";
       }else
       if(findingEmailChoice == 2){
           emailFound = "Email Not Found_100.txt";
       }else{
           cout << "ERROR";
           return 0;
       }
   } else
   if (fileChoice == 2){
    fileName = "email_100000.txt";
       if(findingEmailChoice == 1){
           emailFound = "Email Found_100000.txt";
       }else
       if(findingEmailChoice == 2){
           emailFound = "Email Not Found_100000.txt";
       }else{
           cout << "ERROR";
           return 0;
       }
   }else
   if (fileChoice == 3){
    fileName = "email_500000.txt";
       if(findingEmailChoice == 1){
           emailFound = "Email Found_500000.txt";
       }else
       if(findingEmailChoice == 2){
           emailFound = "Email Not Found_500000.txt";
       }else{
           cout << "ERROR";
           return 0;
       }
   }else{
    cout << "ERROR";
    return 0;
   }

  /********** ********** **********
   * io file
   ********** ********** **********/

   /*
    * Email Generator File
    */

   cout << "Handling iostream...\n";
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
      cout << "Unable to open file found\nERROR\n";
      return 0;
   }
   vectEmail.pop_back();

   /*
    * Email Found File / Email Not Found File
    */

   myfile1.open(emailFound);
   if (myfile1.is_open()) //if the file is open
   {
      while (!myfile1.eof()) //while the end of file is NOT reached
      {
         getline(myfile1, line);         //get one line from the file
         vectEmailFound.push_back(line); //output loop statement
      }
      myfile1.close(); //closing the file
   }
   else {
      cout << "Unable to open file found\nERROR\n";
      return 0;
   }

   vectEmailFound.pop_back();
   cout << "All iostream handling Successful\n\n";


  /********** ********** **********
   * construct hash table
   ********** ********** **********/


   cout << "Inserting Hash Table Chaining...\n";

   const float HTCDATASIZE = 0.9;
   const float HTLBDATASIZE = 1.5;

   // Declaration
   HT_Chaining htc(vectEmail.size() * HTCDATASIZE);
   HT_LinearProbing htlp(vectEmail.size() * HTLBDATASIZE);


   // Construct gash table using chaining method and record the time
   int sum_ascii;
   auto insetStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmail.size(); i++){
      for (char c : vectEmail[i]){
         sum_ascii += c;
      };
      htc.insertItem(sum_ascii, vectEmail[i]);
      sum_ascii = 0; //clear the sum_ascii
   }
   auto insetEnd = chrono::system_clock::now();
   double nanotime_htcInsertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
   double millitime_htcInsertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();

   cout << "Hash Table Chaining Successful\n\n";

   cout << "Inserting Hash Table Linear Probing...\n";

   // Construct gash table using linear probing method and record the time
   sum_ascii;
   insetStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmail.size(); i++)
   {
      for (char c : vectEmail[i])
      {
         sum_ascii += c;
      };
      htlp.insertItem(sum_ascii, vectEmail[i]);
      sum_ascii = 0; //clear the sum_ascii
   }
   insetEnd = chrono::system_clock::now();
   double nanotime_htlpInsertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
   double millitime_htlpInsertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();

   cout << "Hash Table Linear Probing Successful\n\n";

   //Display fileChoice that is email_100.txt
   /* */
   if(fileChoice == 1){
      cout << "HashTable Chaining Method\n\n";
      cout << htc << endl << endl;
      cout << "HashTable Linear Probing Method\n\n";
      htlp.displayAll();
      cout << endl << endl;
   }/* */


  /********** ********** **********
   * calculate hash table searching
   * && retrieval time
   ********** ********** **********/


   // Search Chaining Method
   cout << "\nSearching hash table Chaining\n\n";
   sum_ascii = 0;
   auto searchStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmailFound.size(); i++){
      for (char c : vectEmailFound[i]){
         sum_ascii += c;
      };
      if (htc.searchItem(sum_ascii, vectEmailFound[i])){
        cout << "ITEM " << vectEmailFound[i] << " found at Key => " << htc.hashfunction(sum_ascii) << endl;
      }
      else
        cout << "ITEM " << vectEmailFound[i] << " Not found\n";
      sum_ascii = 0;
   }
   auto searchEnd = chrono::system_clock::now();
   double nanotime_htcSearchTaken = chrono::duration_cast<chrono::nanoseconds>(searchEnd - searchStart).count();
   double millitime_htcSearchTaken = chrono::duration_cast<chrono::milliseconds>(searchEnd - searchStart).count();


   // Search Linear Probing
   cout << "\nSearching hash table Chaining\n\n";
   sum_ascii = 0;
   searchStart = chrono::system_clock::now();
   for (int i = 0; i < vectEmailFound.size(); i++){
      for (char c : vectEmailFound[i]){
         sum_ascii += c;
      };
      cout << "ITEM " << htlp.searchItem(sum_ascii, vectEmailFound[i]) << "\n";
      sum_ascii = 0;
   }
   searchEnd = chrono::system_clock::now();
   double nanotime_htlpSearchTaken = chrono::duration_cast<chrono::nanoseconds>(searchEnd - searchStart).count();
   double millitime_htlpSearchTaken = chrono::duration_cast<chrono::milliseconds>(searchEnd - searchStart).count();



  /********** ********** **********
   * Display All Data
   ********** ********** **********/


   displayData("Chaining Method", vectEmail,
               nanotime_htcInsertTaken, millitime_htcInsertTaken,
               nanotime_htcSearchTaken, millitime_htcSearchTaken);

   displayData("Linear Probing", vectEmail,
               nanotime_htlpInsertTaken, millitime_htlpInsertTaken,
               nanotime_htlpSearchTaken, millitime_htlpSearchTaken);

   cout << "\n\nProgram Ends Here\n\n";

}

void displayData(string hashtableMethod, vector<string> vectEmail,
                 double nanotime_insertTaken, double millitime_insertTaken,
                 double nanotime_searchTaken, double millitime_searchTaken){

   cout << "\n" << hashtableMethod << "\n\n";
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
   cout << "\n\n\n";

}


