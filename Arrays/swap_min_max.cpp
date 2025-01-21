// Swap min and max numbers of an array

#include<iostream>
using namespace std;

void swap_min_max(int arr[], int size){

    int minIndex, maxIndex;
    int min = INT8_MAX;
    int max = INT8_MIN;

    for(int i=0; i<size; i++){

        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }

        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    swap(arr[minIndex],arr[maxIndex]);
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    swap_min_max(arr, size);
    printArray(arr, size);
}