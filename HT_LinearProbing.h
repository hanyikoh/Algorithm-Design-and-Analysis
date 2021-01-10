#ifndef HT_LINEARPROBING_H
#define HT_LINEARPROBING_H

#include <cctype>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Email{

public:
   int rollno;
   string name;
   Email(){};

   int getRollno(){
       return rollno;
   }

   string getName(){
       return name;
   }
};


// Hash Table Linear Probing
class HT_LinearProbing{
   Email **arr;  //Pointer to pointer to Email variable
   int size;    //Hash Table Size
   int count;   //Count number of insertion

public:
   HT_LinearProbing(int s){
      count = 0;
      size = s;
      arr = new Email *[size];

      for (int i = 0; i < size; i++)
         arr[i] = nullptr;
   }

   int getSize(){
        return size;
   }

   //Hash function
   int hashfunction(int n){
      return n % size;
   };

   //Insertion
   void insertItem(int key, string value){
      if (count == size){
         cout << " Hash full";
         return;
      }

      int hashIndex = hashfunction(key);

      while (arr[hashIndex] != nullptr){
         hashIndex = (hashIndex + 1) % size;
      }
      arr[hashIndex] = new Email();
      arr[hashIndex]->rollno = key;
      arr[hashIndex]->name = value;
      count++;
   };

   //Retrieval
   string retrieve (int key)
   {
      if (count == 0){
         return "Empty";
      }

      int hashIndex = hashfunction(key);
      int temp = hashIndex; //store original hash key inside temp

      while (true){
         if (arr[hashIndex] == nullptr){
            hashIndex = (hashIndex + 1) % size;
         }
         else if (arr[hashIndex]->rollno != key){
            hashIndex = (hashIndex + 1) % size;
         }
         else
            break;

         if (hashIndex == temp){ //Not found after going through the entire table
            temp = -1;
            break;
         }
      }

      if (temp == -1){
         return "Not Found";
      }
      else{
         return arr[hashIndex]->name;
      }
   }

   //Delete
   void deleteItem(int key){
      if (count == 0){
         cout << "Hash is empty";
      }

      int hashIndex = hashfunction(key);
      int temp = hashIndex;
      while (true){
         if (arr[hashIndex] == nullptr){
            hashIndex = (hashIndex + 1) % size;
         }

         else if (arr[hashIndex]->rollno != key){
            hashIndex = (hashIndex + 1) % size;
         }
         else
            break;

         if (hashIndex == temp){
            temp = -1;
            break;
         }
      }

      if (temp == -1){
         cout << "Not Found";
      }
      else{
         delete arr[hashIndex];
         arr[hashIndex] = nullptr;
         count--;
      }
   }

   /*
   friend ostream& operator<< (ostream& os, HT_LinearProbing & ht) {
        for (int i = 0; i < ht.getSize(); i++)
        os << "HASH_TABLE[" << i << "]: key => " << arr[i]->rollno << " value => " << arr[i]->name << endl;
        return os;
    }*/


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

   /*
    ~MyHashTable(){
       for(int i = 0; i < size; i++){
          if(arr[i] != nullptr){
             cout <<"deleting key = > " << arr[i]->rollno << " value = >" << arr[i]->name << endl;
             delete arr[i];
             arr[i] = nullptr;
          }
       }
    }
   */
};

#endif // HT_LINEARPROBING_H
