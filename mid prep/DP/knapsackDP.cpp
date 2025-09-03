
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
const int MAXW = 1000;

int n, W;
int weight[MAXN], value[MAXN];
int dp[MAXN+1][MAXW+1];

int knapsack() {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i-1] <= w) {
                dp[i][w] = max(
                    dp[i-1][w],
                    value[i-1] + dp[i-1][w - weight[i-1]]
                );
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

void findChosenItems() {
    int w = W;
    vector<int> chosen;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            chosen.push_back(i-1);
            w -= weight[i-1];
        }
    }

    cout << "Chosen items (0-indexed): ";
    for (int i = chosen.size() - 1; i >= 0; i--) {
        cout << chosen[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> weight[i];
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> value[i];

    int ans = knapsack();
    cout << "Maximum value in Knapsack = " << ans << endl;

    findChosenItems();

    return 0;
}
