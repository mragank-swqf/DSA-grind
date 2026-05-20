#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int ans = 0; int ones = 0;
    for (int x:nums) {
        if (x==1) {ones++; continue; }
        ones = 0; ans += x;
    } ans += ones>0;
    return ans;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        cout << solve(arr) << endl;
    } return 0;
}