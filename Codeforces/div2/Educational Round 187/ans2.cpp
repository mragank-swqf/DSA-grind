#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x) {
    string s = to_string(x);
    ll current_sum = 0;
    for (char c : s) {
        current_sum += (c - '0');
    }

    // If it's already beautiful, no moves needed
    if (current_sum <= 9) {
        return 0;
    }

    // Gather the maximum reduction possible for each position
    vector<int> reductions;
    
    // First digit can only drop to 1 (to avoid leading zero)
    reductions.push_back((s[0] - '0') - 1);
    
    // Other digits can drop all the way to 0
    for (size_t i = 1; i < s.size(); i++) {
        reductions.push_back(s[i] - '0');
    }

    // Sort reductions in descending order to be greedy
    sort(reductions.rbegin(), reductions.rend());

    ll moves = 0;
    for (int reduction : reductions) {
        current_sum -= reduction;
        moves++;
        if (current_sum <= 9) {
            break;
        }
    }

    return moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while (t--) {
        ll x; 
        cin >> x;
        cout << solve(x) << "\n";
    } 
    return 0;
}