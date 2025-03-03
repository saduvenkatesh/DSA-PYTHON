#include <iostream>
#include <vector>
using namespace std;

// Function to find min and max in an array
pair<int, int> findMinMax(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) {
        cout << "Array is empty!";
        return {INT16_MAX, INT16_MIN}; 
    }

    int minVal = arr[0], maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    return {minVal, maxVal};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pair<int, int> result = findMinMax(arr);

    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;

    return 0;
}
