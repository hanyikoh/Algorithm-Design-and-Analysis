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

using namespace std;

template <typename T>
void printArray(T A[], int n)
{
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  cout << endl;
}

template <typename T>
class PriorityQueue
{
  vector<T> A;

  void heapify_enqueue(int index)
  {                 // used in enqueue.
    if (index == 0) // if already at root.
      return;

    // parent
    int parent_index = (index - 1) / 2;
    if (A[index] > A[parent_index])
      swap(A[index], A[parent_index]);
    // swap if parent is smaller
    heapify_enqueue(parent_index);
    // recursion of the function
  }

  void heapify_dequeue(int index)
  {          // used in dequeue.
    int max; // max index
    // left child index
    int left = 2 * index + 1;

    // right child index
    int right = 2 * index + 2;

    // compare and find the greatest child
    //make sure the size of index is always smaller than the size of tree
    if (left < A.size() && A[left] > A[index])
      max = left;
    else
      max = index;

    if (right < A.size() && A[left] > A[index])
      max = right;

    if (max != index)
    {
      swap(A[index], A[max]);
      heapify_dequeue(max);
    }
  }

public:
  void enqueue(T element)
  {
    A.push_back(element);
    heapify_enqueue(A.size() - 1); // start at last element.
  }

  T dequeue()
  {
    T removed_element = A[0];
    A[0] = A[A.size() - 1]; // copy last element to root.
    A.pop_back();           // remove last element.
    heapify_dequeue(0);     // start at root.
    // cout << endl
    //      << "FIRST :" << A[0] << endl;
    return removed_element;
  }

  int size()
  {
    return A.size();
  }

  void print()
  {
    for (int i = 0; i < A.size(); i++)
      cout << A[i] << " ";
    cout << endl;
  }
};

int main()
{
  string A[100];

  string line;
  ifstream myfile1("email_10.txt"); //opening the file.
  if (myfile1.is_open())            //if the file is open
  {
    int i = 0;
    while (!myfile1.eof()) //while the end of file is NOT reached
    {
      getline(myfile1, line); //get one line from the file
      A[i] = line;            //output loop statement
      i++;
    }
    myfile1.close(); //closing the file
  }
  else
    cout << "Unable to open file";

  int n = sizeof(A) / sizeof(A[0]);

  PriorityQueue<string> pq;
  for (int i = 0; i < n; i++)
  {
    pq.enqueue(A[i]);
  }

  cout << "\nDequeue\t: PriorityQueue\n";
  for (int i = 0; i < n; i++)
  {
    cout << pq.dequeue() << "\t: ";
  }
}
