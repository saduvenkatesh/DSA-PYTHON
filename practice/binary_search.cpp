#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int tar, int st, int end){
    
    if(st<=end){
        int mid = st + (end-st)/2;
        if(tar==arr[mid])
           return mid;
        else if (tar<arr[mid])
           return binary_search(arr, tar, st, mid-1);
        else
           return binary_search(arr, tar, mid+1, end);
    }
    return -1;
}

int main(){
    vector<int> arr = {3,4,7,9,10,12,45,56}; // only sorted arrays are allowed for binary search
    int st=0,end=arr.size(), tar=45;
    //cout<<end;
    cout<<binary_search(arr, tar, st, end);
}