#include<iostream>
using namespace std;

int pow_of_2(int pow){

    if(pow > 0){
        return 2*pow_of_2(pow-1); // using recursion technique
    }
    else{
        return 1;
    }
}

int using_bit(int pow){
    return 1<<pow;
}

int main(){
    cout<<pow_of_2(10)<<endl;
    cout<<using_bit(5);
}