#include<iostream>
#include<vector>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i=1; i<n;i++){
        int prev=i-1, curr=arr[i];
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void bubblesort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
            if(!isSwap)
              return;
        }
    }
}

void merge(int arr[], int st, int mid, int end){
    vector<int> temp;
    int i=st, j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
           temp.push_back(arr[i++]);
        if(arr[i]>arr[j])
           temp.push_back(arr[j++]);
    }

    while(i<=mid)
       temp.push_back(arr[i++]);
    while(j<=end)
       temp.push_back(arr[j++]);
    
    for(int idx=0 ; idx<temp.size();idx++)
       arr[st+idx]= temp[idx];
}

void mergesort(int arr[],int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

int partition(int arr[], int st, int end){
    int piv=arr[st];
    int i=st+1, j=end;
    while(i<=j){
        while(i<=j && arr[i]<=piv) i++;
        while(arr[j]>piv) j--;

        if (i<j)
          swap(arr[i], arr[j]);
    }

    swap(arr[st],arr[j]);
    return j;
}
int quicksort(int arr[], int st, int end){
    if(st<end){
        int pividx=partition(arr,st,end);
        quicksort(arr,st,pividx-1);
        quicksort(arr,pividx+1,end);
    }
}
int main(){
    int arr[]={5,1,2,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    //insertionsort(arr,n);
    //bubblesort(arr,n);
    mergesort(arr,0,n-1);
    //quicksort(arr,0,n);

    for(int val : arr)
      cout<<val<<" ";
}