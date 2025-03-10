#include <bits/stdc++.h>
using namespace std;

// Structure to store item details
struct Item {
    int weight, value;
    double ratio;
};

// Comparator function for sorting items by value-to-weight ratio
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Greedy Knapsack Function
double knapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp); // Sort items by ratio
    double maxProfit = 0.0;
    
    for (auto &item : items) {
        if (W >= item.weight) { // Take full item
            W -= item.weight;
            maxProfit += item.value;
        } else { // Take fraction of item
            maxProfit += item.value * ((double)W / item.weight);
            break;
        }
    }
    return maxProfit;
}

int main() {
    vector<Item> items = {{10, 60, 0}, {20, 100, 0}, {30, 120, 0}};
    int W = 50; // Knapsack capacity

    // Calculate value-to-weight ratio
    for (auto &item : items) 
        item.ratio = (double)item.value / item.weight;

    cout << "Maximum Profit: " << knapsack(W, items) << endl;
    return 0;
}


/*
     Sort Items: Sort items by their value-to-weight ratio in descending order.
     Pick Highest Value First: Start picking items with the highest ratio until the knapsack is full.
     Check Capacity: If an item fits completely, take it; otherwise, take a fraction of it.
     Update Remaining Space: Deduct the item's weight from the knapsack capacity.
     Compute Total Value: Sum up the values of selected items for the maximum profit.
     
*/

/*
    W = 50
    Items = { {10, 60}, {20, 100}, {30, 120} }
    Maximum Profit: 240
*/