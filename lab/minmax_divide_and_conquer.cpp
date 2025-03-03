#include <iostream>
#include <vector>
using namespace std;

// Function to find min and max using divide and conquer
pair<int, int> findMinMaxDC(vector<int> &arr, int low, int high) {
    // If there is only one element
    if (low == high)
        return {arr[low], arr[low]};

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;
    pair<int, int> leftMinMax = findMinMaxDC(arr, low, mid);
    pair<int, int> rightMinMax = findMinMaxDC(arr, mid + 1, high);

    // Combine results
    int overallMin = min(leftMinMax.first, rightMinMax.first);
    int overallMax = max(leftMinMax.second, rightMinMax.second);

    return {overallMin, overallMax};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pair<int, int> result = findMinMaxDC(arr, 0, n - 1);

    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;

    return 0;
}


/*
    Algorithm : 

    Split the array into two halves.
    Recursively find the min and max in both halves.
    Combine the results to get the overall min and max.
*/