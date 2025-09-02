
#include <iostream>
#include <vector>
using namespace std;

// Structure to store item details
struct Item {
    string name;   // Name of item
    int weight;    // Weight in kg
    int price;     // Price in Taka
    int available; // Available quantity in kg
};

int main() {
    // Initialize shop items
    vector<Item> items = {
        {"Rice", 12, 840, 12},
        {"Salt", 10, 870, 10},
        {"Saffron", 8, 2000, 8},
        {"Sugar", 5, 500, 5}
    };

    int knapsackCapacity = 9; // Each thief's capacity in kg
    int thiefCount = 0;       // Count of thieves used

    while (true) {
        int remainingCapacity = knapsackCapacity; // Capacity left for current thief
        int thiefProfit = 0;                      // Profit earned by current thief
        vector<pair<string, int>> thiefItems;     // Items taken by current thief

        // Check if any items are left in the shop
        bool shopEmpty = true;
        for (auto &item : items) {
            if (item.available > 0) {
                shopEmpty = false;
                break;
            }
        }
        if (shopEmpty) break; // Stop if shop is empty

        thiefCount++; // New thief enters

        // Greedy: try to take most valuable items that fit
        for (auto &item : items) {
            if (item.available <= 0) continue; // Skip if item finished

            // Take as much as possible of this item within remaining capacity
            int takeKg = min(item.available, remainingCapacity);
            if (takeKg > 0) {
                thiefItems.push_back({item.name, takeKg});   // Record item taken
                thiefProfit += (item.price * takeKg) / item.weight; // Add proportional price
                remainingCapacity -= takeKg;                // Reduce remaining capacity
                item.available -= takeKg;                   // Reduce item availability
            }

            if (remainingCapacity == 0) break; // Knapsack full
        }

        // Print current thief's loot
        cout << "Thief " << thiefCount << " takes:\n";
        for (auto &it : thiefItems) {
            cout << it.second << " kg of " << it.first << "\n";
        }
        cout << "Profit = " << thiefProfit << " Taka\n\n";
    }

    cout << "Total thieves needed to empty the shop: " << thiefCount << "\n";

    return 0;
}
