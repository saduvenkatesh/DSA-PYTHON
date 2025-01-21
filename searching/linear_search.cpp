// Linear search 
// Time complexity : O(n)

#include<iostream>
using namespace std;

int linear_search(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if (arr[i] == target)
           return i;
    }
    return -1;
}

int main (){
    int arr[] = {3,4,15,6,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    cout<<linear_search(arr, size, target);

}