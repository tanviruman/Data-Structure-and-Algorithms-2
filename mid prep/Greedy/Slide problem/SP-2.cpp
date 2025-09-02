#include <iostream>          // Include input/output library for cin and cout
using namespace std;         // Use standard namespace to avoid writing std:: every time

int main() {
    int S, N, M;             // S = days to survive, N = max units per day, M = units needed per day
    cout << "Enter number of days to survive (S): ";
    cin >> S;                // Read S
    cout << "Enter max units of food per day (N): ";
    cin >> N;                // Read N
    cout << "Enter units of food required per day (M): ";
    cin >> M;                // Read M

    // First, check if it is even possible to survive
    // Calculate total food needed
    int totalFoodNeeded = S * M;

    // Calculate number of days the shop is open in the survival period
    int fullWeeks = S / 7;                  // Number of full weeks
    int remainingDays = S % 7;              // Remaining days beyond full weeks
    int shopOpenDays = fullWeeks * 6;       // Each full week, shop open 6 days (closed on Sunday)

    // In the remaining days, shop open unless there is a Sunday
    // Assume day 1 is Monday, so shop closed only if remainingDays >= 7
    if (remainingDays > 0) {
        // Count shop open days in the remaining days
        shopOpenDays += min(remainingDays, 6);  // At most 6 open days
    }

    // Calculate maximum food that can be bought
    int maxFoodBuyable = shopOpenDays * N;

    if (maxFoodBuyable < totalFoodNeeded) {
        // Not enough food can be bought
        cout << "It is not possible to survive.\n";
    } else {
        // Minimum number of days to buy food = ceil(totalFoodNeeded / N)
        int minDaysToBuy = totalFoodNeeded / N;
        if (totalFoodNeeded % N != 0) {
            minDaysToBuy += 1;  // Add one more day if there's a remainder
        }
        cout << "Minimum number of days to buy food: " << minDaysToBuy << "\n";
    }

    return 0;  // End of program
}

