#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

const int INF = 1e9;       // A large value used to represent "infinity"

// Function to calculate minimum number of coins to make a given amount
// coins[] = array of coin denominations
// m = number of coin types
// amount = target amount
// dp = dynamic programming table (2D array)
int minCoins(int coins[], int m, int amount, int dp[][100]) {
    // Initialize the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= amount; j++) {
            if (i == 0)                           // If no coins available
                dp[i][j] = (j == 0 ? 0 : INF);    // 0 coins needed for 0 amount, otherwise impossible (INF)
            else
                dp[i][j] = INF;                   // Default: set to INF (impossible initially)
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {                // Iterate through each coin type
        for (int j = 0; j <= amount; j++) {       // Iterate through each amount from 0 → target
            if (coins[i-1] > j) {                 // If coin is larger than the current amount
                dp[i][j] = dp[i-1][j];            // Cannot use this coin → take result from previous row
            } else {
                // Either:
                // 1. Do not use this coin → dp[i-1][j]
                // 2. Use this coin → 1 + dp[i][j - coin]
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }

    return dp[m][amount]; // Minimum coins needed to form the target amount
}

// Function to reconstruct which coins were used
void findCoins(int coins[], int m, int amount, int dp[][100]) {
    int i = m, j = amount;                  // Start from bottom-right corner of dp table
    cout << "Coins used: ";
    while (i > 0 && j > 0) {                // While we still have coins and remaining amount
        if (dp[i][j] == dp[i-1][j]) {       // If result same as without using current coin
            i--;                            // Move to previous coin type
        } else {
            cout << coins[i-1] << " ";      // Use this coin
            j -= coins[i-1];                // Reduce amount by coin value
        }
    }
    cout << endl;
}

int main() {
    int coins[] = {1, 3, 4};                // Available coin denominations
    int m = sizeof(coins)/sizeof(coins[0]); // Number of coin types
    int amount = 6;                         // Target amount to form

    int dp[100][100];                       // DP table (supports up to 100 coins and amount 100)

    int result = minCoins(coins, m, amount, dp); // Compute minimum coins

    if (result >= INF)                      // If result is INF → no solution
        cout << "No solution possible" << endl;
    else {
        cout << "Minimum coins needed = " << result << endl;
        findCoins(coins, m, amount, dp);    // Print which coins are used
    }

    return 0;                               // End of program
}
