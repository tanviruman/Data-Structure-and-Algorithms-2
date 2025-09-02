#include <iostream>          // Include input/output library for cin and cout
using namespace std;         // Use standard namespace to avoid writing std:: every time

int main() {
    int denominations[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1}; // Array of available notes/coins
    int n = sizeof(denominations) / sizeof(denominations[0]);   // Calculate number of denominations

    int V;                      // Variable to store the amount entered by the user
    cout << "Enter the amount in Rs: ";  // Prompt user to enter amount
    cin >> V;                    // Read amount from user

    int totalCoins = 0;          // Variable to store total number of coins/notes used

    cout << "\nDenomination\tCount\n";   // Print table header
    cout << "-----------------------\n"; // Print separator for better formatting

    for (int i = 0; i < n; i++) {       // Loop through all denominations
        int count = V / denominations[i]; // Calculate how many notes/coins of this denomination can be used
        V = V - (count * denominations[i]); // Subtract the value of the used notes from remaining amount
        cout << denominations[i] << "\t\t" << count << "\n"; // Print denomination and count used
        totalCoins += count;              // Add the count to total number of coins/notes used
        if (V == 0)                       // If remaining amount becomes 0
            break;                        // Stop the loop, no more coins needed
    }

    cout << "-----------------------\n";       // Print separator
    cout << "Total coins/notes used: " << totalCoins << "\n"; // Print total coins/notes used

    return 0;  // End of program
}
