#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int st, int mid, int end);

void merge_sort(int arr[], int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;
        merge_sort(arr, st, mid);
        merge_sort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

void merge(int arr[], int st, int mid, int end){
    vector<int> temp;
    int i=st, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
           temp.push_back(arr[i++]);
        else
           temp.push_back(arr[j++]);
    }

    while(i<=mid)
       temp.push_back(arr[i++]);
    while(j<=end)
       temp.push_back(arr[j++]);
    
    for(int i=0; i<temp.size();i++)
       arr[i+st] = temp[i];
}

void printArray(int arr[], int end){
    for(int i=0; i<end; i++)
       cout<<arr[i]<<" ";
}

int main(){
    int arr[]={5,2,4,1,7,3};
    int end = sizeof(arr)/sizeof(arr[0]), st=0;
    merge_sort(arr, st, end-1);
    printArray(arr, end);
}