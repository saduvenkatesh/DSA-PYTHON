// Print maximum subarrays of given array
// max sub array with 'n' elements = n*(n+1)/2

#include<iostream>
#include<vector>
using namespace std;

int maxSubArraySum(vector<int>&vec){  // Bruteforce with time complexity O(n^2)
    int maxSum = INT8_MIN;
    int size = vec.size();
    for(int st=0; st<size; st++){
        int currSum = 0;
        for(int end = st; end<size; end++){
            currSum += vec[end];
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

int kandanes_algorithm(vector<int>&vec){  // maximum sub array sum using kandane's algorithm with O(n), most optimmized solution
    int currSum = 0, maxSum = INT8_MIN;
    for(int val : vec){
        currSum += val;
        maxSum = max(currSum, maxSum);
        if(currSum < 0)
           currSum = 0;
    }
    return maxSum;
}


void print_subArray(vector<int>&vec){  // Brute for printing maximum subarrays 
    int size = vec.size();
    for(int st=0; st<size; st++){
        for(int end=st; end<size; end++){
            for(int i=st; i<=end; i++)
               cout<<vec[i];
            cout<<" ";
        }
        cout<<endl;
    }
}

int main (){
    vector<int> vec = {1,2,3,4,5};
    print_subArray(vec);
    cout<<"maximum subarray sum using brute force : "<<maxSubArraySum(vec)<<endl;
    cout<<"maximum subarray sum using kandane's algorithm : "<<kandanes_algorithm(vec)<<endl;
}