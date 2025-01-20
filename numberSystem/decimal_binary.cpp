#include<iostream>
using namespace std;

int dec_to_binary(int decNum){

    int ans = 0; // binary number
    int pow = 1; // powers of 10

    while(decNum > 0){  // logic

        int rem = decNum%2;
        decNum /=2;
        ans += rem*pow;
        pow *= 10;  
    }
    return ans;
}

int bin_to_dec(int binNum){
    int ans = 0; // decNum
    int pow = 1; // powers of 2

    while (binNum > 0){
        int rem = binNum%10;
        binNum = binNum/10;
        ans += rem*pow;
        pow = pow*2;
    }
    return ans;
}

int main (){
    
    cout<<dec_to_binary(6)<<endl; // 110
    cout<<bin_to_dec(101); // 5
}