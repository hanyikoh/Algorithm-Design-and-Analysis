
#include <iostream>
#include <vector>
#include <chrono>  // C++11
#include <cstdlib> // This line is required in Code::Blocks 13.12.
#include <ctime>

using namespace std;

template <typename T>

void printArray(vector<T> A, int n)
{
  for (int i = 0; i < n; i++)
    cout << A.at(i) << " ";
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
    // string temp;
    // bool tag = false;

    // for (int i = 0; i < A[index].length(); i++)
    // {
    //   if ((A[index][i] - '0') > (A[parent_index][i] - '0'))
    //   {
    //     //swap(A[index], A[parent_index]);
    //     temp = A[index];
    //     A[index] = A[parent_index];
    //     A[parent_index] = temp;
    //   }
    //   if ((A[index][i] - '0') < (A[parent_index][i] - '0'))
    //   {
    //     break;
    //   }
    // }

    if (A[index] > A[parent_index])
      swap(A[index], A[parent_index]);
    // swap if parent is smaller
    heapify_enqueue(parent_index);
    //if(A[index].compare(A[parent_index]) > 0 )
    // swap if parent is smaller
    //    swap(A[index], A[parent_index]);
    // heapify_enqueue(parent_index);
    // recursion of the function
  }

  void heapify_dequeue(int index)
  {               // used in dequeue.
    int maxValue; // max index
    // left child index
    int left = (2 * index) + 1;

    // right child index
    int right = (2 * index) + 2;

    // compare and find the greatest child
    //make sure the size of index is always smaller than the size of tree
    if (left < A.size() && A[left] > A[index])
      maxValue = left;
    else
      maxValue = index;

    if (right < A.size() && A[left] > A[index])
      maxValue = right;

    if (maxValue != index)
    {
      swap(A[index], A[maxValue]);
      heapify_dequeue(maxValue);
    }
  }

public:
  void enqueue(T element)
  {
    A.push_back(element);
    heapify_enqueue(A.size() - 1); // start at last element.
  }

  // T dequeue()
  // {
  //   T removed_element = A[0];
  //   A[0] = A[A.size() - 1]; // copy last element to root.
  //   A.pop_back();           // remove last element.
  //   for (int i = 0; i < A.size(); i++)
  //     cout << A[i] << " ";
  //   cout << endl;
  //   heapify_dequeue(0); // start at root.
  //   return removed_element;
  // }

  // void dequeue()
  // {
  //   T removed_element = A[0];
  //   A[0] = A[A.size() - 1]; // copy last element to root.
  //   //swap(A[0], A[A.size() - 1]);
  //   A.pop_back();       // remove last element.
  //   heapify_dequeue(0); // start at root.
  //   //return removed_element;
  // }

  T dequeue()
  {
    T removed_element = A[0];
    A[0] = A[A.size() - 1]; // copy last element to root.
    //swap(A[0], A[A.size() - 1]);
    A.pop_back();       // remove last element.
    heapify_dequeue(0); // start at root.
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
      cout << A[i] << " " << endl;
    cout << endl;
  }
};

//int main ()
void priorityQueue(vector<string> A)
{
  vector<double> durationVect;
  double sum_of_durations;
  int n = A.size();
  PriorityQueue<string> pq;
  // chrono::duration<double> duration;
  auto insetStart = chrono::system_clock::now();
  for (int i = 0; i < n; i++)
  {
    // cout << A.at(i) << "\t: ";
    pq.enqueue(A[i]);
    // duration = duration + ( end - start );
    //durationVect.push_back(duration);
  }
  auto insetEnd = chrono::system_clock::now();
  double nanotime_insertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
  double millitime_insertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();

  auto dequeueStart = chrono::system_clock::now();
  vector<string> dequequedList;

  for (int i = 0; i < n * 0.1; i++)
  {
    dequequedList.push_back(pq.dequeue());
    // pq.dequeue();
  }
  cout << "First 10 Dequequed Elements " << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << dequequedList[i] << endl;
    // pq.dequeue();
  }

  auto dequeueEnd = chrono::system_clock::now();
  double nanotime_dequeueTaken = chrono::duration_cast<chrono::nanoseconds>(dequeueEnd - dequeueStart).count();
  double millitime_dequeueTaken = chrono::duration_cast<chrono::milliseconds>(dequeueEnd - dequeueStart).count();
  //nanotime_insertTaken *= 1e-9;

  // for (std::vector<double>::iterator it = durationVect.begin(); it != durationVect.end(); ++it)
  //   sum_of_durations += *it;

  cout << "\n";
  cout << "Total Nanoseconds for Inserting " << n << " Emails: " << nanotime_insertTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Inserting " << n << " Email: " << nanotime_insertTaken / n << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Inserting " << n << " Email: " << millitime_insertTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Inserting " << n << " Email: " << millitime_insertTaken / n << " milliseconds";
  cout << "\n";

  cout << "\n";
  cout << "Total Nanoseconds for Dequeue " << n << " Email: " << nanotime_dequeueTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Dequeue " << n << " Email: " << nanotime_dequeueTaken / n << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Dequeue " << n << " Email: " << millitime_dequeueTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Dequeue " << n << " Email: " << millitime_dequeueTaken / n << " milliseconds";
  cout << "\n";

  cout << endl;
  // pq.print();
}
