#include <iostream>   // For input/output
#include <algorithm>  // For sort() function
#include <iomanip>    // For controlling output precision

using namespace std;

// Structure to hold item details
struct Item {
    int value;      // Value of the item
    int weight;     // Weight of the item
    double ratio;   // Value/Weight ratio
    int index;      // Original item index (for display)
};

// Compare two items based on value (descending order)
bool cmpValue(Item a, Item b) {
    return a.value > b.value;
}

// Compare two items based on weight (ascending order)
bool cmpWeight(Item a, Item b) {
    return a.weight < b.weight;
}

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

// Strategy 1: Pick items by Value (highest value first)
void pickByValue(Item items[], int n, int capacity) {
    sort(items, items + n, cmpValue); // Sort items by value (descending)

    int remaining = capacity;  // Remaining capacity of knapsack
    int totalValue = 0;        // Total value of chosen items

    cout << "\nPicking items by Value (highest first):\n";
    cout << "Item\tValue\tWeight\tTaken\n";

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) { // If item fits
            cout << items[i].index << "\t"
                 << items[i].value << "\t"
                 << items[i].weight << "\t"
                 << items[i].weight << "\n";
            totalValue += items[i].value;   // Add item value
            remaining -= items[i].weight;   // Reduce remaining capacity
        }
    }

    cout << "Total value = " << totalValue << "\n";
}

// Strategy 2: Pick items by Weight (lowest weight first)
void pickByWeight(Item items[], int n, int capacity) {
    sort(items, items + n, cmpWeight); // Sort items by weight (ascending)

    int remaining = capacity;
    int totalValue = 0;

    cout << "\nPicking items by Weight (lowest first):\n";
    cout << "Item\tValue\tWeight\tTaken\n";

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            cout << items[i].index << "\t"
                 << items[i].value << "\t"
                 << items[i].weight << "\t"
                 << items[i].weight << "\n";
            totalValue += items[i].value;
            remaining -= items[i].weight;
        }
    }

    cout << "Total value = " << totalValue << "\n";
}

// Strategy 3: Pick items by Value/Weight Ratio (highest ratio first)
void pickByRatio(Item items[], int n, int capacity) {
    sort(items, items + n, cmpRatio); // Sort items by ratio (descending)

    int remaining = capacity;
    int totalValue = 0;

    cout << "\nPicking items by Value/Weight Ratio (highest first):\n";
    cout << "Item\tValue\tWeight\tTaken\n";

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            cout << items[i].index << "\t"
                 << items[i].value << "\t"
                 << items[i].weight << "\t"
                 << items[i].weight << "\n";
            totalValue += items[i].value;
            remaining -= items[i].weight;
        }
    }

    cout << "Total value = " << totalValue << "\n";
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    // Dynamically create array of items
    Item* items = new Item[n];

    // Input item details
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value: ";
        cin >> items[i].value;
        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;
        items[i].index = i + 1; // Store item number
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Show all items entered
    printItems(items, n);

    // Let user choose strategy
    cout << "\nChoose picking strategy:\n";
    cout << "1. By Value (highest value first)\n";
    cout << "2. By Weight (lowest weight first)\n";
    cout << "3. By Value/Weight ratio (highest ratio first)\n";
    cout << "Enter choice (1-3): ";

    int choice;
    cin >> choice;

    // Call function based on choice
    switch(choice) {
        case 1:
            pickByValue(items, n, capacity);
            break;
        case 2:
            pickByWeight(items, n, capacity);
            break;
        case 3:
            pickByRatio(items, n, capacity);
            break;
        default:
            cout << "Invalid choice.\n";
    }

    delete[] items; // Free memory
    return 0;
}
