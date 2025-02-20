#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int st, int mid, int end){
     
     vector<int> temp;
     int i=st, j=mid+1;

     while(i<st && j<end){
        
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
     }

     // For left half
     while(i<=mid){
        temp.push_back(arr[i]);
        i++;
     }
        
    
    // For right half
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    // To copy the sorted elements from temp vector to the original vector
    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
     
}

void mergesort(vector<int>&arr, int st, int end){

      if(st<end){
         
          int mid = st + (end-st)/2;
          mergesort(arr, st, mid); // For left half
          mergesort(arr, mid+1, end); // For right half
            
            merge(arr, st, mid, end);
      }

}

void greet(){
   cout<<"hello";
   
}

int main(){
    vector<int> arr = {12,3,35,8,32,7};
    int st=0, end= arr.size();
    mergesort(arr, st, end);

    // Print the array
    
}