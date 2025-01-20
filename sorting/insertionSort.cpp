/*
    Insertion Sort : insertion sort method sorts a list of elements by inserting each successive element in the previously sorted sublist. Such insertion of elements requires the other elements to be shuffeled as required.

*/

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int prev, curr;
    for (int i=1; i<n; i++){
        prev = i-1;
        curr = arr[i];

        while(prev>=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    int arr[] = {5,3,7,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
}

/*
    Algorithm:
    Start from the second element (index 1).
    Compare it with the element before it.
    If the current element is smaller than the previous element, shift the previous element one position to the right.
    Continue shifting the elements to the right until the current element is in the correct position.
    Repeat this process for all the elements in the array until the array is sorted.
*/