// find the sum and product of element in array

#include<iostream>
using namespace std;

int sum (int arr[], int size){
    size -= 1;
    if(size<0)
      return 0;
    return arr[size]+sum(arr,size);
}

int product (int arr[], int size){
    size -= 1;
    if(size < 0)
      return 1;
    return arr[size]*product(arr,size);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<sum(arr, size)<<endl;
    cout<<product(arr, size);
}