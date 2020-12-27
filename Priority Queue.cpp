
#include <iostream>
#include <vector>
#include <chrono> // C++11
#include <cstdlib> // This line is required in Code::Blocks 13.12.


using namespace std;

template <typename T>

void printArray (vector<T> A, int n) {
  for (int i = 0; i < n; i++)
    cout << A.at(i) << " ";
  cout << endl;
}

template <typename T>
class PriorityQueue {
  vector<T> A;

  void heapify_enqueue (int index) {   // used in enqueue.
    if (index == 0)                    // if already at root.
      return;

    // parent
    int parent_index = (index-1)/2;
    string temp;
    bool tag = false;

    for(int i = 0; i < A[index].length(); i++){
    if ((A[index][i] - '0') > (A[parent_index][i] - '0'))
        {
            //swap(A[index], A[parent_index]);
            temp = A[index];
            A[index] = A[parent_index];
            A[parent_index] = temp;
        }
    if ((A[index][i] - '0') < (A[parent_index][i] - '0')){
        break;
    }
    }

    //if(A[index].compare(A[parent_index]) > 0 )
    // swap if parent is smaller
    //    swap(A[index], A[parent_index]);
    heapify_enqueue(parent_index);
    // recursion of the function
}

  void heapify_dequeue (int index) {   // used in dequeue.
    int maxValue;                           // max index
    // left child index
    int left = (2*index)+1;

    // right child index
    int right = (2*index)+ 2;

    // compare and find the greatest child
    //make sure the size of index is always smaller than the size of tree
    for(int i = 0; i < A[index].length(); i++){
        if ( left < A.size() && ( (A[left][i] - '0') > (A[index][i] - '0')))
            {
                maxValue = left;
                break;
            }
        else if(right < A.size() && ((A[right][i] - '0') > (A[index][i] - '0')))
            {
                maxValue = right;
                break;
            }
        else {
                maxValue = index;
            }
        }
    /*
    if(left < A.size() && A[left].compare(A[index]) > 0 ){
        max = left;
        cout << "L Value Changed: "<< A[left]<<" Replace " << A[index] << endl;
    }
    else
        max = index;

    if(right < A.size() && A[right] > (A[index])){
        max = right;
        cout << "R Value Changed: "<< A[right]<<" Replace " << A[index] << endl;
    }
    */


    if (maxValue != index) {
      swap (A[index], A[maxValue]);
      heapify_dequeue (maxValue);
    }
  }

 public:
  void enqueue (T element) {
    A.push_back (element);
    heapify_enqueue (A.size()-1);  // start at last element.
  }

  T dequeue() {
    T removed_element = A[0];
    A[0] = A[A.size()-1];          // copy last element to root.
    A.pop_back();                  // remove last element.
    for (int i = 0; i < A.size(); i++)
      cout << A[i] << " ";
    cout << endl;
    heapify_dequeue (0);           // start at root.
    return removed_element;
  }

  int size() {
    return A.size();
  }

  void print() {
    for (int i = 0; i < A.size(); i++)
      cout << A[i] << " ";
    cout << endl;
  }

  void printFirst() {
    cout << A.at(0) << " ";
    cout << endl;
  }
};

//int main ()
void priorityQueue (vector<string> A)
{
  //int A[] = {4, 2, 5, 8, 6, 9, 3, 7};
  //int n = sizeof(A)/sizeof(A[0]);
  vector <double> durationVect;
  double sum_of_durations;
  int n = A.size();
  cout << "Array = ";
  printArray (A, n);

  cout << "\nEnqueue\t: PriorityQueue\n";
  PriorityQueue<string> pq;
  for (int i = 0; i < n; i++) {
    cout << A.at(i) << "\t: ";
    auto start = chrono::system_clock::now();
    pq.enqueue (A[i]);
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    //durationVect.push_back(duration);
    pq.print();
  }
  cout << (n * 0.1);
  cout << "\nDequeue\t: PriorityQueue\n";
  for (int i = 0; i < 1; i++) {
    cout << pq.dequeue() << "\t: ";
    pq.print();
  }

  for(std::vector<double>::iterator it = durationVect.begin(); it != durationVect.end(); ++it)
    sum_of_durations += *it;

  cout << "\n";
  cout << "Total Time for Inserting Email: "<< sum_of_durations;
  cout << "\n";
  cout << "Average Time for Inserting Email: "<< sum_of_durations / n;
  cout << "\n";


}
