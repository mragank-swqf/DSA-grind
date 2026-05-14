//OIE Excursion

#include <iostream>
#include <vector>
using namespace std;

string solve(int n, int m, vector<int>& nums) {
    int mx_cons = 0; int cons = 1;
    for (int i=1; i<n; i++) {
        if (nums[i]==nums[i-1]) {
            cons++;
            mx_cons = max(mx_cons, cons);
            if (mx_cons>=m) return "NO";
        } else if (nums[i]!=nums[i-1]) cons = 1;
    } return "YES";
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        cout << solve(n, m, arr) << endl;
    } return 0;
}