#include <iostream>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    long long MOD = 998294353;
    
    long long fn = (n + 1) / 4;
    long long gn = (n + 3) / 4;
    long long fx = x / 4;
    long long gx = (x + 2) / 4;
    
    fn++;
    fx++;
    
    long long ans = ((fx % MOD) * ((fn - fx) % MOD)) % MOD;
    ans = (ans + ((gx % MOD) * ((gn - gx) % MOD)) % MOD) % MOD;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}