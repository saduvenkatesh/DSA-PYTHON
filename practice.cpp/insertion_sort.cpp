#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        bool isSwap = false;
        int prev=i-1, curr= arr[i];
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
            isSwap= true;
            //cout<<"hi"; use it for already sorted array for cross checking 
        }
        if(!isSwap)
          return;
        arr[prev+1]=curr;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
      cout<<arr[i]<<" ";
}

int main (){
    int arr[] = {1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    printArray(arr, n);
}