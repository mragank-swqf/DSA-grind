#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
    vector<int> res(n);
    for (int i=0; i<n; i++) {
        res[i] = 2*i+1;
    } return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> res = solve(n);
        for (int i=0; i<n; i++) cout << res[i] << " ";
        cout << endl;
    } return 0;
}