#include<iostream>
#include<vector>
using namespace std;

int single_number(vector<int>&vec, int size){
    int ans=0;
    for(int i=0; i<size; i++)
       ans ^= vec[i];   //0^0 = 0, 1^1 = 0, 1^0 = 1, 0^1 = 1 bitwise XOR operator
    return ans;
}

int main(){
    vector<int> vec = {10,20,10,20,30,40,40}; 
    cout<<single_number(vec, vec.size());  // 30
}