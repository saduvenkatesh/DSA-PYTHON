#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int st, int mid, int end){
    vector<int> temp;
    int i=st, j= mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
}

void mergesort(int arr[], int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;
        mergesort(arr, st, mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
      cout<<arr[i]<<" ";
}

int main (){
    int arr[] = {3,2,5,1,0,14,12};
    int st=0, end= sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,st, end-1);
    printArray(arr, end);
}