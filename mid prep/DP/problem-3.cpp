#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// Structure to hold vegetable info
struct Vegetable {
    string name;        // Name of vegetable
    double amount;      // Available amount (in KG)
    double buy;         // Total buying price
    double sell;        // Total selling price
    double profit;      // Total profit (sell - buy)
    double profitPerKg; // Profit per KG
};

// Comparator to sort vegetables by profit per KG (descending)
bool cmp(Vegetable a, Vegetable b) {
    return a.profitPerKg > b.profitPerKg;
}

int main() {
    int n;              // Number of vegetables
    double W;           // Maximum weight allowed on truck (capacity)
    cin >> n >> W;

    vector<Vegetable> veg(n);

    // Input vegetable info
    for (int i = 0; i < n; i++) {
        cin >> veg[i].name >> veg[i].amount >> veg[i].buy >> veg[i].sell;
        veg[i].profit = veg[i].sell - veg[i].buy;              // Total profit
        veg[i].profitPerKg = veg[i].profit / veg[i].amount;    // Profit per KG
    }

    // Sort by profit per KG (greedy choice)
    sort(veg.begin(), veg.end(), cmp);

    double totalProfit = 0.0;     // Track total profit
    vector<pair<string, double>> chosen; // Vegetables chosen with amount

    // Greedy selection
    for (int i = 0; i < n; i++) {
        if (W <= 0) break;  // Stop if truck is full

        if (veg[i].amount <= W) {
            // Take the whole vegetable stock
            W -= veg[i].amount;
            totalProfit += veg[i].profit;
            chosen.push_back({veg[i].name, veg[i].amount});
        } else {
            // Take only part of it
            double fraction = W;   // Take as much as remaining capacity
            totalProfit += fraction * veg[i].profitPerKg;
            chosen.push_back({veg[i].name, fraction});
            W = 0; // Truck is full
        }
    }

    // Output results
    for (auto &p : chosen) {
        cout << p.first << " " << p.second << "KG\n";
    }
    cout << "Maximum Profit = " << totalProfit << " Taka\n";

    return 0;
}

