using ll = long long;
#include <bits/stdc++.h>
using namespace std;

vector<ll> solve(vector<ll>& nums, ll n) {
    ll ans = INT_MAX; ll sm = 0; ll temp; ll mn = 1e9;
    for (ll i=0; i<n; i++) {
        sm += nums[i];
        temp = sm/(i+1);
        nums[i] = min(mn, temp);
        mn = min(mn, nums[i]);
    } return nums;
}

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for (ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> res = solve(arr, n);
        for (ll i=0; i<n; i++) cout << res[i] << " ";
        cout << endl;
    } return 0;
}