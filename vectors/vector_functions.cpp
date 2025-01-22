// VEctor functions
#include<iostream>
#include<vector>
using namespace std;

void push_back(vector<int>&vec){  //This is pass by reference becoz it has ampersand
    vec.push_back(30);
    vec.push_back(40);
}

void push_back(vector<char>vec){
    vec.push_back('c');
}


int main(){

    vector<int> vec1 = {10,20,'a'};
    cout<<vec1[2]<<endl; // prints ASCII value of 'a'
    push_back(vec1);
    cout<<vec1[3]<<endl; //30 becoz of pass by reference
    vec1.pop_back();  // pop_back is not working
    cout<<vec1[3]<<endl;
    cout<<vec1.front()<<endl;
    cout<<vec1.back()<<endl;
    cout<<vec1.at(3)<<endl;


    vector<char> vec2 = {'a','b'};
    cout<<vec2[1]<<endl; // b
    cout<<vec2[2]<<endl; // gives garbage value becoz of pass by value
    
}