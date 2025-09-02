#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A = {1, 3, 5, 9};  // Input array
    int moves = 0;                  // Minimum moves counter

    sort(A.begin(), A.end());       // Sort the array for easier processing

    while (!A.empty()) {
        int X = A[0] + 1;          // Choose X = first element + 1 (greedy choice)

        // Count elements within [X-1, X+1]
        vector<int> toRemove;      // Indices to remove
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - X) <= 1) {
                toRemove.push_back(i);
                if (toRemove.size() == 2) break; // remove at most 2 elements
            }
        }

        // Remove selected elements from the array
        for (int i = toRemove.size() - 1; i >= 0; i--) { // remove from back to avoid shifting
            A.erase(A.begin() + toRemove[i]);
        }

        moves++; // One move done
    }

    cout << "Minimum number of moves: " << moves << endl;

    return 0;
}

