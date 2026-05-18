#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int dp0 = 0; // Max length of subsequence containing only '2's
    int dp1 = 0; // Max length of subsequence with '2's followed by '1's/'3's
    
    for (char c : s) {
        if (c == '2') {
            dp0++;
        } else if (c == '1' || c == '3') {
            dp1 = max(dp1, dp0) + 1;
        }
        // '4' is ignored because it cannot be in a beautiful subsequence
    }
    
    int longest_beautiful = max(dp0, dp1);
    int min_deletions = s.length() - longest_beautiful;
    
    cout << min_deletions << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}