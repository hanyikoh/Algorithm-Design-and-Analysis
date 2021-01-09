#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printArray (T A[], int n) {
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
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
    if(A[index] > A[parent_index])
        swap(A[index], A[parent_index]);
    // swap if parent is smaller
    heapify_enqueue(parent_index);
    // recursion of the function


  }

  void heapify_dequeue (int index) {   // used in dequeue.
    int max;                           // max index
    // left child index
    int left = 2*index+1;

    // right child index
    int right = 2*index+ 2;

    // compare and find the greatest child
    //make sure the size of index is always smaller than the size of tree
    if(left < A.size() && A[left] > A[index])
        max = left;
    else
        max = index;

    if(right < A.size() && A[left] > A[index])
        max = right;


    if (max != index) {
      swap (A[index], A[max]);
      heapify_dequeue (max);
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
};

int main () {
  string A[] = {
    "yaxte.KFcj@AmSfWn.net" ,
    "wRq8k.5kCx@aLCZdk.my" ,
    "RK4xy.X3xr@UOSEBe.net",
    "uQ3RK.WKbM@rfXsbV.net",
    "WTY0x.ffiW@bzbjWy.org",
    "bIONR.Jd8K@xIJMGe.my",
    "uUJzl.eYhw@RiPpeE.my",
    "qDzt7.amih@aChDrg.net",
    "sMw9w.tfrX@BLGqck.org"};
  int n = sizeof(A)/sizeof(A[0]);
  cout << "Array = ";
  printArray (A, n);

  cout << "\nEnqueue\t: PriorityQueue\n";
  PriorityQueue<string> pq;
  for (int i = 0; i < n; i++) {
    cout << A[i] << "\t: ";
    pq.enqueue (A[i]);
    pq.print();
  }

  cout << "\nDequeue\t: PriorityQueue\n";
  for (int i = 0; i < n; i++) {
    cout << pq.dequeue() << "\t: ";
    pq.print();
  }
}
