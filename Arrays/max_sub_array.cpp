// Print maximum subarrays of given array
// max sub array with 'n' elements = n*(n+1)/2

#include<iostream>
using namespace std;

void print_subArray(int arr[], int size){  // Brute for orinting maximum subarrays 
    
    for(int st=0; st<size; st++){
        for(int end=st; end<size; end++){
            for(int i=st; i<=end; i++)
               cout<<arr[i];
            cout<<" ";
        }
        cout<<endl;
    }
}

int main (){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_subArray(arr,size);
}