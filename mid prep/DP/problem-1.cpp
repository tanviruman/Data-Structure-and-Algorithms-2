#include <bits/stdc++.h>
using namespace std;

const int MAX = 3005;   // as per constraints

// Map from first language word → chosen shorter word
unordered_map<string, string> dictMap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;   // n = number of lecture words, m = number of word pairs

    // Read m pairs (a[i], b[i]) and decide which one to use
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        // If first language word is shorter or equal, keep a
        // Else, keep b
        if (a.size() <= b.size())
            dictMap[a] = a;
        else
            dictMap[a] = b;
    }

    // Read lecture text (n words, all from first language)
    vector<string> lecture(n);
    for (int i = 0; i < n; i++) {
        cin >> lecture[i];
    }

    // Output transformed lecture
    for (int i = 0; i < n; i++) {
        cout << dictMap[lecture[i]];
        if (i != n-1) cout << " ";
    }
    cout << "\n";

    return 0;
}

