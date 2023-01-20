/*
                -> 0/1 Knapsack Problem <- (IMP)

A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

*/

#include<iostream>
#include<vector>

using namespace std;

int solveMem(vector<int> &values, vector<int> &weights, int n, int index, int capacity, vector<vector<int> > &dp) {
    if (index == 0) {
        if (weights[0] <= capacity) {
            return values[0];
        } else {
            return 0;
        }
    }
    
    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }
    
    int include = 0;
    if (weights[index] <= capacity) {
        include = values[index] + solveMem(values, weights, n, index - 1, capacity - weights[index], dp);
    }
    
    int exclude = 0 + solveMem(values, weights, n, index - 1, capacity, dp);
    
    dp[index][capacity] = max(include, exclude);
    
    return dp[index][capacity];
}

int solveTab(vector<int> &values, vector<int> &weights, int n, int capacity) {
    vector<vector<int> > dp (n, vector<int> (capacity + 1, 0)); 
    
    for (int w = weights[0]; w <= capacity; w++) {
         if (weights[0] <= capacity) {
            dp[0][w] = values[0];
        } else {
            dp[0][w] = 0;
         }
    }
    
    for (int index = 1; index < n; index++) {
        for (int w = 0; w <= capacity; w++) {
            int include = 0;
            if (weights[index] <= w) {
                include = values[index] + dp[index - 1][w - weights[index]];
            }

            int exclude = 0 + dp[index - 1][w];
            
            dp[index][w] = max(include, exclude);
        }
    }
    
    return dp[n-1][capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
    vector<vector<int> > dp (n, vector<int> (w + 1, -1));
    int index = n - 1;
    return solveMem(values, weights, n, index, w, dp);
}