#include<iostream>
#include<vector>
using namespace std;

void display_vector(vector<char>vec){
    for(char letter : vec)
      cout<<letter<<endl;
}

void display_vector(vector<int>vec){
    for(char letter : vec)
      cout<<letter<<endl;
}

int main(){
    vector<char>vec = {'a','b','c','d','e'};
    display_vector(vec);


    vector<int>vec3(4,1); // creates vector with size 4 and initializes all indexe's value to zero
    cout<<vec3[0]<<endl; // 1
    cout<<vec3[3]<<endl; // 1
    cout<<vec3[4]<<endl;  // don't give error but prints some garbage value
    display_vector(vec3);

    vector<int>numbers; // initialy size=0 
    cout<<numbers[0]; // Segmentation Fault becoz size is 0;

}