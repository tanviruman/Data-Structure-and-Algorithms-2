#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store train arrival and departure
struct Train {
    int arrival;
    int departure;
    int index; // To identify train
};

int main() {
    // Initialize trains
    vector<Train> trains = {
        {1000, 1030, 1}, {840, 1030, 2}, {850, 1040, 3},
        {1700, 2000, 4}, {800, 835, 5}, {1300, 1800, 6},
        {1500, 1650, 7}, {1200, 1380, 8}
    };

    // Sort trains by earliest departure time
    sort(trains.begin(), trains.end(), [](Train a, Train b) {
        return a.departure < b.departure;
    });

    int count = 0;              // Count of trains scheduled
    int lastDeparture = -10;    // Last departure time, initially -10 for safety break
    vector<int> selectedTrains; // Store indices of selected trains

    cout << "Selected trains (arrival, departure):\n";

    for (auto t : trains) {
        // Check if train can be scheduled with at least 10 min gap
        if (t.arrival >= lastDeparture + 10) {
            cout << "[" << t.arrival << ", " << t.departure << "]\n";
            lastDeparture = t.departure;      // Update last departure
            selectedTrains.push_back(t.index);
            count++;
        }
    }

    cout << "Maximum number of trains that can use the platform: " << count << "\n";

    return 0;
}

