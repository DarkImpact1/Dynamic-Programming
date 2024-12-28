#include <bits/stdc++.h>
using namespace std;

int recursiveKnapsack(int wts[], int val[], int capacity, int n) {
    // Base case: if no items left or no capacity left
    if (capacity == 0 || n == 0) {
        return 0;
    }

    // If weight of the nth item is less than or equal to the remaining capacity
    if (wts[n - 1] <= capacity) {
        // Maximize by either including or excluding the item
        return max(
            val[n - 1] + recursiveKnapsack(wts, val, capacity - wts[n - 1], n - 1),
            recursiveKnapsack(wts, val, capacity, n - 1)
        );
    }
    // If weight of the nth item is more than the remaining capacity
    else {
        return recursiveKnapsack(wts, val, capacity, n - 1);
    }
}

int main() {
    int weights[] = {2, 3, 4, 5}; // Weights of the items
    int values[] = {3, 4, 5, 6};  // Corresponding values of the items
    int capacity = 9;             // Capacity of the knapsack
    int n = sizeof(weights) / sizeof(weights[0]); // Number of items

    // Output the result
    cout << "Maximum value in Knapsack: " 
         << recursiveKnapsack(weights, values, capacity, n) << endl;

    return 0;
}
