#include <iostream>
using namespace std;

// Function to compute b^n using Divide and Conquer
int power(int b, int n) {
    if (n == 0)
        return 1;

    int half = power(b, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return b * half * half;
}

int main() {
    int b, n;
    cin >> b >> n;

    cout << power(b, n) << endl;

    return 0;
}
