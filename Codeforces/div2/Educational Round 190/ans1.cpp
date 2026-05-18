#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    // Calculate how many full groups of 3 we can make
    long long full_groups = n / 3;
    long long remainder = n % 3;

    // Cost for the full groups of 3
    long long cost = full_groups * min(3 * a, b);

    // Cost for the remaining students
    if (remainder == 1) {
        cost += min(a, b);
    } else if (remainder == 2) {
        cost += min(2 * a, b);
    }

    cout << cost << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}