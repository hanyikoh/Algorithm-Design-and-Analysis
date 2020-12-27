#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<string> HeapifyEnqueue(vector<string> arr, int index) // make sure all parent is greater than its child
{
    if(index == 0)  //if the vector only has one element, return directly
        return arr;

    int parent = (index-1)/2;  // find parent value
    if(arr[index] > arr[parent])
    {
        swap(arr[index],arr[parent]);  //if greater than its parent, swap
        arr = HeapifyEnqueue(arr,parent);  // make sure after swapping, the parent is greater, if not swap again
    }
    return arr;

}

vector<string> Enqueue(string input, vector<string> arr)  // insert element to result vector
{
    arr.push_back(input);
    int index = arr.size()-1;  //get the index of that element been inserted
    arr = HeapifyEnqueue(arr, index);
    return arr;
}


vector<string> HeapifyDequeue(int index, vector<string> arr) //make sure after delete a root, the new root is the greatest.
{
    int max=0;
    int left = (2*index)+1;  //find the index of left node
    int right = (2*index)+2;  // find the index of right node
    if(right < arr.size())  // if true mean left and right node is not empty
    {
        if(arr[left] > arr[right])
        {
            max = left;
        }
        else
        {
            max = right;
        }

        if(arr[index] > arr[max])
        {
            max = index;
        }
    }
    else if(left < arr.size())   // if true mean only left node not empty
    {
        if(arr[left] > arr[index])
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
        swap(arr[max],arr[index]);
        arr = HeapifyDequeue(max,arr);
    }
    return arr;
}



vector<string> Dequeue(vector<string> arr) //remove the root
{
  string remove_element =  arr[0];
  arr[0] = arr[arr.size()-1]; // when root been removed, the last element become the root
  arr.pop_back();
  arr = HeapifyDequeue(0,arr);
  return arr;
}



int main()
{

  vector<string> input = {"z","c","d","e","f"};   //input
  vector<string> result;  // final result
  for(int i=0; i<input.size(); i=i+1)  // loop to insert  every element to result vector and rearrange according max priority
  {

     result = Enqueue(input[i],result);
  }

    for(int i=0; i<3; i=i+1)  // loop to remove
    {

        result = Dequeue(result);
    }

       for(int i=0; i<result.size(); i=i+1) // print the final result
    {
      cout << result[i] + "\n";

    }


    return 0;
}
