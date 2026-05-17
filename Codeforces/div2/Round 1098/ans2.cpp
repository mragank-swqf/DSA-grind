#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(long long n, long long x1, long long x2, long long k) {
    if (n<=3) return 1;
    int d = min(abs(x1-x2), n-abs(x1-x2));
    return d+k;
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            long long n, x1, x2, k;
            cin >> n >> x1 >> x2 >> k;
            cout << solve(n, x1, x2, k) << "\n"; // Avoid endl for faster performance
        }
    }
    return 0;
}