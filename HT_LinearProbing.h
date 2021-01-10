#ifndef HT_LINEARPROBING_H
#define HT_LINEARPROBING_H

#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Hash Table Linear Probing
class HT_LinearProbing{
   vector<string>table;
   int count;   //Count number of insertion

public:
   HT_LinearProbing(int s){
      count = 0;
      table.resize(s); // resize vector to support size elements.
      fill(table.begin(), table.end(), "-1");
   }

   int getSize(){
        return table.size();
   }

   int getCount(){
        return count;
   }

   //Hash function
   int hashfunction(int n){
      return n % table.size();
   };

   int hashfunction(string item){

      int sum_ascii = item[0] * item[1] * item[2] * item[3] * item[4];
      /*
      for (char c : item)
      {
         sum_ascii += c;
      };/* */
      //cout << sum_ascii << endl;
      return sum_ascii % table.size();
   };

   //Insertion
   void insertItem(string item){

      count++;

      int hashIndex = hashfunction(item);
      while (table[hashIndex] != "-1"){
         hashIndex = (hashIndex + 1) % table.size();
         count++;
      }
      table[hashIndex] = item;

   };

   //Retrieval
   string searchItem (int key, string item){
      if (count == 0){
         return "Empty";
      }

      int hashIndex = hashfunction(key);
      int temp = hashIndex; //store original hash key inside temp

      while (true){
         if (table[hashIndex] == ""){
            hashIndex = (hashIndex + 1) % table.size();
         }
         else if (table[hashIndex] != item){
            hashIndex = (hashIndex + 1) % table.size();
         } else
            break;

         if (hashIndex == temp){ //Not found after going through the entire table
            temp = -1;
            break;
         }
      }

      if (temp != -1 && (table[hashIndex] == item)){
         return item + " found at Key " + to_string(hashIndex);
      }
      else{
         return item + " not found";

      }
   }

   void displayAll(){
      for (int i = 0; i < table.size(); i++){
         if (table[i] != "-1")
            cout << "HASH_TABLE[" << i << "]: value => " << table[i] << endl;
      }
   }

/*
    ~MyHashTable(){
       for(int i = 0; i < size; i++){
          if(arr[i] != nullptr){
             delete arr[i];
             arr[i] = nullptr;
          }
       }
    }
*/

};

#endif // HT_LINEARPROBING_H
