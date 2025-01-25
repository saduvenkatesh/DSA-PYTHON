#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array for Binary Search
    sort(arr, arr + n);

    cout << "Enter the element to search: ";
    cin >> key;

    binarySearch(arr, n, key);

    return 0;
}
