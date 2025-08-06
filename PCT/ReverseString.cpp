#include <iostream>
using namespace std;

// Recursive function to reverse a string in-place
void reverseString(string &s, int left, int right) {
    if (left >= right)
        return;

    // Swap characters at left and right positions
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    // Recursive call
    reverseString(s, left + 1, right - 1);
}

int main() {
    string s;
    cin >> s;

    reverseString(s, 0, s.length() - 1);

    // Print the reversed string
    cout << s << endl;

    return 0;
}

