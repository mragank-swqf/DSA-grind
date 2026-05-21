#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
    int ans = 0;
    for (int i=1; i<n; i++) {
        int mn = min(arr[i], arr[i-1]);
        int mx = max(arr[i], arr[i-1]);
        ans += (mx%(mx-mn) == 0);
    } return ans;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        cout << solve(arr, n) << endl;
    } return 0;
}