#include<iostream>
using namespace std;

void min_max_index(int arr[], int size){
    
    int min_num = INT8_MAX;
    int max_num = INT8_MIN;
    int min_index, max_index;

    for(int i=0; i<size; i++){
        if(arr[i] < min_num){
            min_num = arr[i];
            min_index = i;
        }

        if(arr[i] > max_num){
            max_num = arr[i];
            max_index = i;
        }
    }

    cout<<"min index, max index = "<<min_index<<", "<<max_index<<endl;
}

int main (){
    
    int arr[] = {10,2,30,-2,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    min_max_index(arr, size); // min index, max index = 3, 2
}