#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int,int> minmax(vector<int> &arr, int st, int end){

    if(st==end)
        return {arr[st], arr[st]};
    if (end==st+1){
        if(arr[st<arr[end]])
           return {arr[st], arr[end]};
        else
           return {arr[end], arr[st]};
    }

    // Divide the array into two halfs
    int mid = st + (end-st)/2;
    pair<int,int> lefthalfminmax = minmax(arr,st,mid);
    pair<int,int> righthalfminmax = minmax(arr,mid+1,end);

    // combine results
    int overallmin = min(lefthalfminmax.first,righthalfminmax.first);
    int overallmax = max(lefthalfminmax.second,righthalfminmax.second);

    return {overallmin, overallmax};
}

int main(){
    vector<int> arr = {6,2,3,-5,15};
    pair<int,int> result = minmax(arr,0,arr.size()-1);
    cout<<result.first<<", "<<result.second;
}