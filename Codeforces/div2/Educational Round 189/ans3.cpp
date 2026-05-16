#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    // dp[i] stores the minimum repaints for the first i columns
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0; // Base case: 0 columns cost 0

    for (int i = 1; i <= n; ++i) {
        // Option 1: Place a vertical domino at column i
        // Cost is 1 if they are different, 0 if they are the same
        int v_cost = (s1[i - 1] == s2[i - 1]) ? 0 : 1;
        dp[i] = min(dp[i], dp[i - 1] + v_cost);

        // Option 2: Place two horizontal dominoes covering columns i-1 and i
        if (i >= 2) {
            int h_cost_top = (s1[i - 2] == s1[i - 1]) ? 0 : 1;
            int h_cost_bot = (s2[i - 2] == s2[i - 1]) ? 0 : 1;
            dp[i] = min(dp[i], dp[i - 2] + h_cost_top + h_cost_bot);
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}