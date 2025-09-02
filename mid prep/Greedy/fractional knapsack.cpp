#include <iostream>   // For input/output
#include <algorithm>  // For sort() function
#include <iomanip>    // For controlling output precision

using namespace std;

// Structure to hold item details
struct Item {
    int value;      // Value of the item
    int weight;     // Weight of the item
    double ratio;   // Value/Weight ratio
    int index;      // Original item index
};

// Compare two items based on ratio (descending order)
bool cmpRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Function to print all items with details
void printItems(Item items[], int n) {
    cout << "\nItems:\n";
    cout << "Item\tValue\tWeight\tValue/Weight\n";
    for (int i = 0; i < n; i++) {
        cout << items[i].index << "\t"
             << items[i].value << "\t"
             << items[i].weight << "\t"
             << fixed << setprecision(2) << items[i].ratio << "\n";
    }
}

// Fractional Knapsack using Greedy (by ratio)
void fractionalKnapsack(Item items[], int n, int capacity) {
    sort(items, items + n, cmpRatio); // Sort items by ratio (descending)

    double totalValue = 0.0;  // Total value of items taken
    int remaining = capacity; // Remaining knapsack capacity

    cout << "\nPicking items by Fractional Knapsack (highest ratio first):\n";
    cout << "Item\tValue\tWeight\tTaken\n";

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            // Take the whole item
            cout << items[i].index << "\t"
                 << items[i].value << "\t"
                 << items[i].weight << "\t"
                 << items[i].weight << "\n";
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            // Take fraction of item
            double fraction = (double)remaining / items[i].weight;
            double valueTaken = items[i].value * fraction;
            cout << items[i].index << "\t"
                 << items[i].value << "\t"
                 << items[i].weight << "\t"
                 << remaining << " (fraction)\n";
            totalValue += valueTaken;
            remaining = 0; // Knapsack is now full
        }
    }

    cout << "Total value = " << fixed << setprecision(2) << totalValue << "\n";
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item* items = new Item[n];

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value: ";
        cin >> items[i].value;
        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;
        items[i].index = i + 1;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    printItems(items, n);

    fractionalKnapsack(items, n, capacity);

    delete[] items;
    return 0;
}

