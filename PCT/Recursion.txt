#include<bits/stdc++.h>

using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}

int series(int n) {
    if (n == 0)
        return 0;
    return n*n*n*n*n + series(n-1);
}

int findMinimum(int arr[], int n) {
    if (n == 1)
        return arr[n-1];
    int x = findMinimum(arr, n-1);
    int y = arr[n-1];
    return x < y? x: y;
}

bool checkPalindrome(string s, int start, int end) {
    if (start == end or start > end)
        return true;
    return s[start] == s[end] and checkPalindrome(s, start+1, end-1);
}

int combination(int n, int r) {
    if (r == 0 or r == n)
        return 1;
    return combination(n-1, r-1) + combination(n-1, r);
}

int exponentiation(int b, int e) {
    if (e == 0)
        return 1;
    return b * exponentiation(b, e-1);
} // O(e)

int fastExp(int b, int e) {
    if (e == 0)
        return 1;
    int prod = fastExp(b, e/2);
    if (e%2 == 0)
        return prod*prod;
    return prod*prod*b;
} // O(log(e))

int main() {
    // int n;
    // cin >> n;
    // cout << series(5) << endl;
    // int arr[] = {0, -1, 1, 2, 3, 3, 0, 8, 5, 5};
    // cout << findMinimum(arr, 10) << endl;
    // string s;
    // cin >> s;
    // cout << checkPalindrome(s, 0, s.length()-1) <<endl;
    // int n, r;
    // cin >> n >> r;
    // cout << combination(n, r) << endl;
    int b, e;
    cin >> b >> e;
    cout << fastExp(b, e) << endl;
    return 0;
}
