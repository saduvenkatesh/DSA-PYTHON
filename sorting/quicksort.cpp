#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
    int piv=arr[st];
    int i=st+1, j=end;
    while(i<=j){
        while(i<=end && arr[i]<=piv) i++;
        while(arr[j]>piv) j--;

        if(i<j)
           swap(arr[i], arr[j]);
    }

    swap(arr[st],arr[j]);
    return j;
}

void quicksort(int arr[], int st, int end){
    if(st<end){
        int pividx=partition(arr,st,end);
        quicksort(arr,st,pividx-1);
        quicksort(arr,pividx+1,end);
    }
}

int main(){
    int arr[]={5,32,3,1,2};
    int st=0, end=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,st,end-1);

    for(int val : arr)
       cout<<val<<" ";
}