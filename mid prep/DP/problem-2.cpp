#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// Function to find k closest elements to the target
vector<int> findKClosest(vector<int>& arr, int k, int target) {
    int n = arr.size();   // Get size of input array

    // Case 1: If target is smaller than or equal to the first element
    // Return the first k elements
    if (target <= arr[0]) {
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    // Case 2: If target is larger than or equal to the last element
    // Return the last k elements
    if (target >= arr[n-1]) {
        return vector<int>(arr.end() - k, arr.end());
    }

    // Binary search to find the first element >= target
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;   // Compute mid index
        if (arr[mid] < target)        // If middle element is smaller than target
            low = mid + 1;            // Move right
        else
            high = mid;               // Otherwise, move left
    }

    // After loop, arr[low] is the first element >= target
    int left = low - 1;   // Initialize left pointer to element just before target
    int right = low;      // Initialize right pointer to element at or after target

    vector<int> result;   // To store chosen k elements

    // Pick k closest elements
    while (k--) {
        // If left pointer goes out of bounds, take from right
        if (left < 0) {
            result.push_back(arr[right++]);
        }
        // If right pointer goes out of bounds, take from left
        else if (right >= n) {
            result.push_back(arr[left--]);
        }
        // Otherwise, choose the closer one to target
        else {
            if (abs(arr[left] - target) <= abs(arr[right] - target))
                result.push_back(arr[left--]);   // Pick left if it is closer
            else
                result.push_back(arr[right++]);  // Pick right if it is closer
        }
    }

    // The chosen elements are not guaranteed to be in ascending order
    // So we sort them based on their order in the original array
    sort(result.begin(), result.end(),
         [&](int a, int b) {
             // Compare positions of a and b in arr to maintain original order
             return find(arr.begin(), arr.end(), a) < find(arr.begin(), arr.end(), b);
         });

    return result;  // Return the final result
}

int main() {
    // Example 1
    vector<int> arr1 = {10, 12, 15, 17, 18, 20, 25};
    int k1 = 4, target1 = 16;
    auto res1 = findKClosest(arr1, k1, target1);
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> arr2 = {2, 3, 4, 5, 6, 7};
    int k2 = 3, target2 = 1;
    auto res2 = findKClosest(arr2, k2, target2);
    for (int x : res2) cout << x << " ";
    cout << endl;

    // Example 3
    vector<int> arr3 = {2, 3, 4, 5, 6, 7};
    int k3 = 2, target3 = 8;
    auto res3 = findKClosest(arr3, k3, target3);
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;  // End of program
}

