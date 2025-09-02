#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store train interval
struct Train {
    int arrival;
    int departure;
};

int main() {
    vector<Train> trains = {
        {8, 12}, {6, 9}, {11, 14}, {2, 7},
        {1, 7}, {12, 20}, {7, 12}, {13, 19}
    };

    // Sort trains by earliest departure time
    sort(trains.begin(), trains.end(), [](Train a, Train b) {
        return a.departure < b.departure;
    });

    int count = 0;           // Number of trains that can use the platform
    int lastDeparture = -1;  // End time of last scheduled train

    cout << "Selected trains (arrival, departure):\n";

    for (auto t : trains) {
        // Check if train can be scheduled after previous one with 1 unit gap
        if (t.arrival >= lastDeparture + 1) {
            cout << "[" << t.arrival << ", " << t.departure << ")\n";
            lastDeparture = t.departure; // Update last departure
            count++;                     // Increment count
        }
    }

    cout << "Maximum number of trains that can use the platform: " << count << "\n";

    return 0;
}

