#include <iostream>
using namespace std;
using ll = long long;
string solve(ll x, ll y) {
    ll temp = x+x;
    while (temp<y) {
        if (y%temp != 0) return "YES";
        temp+=x;
    } return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    } return 0;
}