#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> arr, int n) {
    int zeros = 0; int ones = 0, twos = 0;
    for (int x: arr) {
        if (x==0) zeros++;
        else if (x==1) ones++;
        else twos++;
    } int ans = zeros+ min(ones, twos);
    ones = ones-min(ones, twos);
    ans += (ones>0) ? ones/3:0;
    twos = twos-min(ones, twos);
    ans += (twos>0) ? twos/3:0;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << solve(arr, n) << endl;;
    }
    return 0;
}