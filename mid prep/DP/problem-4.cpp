#include <bits/stdc++.h>
using namespace std;

// Structure to represent each trip request
struct Trip {
    string id;    // Customer ID (unique identifier for the request)
    int start;    // Start time of the trip
    int duration; // Duration of the trip
    int end;      // End time = start + duration
};

// Comparator function to sort trips by their end times (earlier finishing trips first)
bool cmp(Trip a, Trip b) {
    return a.end < b.end;
}

int main() {
    int M, N, X;
    cin >> M >> N >> X;  // Read money per trip (M), number of requests (N), and required break time (X)

    vector<Trip> trips(N);  // Vector to store all trip requests

    // Input each trip request
    for (int i = 0; i < N; i++) {
        cin >> trips[i].id >> trips[i].start >> trips[i].duration;  // Read customer ID, start time, duration
        trips[i].end = trips[i].start + trips[i].duration;          // Compute and store end time
    }

    // Sort all trips by end time (greedy strategy: choose earliest finishing trips first)
    sort(trips.begin(), trips.end(), cmp);

    int count = 0;                 // Keeps track of number of trips chosen
    int last_end = -1e9;           // Tracks end time of last chosen trip (initialized to very small value)
    vector<string> chosen;         // Store IDs of the chosen trips

    // Iterate over all trips and select them greedily
    for (int i = 0; i < N; i++) {
        // Check if the current trip can be taken after the required break
        if (trips[i].start >= last_end + X) {
            chosen.push_back(trips[i].id);  // Select this trip (save its ID)
            last_end = trips[i].end;        // Update last_end to this trip's end time
            count++;                        // Increase count of chosen trips
        }
    }

    // Print the profit calculation
    cout << "Profit: " << count << " x " << M << " = " << count * M << "\n";

    // Print the IDs of the chosen tasks
    cout << "Chosen Tasks:\n";
    for (auto &id : chosen) {
        cout << id << "\n";  // Output each chosen trip ID
    }

    return 0;  // End of program
}
