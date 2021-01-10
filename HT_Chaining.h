#ifndef HT_CHAINING_H
#define HT_CHAINING_H

#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include "LinkedList.h"

using namespace std;

class HT_Chaining {

  vector< LinkedList<string> > table; //vector of LinkedList
  int count;

 public:

     //Constructor
     HT_Chaining (int size) {
        table.resize (size); // resize vector to support size elements.
     }
    //Destructor
    ~HT_Chaining() {
        for (int i = 0; i < table.size(); i++)
        table[i].makeEmpty();
    }

    int hashfunction (int hashitem) { // hash function
     return hashitem % table.size();
    }

    int size() {
        return table.size();
    }

    void insertItem (int key, string newItem) {
        int location = hashfunction(key);
            table[location].insertFront(newItem);
    }

    bool searchItem (int key, string & targetItem) {
        int location = hashfunction(key);
        if(!table[location].find(targetItem))
            return false;
        return true;
    }

    friend ostream& operator<< (ostream& os, HT_Chaining & ht) {
        for (int i = 0; i < ht.size(); i++)
        os << "HASH_TABLE[" << i << "] = " << ht.table[i] << endl;
        return os;
    }
};

#endif // HT_CHAINING_H
