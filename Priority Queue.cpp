
#include <iostream>
#include <vector>
#include <chrono>  // C++11
#include <cstdlib> // This line is required in Code::Blocks 13.12.
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
class PriorityQueue
{
  vector<T> A;
  bool emailFound = false;

  void heapify_enqueue(int index)
  {                 // used in enqueue.
    if (index == 0) // if already at root.
      return;

    // parent
    int parent_index = (index - 1) / 2;

    if (A[index].compare(A[parent_index]) > 0)
      swap(A[index], A[parent_index]);
    heapify_enqueue(parent_index);
  }

  void heapify_dequeue(int index)
  {               // used in dequeue.
    int maxValue; // max index
    // left child index
    int left = (2 * index) + 1;

    // right child index
    int right = (2 * index) + 2;

    if (left < A.size() && A[left].compare(A[index]) > 0)
      maxValue = left;
    else
      maxValue = index;

    if (right < A.size() && A[right].compare(A[index]) > 0)
      maxValue = right;

    if (maxValue != index)
    {
      swap(A[index], A[maxValue]);
      heapify_dequeue(maxValue);
    }
  }

public:
  string randomEmail()
  {
    return A[rand() % A.size()];
  }

  void enqueue(T element)
  {
    A.push_back(element);
    heapify_enqueue(A.size() - 1); // start at last element.
  }

  T dequeue()
  {
    T removed_element = A[0];
    A[0] = A[A.size() - 1];
    A.pop_back();
    heapify_dequeue(0);
    return removed_element;
  }

  int size()
  {
    return A.size();
  }

  // void print()
  // {
  //   // for (int i = 0; i < 10; i++)
  //   //   cout << A[i] << " " << endl;
  //   // cout << endl;
  //   cout << "HEI" << endl;
  //   outfile.open("TESTXIA.txt");
  //   for (int i = 0; i < A.size(); i++)
  //     outfile << A[i] << endl;
  //   outfile.close();
  // }

  void search(string data)
  {
    searchData = data;
    for (int i = 0; i < A.size(); i++)
    {
      if (A[i] == searchData)
      {
        cout << searchData << " FOUND AT INDEX " + to_string(i) << endl;
        return;
      }
    }
    cout << "EMAIL: " << searchData << " CANNOT NOT BE FOUND" << endl;
    return;
  }
};

//int main ()
void priorityQueue(vector<string> A)
{
  vector<double> durationVect;
  int n = A.size();
  PriorityQueue<string> pq;
  // chrono::duration<double> duration;
  cout << "---------Enqueuing the emails into Heap---------" << endl
       << endl;
  auto insetStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++)
  {
    // cout << A.at(i) << "\t: ";
    pq.enqueue(A[i]);
    // duration = duration + ( end - start );
    //durationVect.push_back(duration);
  }
  auto insetEnd = chrono::high_resolution_clock::now();
  double nanotime_insertTaken = chrono::duration_cast<chrono::nanoseconds>(insetEnd - insetStart).count();
  double millitime_insertTaken = chrono::duration_cast<chrono::milliseconds>(insetEnd - insetStart).count();

  cout << "\nEnqueue done belows are the time spent details: \n";
  cout << "Total Nanoseconds for Inserting " << n << " Emails: " << nanotime_insertTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Inserting " << n << " Email: " << nanotime_insertTaken / n << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Inserting " << n << " Email: " << millitime_insertTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Inserting " << n << " Email: " << millitime_insertTaken / n << " milliseconds";
  cout << "\n\n";

  vector<string> dequequedList;
  auto dequeueStart = chrono::high_resolution_clock::now();
  cout << "---------Dequeuing the 10% Email from Heap---------" << endl
       << endl;
  for (int i = 0; i < n * 0.1; i++)
  {
    dequequedList.push_back(pq.dequeue());
    // pq.dequeue();
  }
  auto dequeueEnd = chrono::high_resolution_clock::now();
  double nanotime_dequeueTaken = chrono::duration_cast<chrono::nanoseconds>(dequeueEnd - dequeueStart).count();
  double millitime_dequeueTaken = chrono::duration_cast<chrono::milliseconds>(dequeueEnd - dequeueStart).count();
  cout << "First 10 Dequequed Elements " << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << dequequedList[i] << endl;
    // pq.dequeue();
  }
  cout << "\nDequeue done belows are the time spent details: \n";
  cout << "Total Nanoseconds for Dequeue " << n * 0.1 << " Email: " << nanotime_dequeueTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Dequeue " << n * 0.1<< " Email: " << nanotime_dequeueTaken / n << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Dequeue " << n * 0.1<< " Email: " << millitime_dequeueTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Dequeue " << n * 0.1<< " Email: " << millitime_dequeueTaken / n << " milliseconds";
  cout << "\n";
  //nanotime_insertTaken *= 1e-9;

  // for (std::vector<double>::iterator it = durationVect.begin(); it != durationVect.end(); ++it)
  //   sum_of_durations += *it;
  ifstream searchFile;
  string line;
  vector<string> searchEmailVect;
  vector<string> searchNoEmailVect;

  for (int i = 0; i < 10; i++)
  {
    searchEmailVect.push_back(pq.randomEmail());
  }

  searchFile.open("Email Not Found_" + to_string(n) + ".txt");
  if (searchFile.is_open()) //if the file is open
  {
    while (!searchFile.eof()) //while the end of file is NOT reached
    {
      getline(searchFile, line);         //get one line from the file
      searchNoEmailVect.push_back(line); //output loop statement
    }
    searchFile.close(); //closing the file
  }

  cout << "---------Searching for 10 Emails that can be found---------" << endl
       << endl;
  auto searchFoundStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; i++)
  {
    pq.search(searchEmailVect[i]);
  }
  auto searchFoundEnd = chrono::high_resolution_clock::now();
  double nanotime_searchFoundTaken = chrono::duration_cast<chrono::nanoseconds>(searchFoundEnd - searchFoundStart).count();
  double millitime_searchFoundTaken = chrono::duration_cast<chrono::milliseconds>(searchFoundEnd - searchFoundStart).count();
  cout << "\nSearching done belows are the time spent details: \n";
  cout << "Total Nanoseconds for Searching " << n << " Email: " << nanotime_searchFoundTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Searching " << n << " Email: " << nanotime_searchFoundTaken / 10 << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Searching " << n << " Email: " << millitime_searchFoundTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Searching " << n << " Email: " << millitime_searchFoundTaken / 10 << " milliseconds";
  cout << "\n";
  cout << "\n";

  cout << "--------Searching for 10 Emails that can't be found--------" << endl
       << endl;
  auto searchStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; i++)
  {
    pq.search(searchNoEmailVect[i]);
  }
  auto searchEnd = chrono::high_resolution_clock::now();
  double nanotime_searchTaken = chrono::duration_cast<chrono::nanoseconds>(searchEnd - searchStart).count();
  double millitime_searchTaken = chrono::duration_cast<chrono::milliseconds>(searchEnd - searchStart).count();
  cout << "\nSearching done belows are the time spent details: \n";
  cout << "Total Nanoseconds for Searching " << n << " Email: " << nanotime_searchTaken << " nanoseconds";
  cout << "\n";
  cout << "Average Nanoseconds for Searching " << n << " Email: " << nanotime_searchTaken / 10 << " nanoseconds";
  cout << "\n";
  cout << "Total Milliseconds for Searching " << n << " Email: " << millitime_searchTaken << " milliseconds";
  cout << "\n";
  cout << "Average Milliseconds for Searching " << n << " Email: " << millitime_searchTaken / 10 << " milliseconds";
  cout << "\n";
  cout << "\n";

  cout << endl;
  // pq.print();
}
