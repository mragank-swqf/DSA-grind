#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    int mid1, mid2; int ans = 0;
    if (n%2!=0) {mid1 = n/2; mid2 = n/2;}
    else if (n%2==0) {mid1 = (n-1)/2; mid2 = (n+1)/2;}
    int i=0, j = n-1;
    while (i<=mid1 && j>=mid2) {
        ans += (arr[i]!=arr[j]); i++; j--;
    } return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i=0; i<n; i++) cin >> nums[i];
        cout << solve(nums, n) << endl;
    } return 0;
}