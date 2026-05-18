#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int d) {
    int h = 1+d/m;
    int ans = (n/h) + (n%h>0);
    return ans; 
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        cout << solve(n, m, d) << endl;
    } return 0;
}