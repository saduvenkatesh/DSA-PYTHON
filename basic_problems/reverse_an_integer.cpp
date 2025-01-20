#include<iostream>
using namespace std;

int reverse(int number){  // logic
    int reversed = 0;
    while(number>0){
        int rem = number%10;
        reversed = reversed*10 + rem;
        number = number/10;
    }
    return reversed;
}

int main(){
    cout<<reverse(123);
}