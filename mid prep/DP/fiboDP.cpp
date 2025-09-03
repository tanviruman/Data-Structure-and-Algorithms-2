
#include <iostream>     // For input/output
using namespace std;

const int MAX = 1000;   // Maximum size for Fibonacci array (supports n up to 999)

// Global variable to count recursive calls in memoization approach
long long calls = 0;

// Array used for memoization, initialized with -1 (meaning "not computed yet")
long long dp_memo[MAX];

// Recursive Fibonacci with memoization (Top-Down DP)
long long fib_memo(int n) {
    ++calls;                     // Count this function call
    if (n <= 1){                 // Base case: F(0)=0, F(1)=1
        return n;
    }
    if (dp_memo[n] != -1){       // If already computed, reuse it (avoid recomputation)
        return dp_memo[n];
    }
    // Compute and store result in dp_memo[n]
    return dp_memo[n] = fib_memo(n-1) + fib_memo(n-2);
}

// Iterative Fibonacci with tabulation (Bottom-Up DP)
long long fib_tab(int n) {
    if (n <= 1) return n;        // Base case

    long long dp[MAX] = {0};     // Create DP table initialized to 0
    dp[1] = 1;                   // F(1)=1, already set dp[0]=0

    // Build the sequence iteratively
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];                // Return F(n)
}

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 0) {   // Input validation: must be non-negative integer
        cout << "n must be a non-negative integer.\n";
        return 0;
    }

    // Initialize dp_memo with -1 (meaning "not yet computed")
    for (int i = 0; i <= n; ++i)
        dp_memo[i] = -1;

    // Run memoized recursion
    long long ans_memo = fib_memo(n);
    cout << "Top-Down (Memoization) Fibonacci(" << n << ") = " << ans_memo << "\n";
    cout << "total recursive calls in Top-Down approach = " << calls << "\n";

    // Run tabulation (iterative DP)
    long long ans_tab = fib_tab(n);
    cout << "Bottom-Up (Tabulation) Fibonacci(" << n << ") = " << ans_tab << "\n";

    return 0;  // End program
}
