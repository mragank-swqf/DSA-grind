//Blocked

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int>& nums, int n) {
    sort(nums.begin(), nums.end());
    for (int i=1; i<n; i++) {
        if (nums[i]==nums[i-1]) return {-1};
    } sort(nums.begin(), nums.end(), greater<int>());
    return nums;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        vector<int> res = solve(arr, n);
        for (int a: res) cout << a << " ";
        cout << endl;
    }
    return 0;
}