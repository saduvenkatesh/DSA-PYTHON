#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]) // change rel opearator ">" to "<" for descending order sorting
               swap(arr[j], arr[j+1]);
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    int arr[]={4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);
    printArray(arr, n);
}