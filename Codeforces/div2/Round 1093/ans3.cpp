//Grid L

#include <iostream>
using namespace std;

pair<int, int> solve(int p, int q) {
    int total = p + 2*q;
    if (total<4) return {-1, -1};
    int n = 1, m = 1; total-=4; 
    while (total>0) {
        if (n>1) total-=3;
        if (total%(2*n+1) == 0) {
            m = 1+(total/(2*n+1));
            return {n, m};
        } n++;
    } return {-1, -1};
}
int main() {
    int t; cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;
        pair<int, int> res = solve(p, q);
        if (res.first==-1) cout << -1 << endl;
        else cout << res.first << " " << res.second << endl;
    } return 0;
}