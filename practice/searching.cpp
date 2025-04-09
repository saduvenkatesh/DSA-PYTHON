#include<iostream>
#include<vector>
using namespace std;

int binarysearch(int arr[],int tar, int st, int end){
    if(st<=end){
        int mid = st+(end-st)/2;

        if(tar>arr[mid])
           return binarysearch(arr,tar,mid+1,end);
        else if (tar<arr[mid])
            return binarysearch(arr,tar,st,mid);
        else
            return mid;
    }
    return -1;
}

int linearsearch(int arr[], int tar,int n){
    for(int i=0; i<n; i++){
        if(tar==arr[i])
          return i;
    }
    return -1;
}

pair<int,int> minmax(vector<int>&arr,int st,int end){
    if(st==end)
       return {arr[st],arr[st]};
    if(end==st+1){
        if(arr[st]<arr[end])
          return {arr[st],arr[end]};
        else
          return {arr[end],arr[st]};
    }

    int mid=st+(end-st)/2;
    pair<int,int> leftminmax = minmax(arr,st,mid);
    pair<int,int> rightminmax = minmax(arr,mid+1,end);

    // overall min, max
    int overallmin = min(leftminmax.first,rightminmax.first);
    int overallmax = max(leftminmax.second,rightminmax.second);

    return {overallmin,overallmax};
}
int main(){
    int arr[]={3,6,7,14,16};
    int tar=16;
    int end = sizeof(arr)/sizeof(arr[0]);
    cout<<binarysearch(arr,tar,0,end)<<endl;
    //cout<<linearsearch(arr,tar,end);
    vector<int> vec = {5,3,1,64,-2};
    pair<int,int> result = minmax(vec,0,vec.size()-1);
    cout<<result.first<<", "<<result.second;

}