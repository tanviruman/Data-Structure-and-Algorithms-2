#include <bits/stdc++.h>   // Include all standard libraries
using namespace std;

// Structure to hold vegetable data
struct Vegetable {
    string name;        // Name of vegetable
    double amount;      // Available amount (KG)
    double buy;         // Total buying price
    double sell;        // Total selling price
    double profit;      // Total profit (sell - buy)
    double profitPerKg; // Profit per KG
};

// Comparator function for sorting by profit per KG (descending)
bool cmp(Vegetable a, Vegetable b) {
    return a.profitPerKg > b.profitPerKg;
}

int main() {
    int n;        // Number of vegetables
    double W;     // Weight limit of truck (KG)
    cin >> n >> W;

    vector<Vegetable> veg(n);  // Store vegetable list

    // Read vegetable info
    for (int i = 0; i < n; i++) {
        cin >> veg[i].name >> veg[i].amount >> veg[i].buy >> veg[i].sell;
        veg[i].profit = veg[i].sell - veg[i].buy;            // Calculate total profit
        veg[i].profitPerKg = veg[i].profit / veg[i].amount;  // Profit per KG
    }

    // Sort vegetables by profit per KG (highest first)
    sort(veg.begin(), veg.end(), cmp);

    double totalProfit = 0.0;                // Track total profit
    vector<pair<string, double>> chosen;     // Store chosen vegetables and amount taken

    // Select vegetables greedily
    for (int i = 0; i < n; i++) {
        if (W <= 0) break;   // If truck full, stop

        if (veg[i].amount <= W) {
            // Take the whole stock of this vegetable
            W -= veg[i].amount;
            totalProfit += veg[i].profit;
            chosen.push_back({veg[i].name, veg[i].amount});
        } else {
            // Take only part of this vegetable
            double fraction = W;
            totalProfit += fraction * veg[i].profitPerKg;
            chosen.push_back({veg[i].name, fraction});
            W = 0;   // Truck is full
        }
    }

    // Print chosen vegetables and amounts
    for (auto &p : chosen) {
        cout << p.first << " " << fixed << setprecision(0) << p.second << " kg\n";
    }

    // Print maximum profit
    cout << "Maximum profit = Tk. " << fixed << setprecision(0) << totalProfit << "\n";

    return 0;
}

