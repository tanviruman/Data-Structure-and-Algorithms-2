#include <iostream>
using namespace std;

// Function to find cube root using binary search
double cubeRoot(double n) {
    double low = 1.0, high = n;
    double mid;

    // Loop until we get a precision of 0.00001 (enough for 4 decimal places)
    while (high - low > 0.00001) {
        mid = (low + high) / 2.0;
        double cube = mid * mid * mid;

        if (cube > n)
            high = mid;
        else
            low = mid;
    }

    return low;
}

int main() {
    double n;
    cin >> n;

    double result = cubeRoot(n);

    // Print result with 4 decimal digits manually
    // Multiply by 10000, cast to int to cut off extra digits, then divide again
    result = (int)(result * 10000 + 0.5);  // rounding
    cout << (result / 10000.0) << endl;

    return 0;
}

