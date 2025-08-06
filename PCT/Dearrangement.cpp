#include <iostream>
using namespace std;

// Recursive function to calculate derangement (!n)
int derangement(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

int main() {
    int n;
    cin >> n;

    cout << derangement(n) << endl;

    return 0;
}

