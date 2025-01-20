/* Bubble Sort :
   It focuses on bringing the largest element to the end of list with successive pass.
   Unlike selection sort, it does not perform a search to identify the largest element.
   It repeatedly compares two consecutive elements and moves the largest amongst them to the right.
   This process is repeated for all pairs of elements until the current iteration moves the largest element to the end of the list. 
*/

#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){

    for (int i=0; i<n; i++){
        bool isswap = false;

        for(int j=0;j<n-i-1; j++){

            if (arr[j] > arr[j+1]){

                swap(arr[j], arr[j+1]);
                isswap = true;
            }
        }

        if (!isswap){ // array is already sorted
            return;
        }
    }
}

void printArray(int arr[], int n){
    for (int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
}

int main (){
    int arr[] = {5,4,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);

    printArray(arr, n);
}



/*
     Algorithm:
     Start at the beginning of the array.
     Compare the first two elements. If the first element is greater than the second, swap them.
     Move to the next pair of elements and repeat the comparison and swap if needed.
     After each pass through the array, the largest unsorted element "bubbles up" to the end of the array.
     Repeat the process for the remaining unsorted elements, each time reducing the number of elements to compare.
     Stop when no swaps are needed, which means the array is sorted.
*/