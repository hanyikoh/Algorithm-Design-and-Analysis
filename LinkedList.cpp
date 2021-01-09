// LinkedList.cpp -- class for a linked list as a data structure

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
using namespace std;

//To create node
template <typename T>
struct Node {
  T info;
  Node<T> *next; //Store address of next node
};

template <typename T>
class LinkedList {

  Node<T> *start; //Store address of very first node

 public:
  //Constructor
  LinkedList() { start = NULL; }
  //Destructor
  ~LinkedList() { makeEmpty(); }

  // inserts at the beginning of the linked list
  void insertFront (T & element ) {
    Node<T> *newNode = new Node<T>; //init a newNode
    newNode->info = element;        //update element info in new Node
    newNode->next = start;          //new element point to previous element's address
    start = newNode;                //start now store new element's address
  }

  // returns true if element is found;
  // returns false if element is not found;
  bool find (T & target) {
    bool found = false;
    Node<T> *ptr = start; //search from the start
    while (ptr != NULL && !found) {
      if (ptr->info == target) { //To access members of a structure through a pointer, use the ->
        found = true; //element is found
      }
      else
        ptr = ptr->next; //element not found
    }
    return found;
  }

  // Check whether the linkedlist is empty
  // If start == null, is true, means it is empty
  bool isEmpty() { return start == NULL; }

  // Delete
  void makeEmpty() {
    while (start != NULL) {
      Node<T> *ptr  = start;
      start = start->next;
      delete ptr;
    }
  }

  //
  friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
    Node<T> *ptr = list.start;
    while (ptr != NULL) {
      os << ptr->info << " | ";
      ptr = ptr->next;
    }
    return os;
  }
};
#endif
