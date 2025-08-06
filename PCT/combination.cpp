#include <iostream>
using namespace std;

// Recursive function to compute nCr
int combination(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

// Function to calculate nth Catalan number
int catalan(int n) {
    int c = combination(2 * n, n);
    return c / (n + 1);
}

int main() {
    int n;
    cin >> n;

    cout << catalan(n) << endl;

    return 0;
}

