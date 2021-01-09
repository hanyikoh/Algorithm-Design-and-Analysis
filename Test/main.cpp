#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

template <typename T>
class MaxPriority
{
    vector <T> result;

    void HeapifyEnqueue(int index) // make sure all parent is greater than its child
    {
        if(index == 0)  //if the vector only has one element, return directly
            return;

        int parent = (index-1)/2;  // find parent value
        if(result[index] > result[parent])
        {
            swap(result[index],result[parent]);  //if greater than its parent, swap
            HeapifyEnqueue(parent);  // make sure after swapping, the parent is greater, if not swap again
        }

    }


   void HeapifyDequeue(int index) //make sure after delete a root, the new root is the greatest.
    {
        int max;
        int left = (2*index)+1;  //find the index of left node
        int right = (2*index)+2;  // find the index of right node
        if(right < result.size())  // if true mean left and right node is not empty
        {
            if(result[left] > result[right])
            {
                max = left;
            }
            else
            {
                max = right;
            }

        if(result[index] > result[max])
            {
                max = index;
            }
        }
        else if(left < result.size())   // if true mean only left node not empty
        {
            if(result[left] > result[index])
            {
                max = left;
            }
            else
            {

                max = index;
            }

        }
        else // if left and right node are empty, the root will confirm is the greatest
        {
            max = index;
        }

        if(max != index) // if the root is not the greatest, swap again
        {
            swap(result[max],result[index]);
            HeapifyDequeue(max);
        }

    }

 public:
    void Enqueue(T element) // insert element to result vector
    {
        result.push_back(element);
        HeapifyEnqueue(result.size()-1);
    }

    T Dequeue()
    {
        T removed_element = result[0];
        result[0] = result[result.size()-1];
        result.pop_back();
        HeapifyDequeue(0);
        return removed_element;
    }

    int size()
    {
        return result.size();

    }

    void print()
    {
        for(int i=0; i< 10; i++)
            cout<<result[i] <<endl;
        cout<<endl;
    }

};


int main()
{
    string myText;
    ifstream MyReadFile("set_C.txt");
    MaxPriority<string> rs;
    auto start = high_resolution_clock::now();
    while(getline(MyReadFile, myText))
    {
       rs.Enqueue(myText);
    }
    auto stop = high_resolution_clock::now();
    auto execute_time = duration_cast<nanoseconds>(stop - start);
    cout<<"---------Complete!---------"<<endl;
    cout<<endl;
    cout<<"Total Enqueue Time is: " << execute_time.count() << " nanoseconds" <<endl;
    cout<<"Remaining Items: "<<rs.size() <<endl;


    int number;
    number = rs.size()*(0.1);
    auto start2 = high_resolution_clock::now();
    for(int i=0; i<number; i++)
    {
        rs.Dequeue();
    }
    auto stop2 = high_resolution_clock::now();
    auto execute_time2 = duration_cast<nanoseconds>(stop2 - start2);
    cout<<endl;
    cout<<"Total Dequeue Time is: " <<execute_time2.count()<< " nanoseconds" <<endl;
    cout<<"Remaining Items: "<<rs.size() <<endl;
    cout<<endl;
    cout<<"---------------------------"<<endl;

}


