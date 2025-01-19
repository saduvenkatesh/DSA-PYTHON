 /*
     Selection sort :
     It works on the principle of identifying the smallest element in the list and moving it to the beginning of the list.
     This process is repeated until all the elements in the list  are sorted.
     
 */

#include<iostream>
using namespace std;

void selectionSort(int arr [],int n){

    for(int i=0; i<n-1; i++){
        int smallestIndex = i;

        for(int j=i+1; j<n; j++){  // find the smallest index and swap each other
            
            if (arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]); 
    }
}

void printArray(int arr[], int n){  // print the array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]= {15,4,19,6,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n); 

    printArray(arr, n);
}