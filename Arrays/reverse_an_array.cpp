// Reverse an array
// Two Pointer Approach

#include<iostream>
using namespace std;

void reverse_array(int arr[], int size){
    int start =0;    // 1st pointer
    int end = size-1; // 2nd pointer

    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
      cout<<arr[i]<<" ,";
    cout<<endl;
}

int main (){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverse_array(arr, size); // pass by reference

    printArray(arr, size);
}