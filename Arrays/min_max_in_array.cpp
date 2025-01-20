#include<iostream>
using namespace std;

void min_max_number(int nums[], int size){
    int smallest_num = INT8_MAX;
    int largest_num = INT8_MIN;

    for(int i=0; i<size; i++){
        smallest_num = min(nums[i], smallest_num);
        largest_num = max(nums[i], largest_num);
    }

    cout<<"min,max = "<<smallest_num<<","<<largest_num;
}

int main(){
    
    int nums []= {4,3,5,2,1};
    int size = sizeof(nums)/sizeof(nums[0]);
    min_max_number(nums, size);
}