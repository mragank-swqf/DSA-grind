#include <iostream>
using namespace std;

const int N = 3e5;
string s1(N, 'a');
string s2(N, 'b');

string solve(string &s) {
    int n = s.size();
    string t1 = s1.substr(0, n);
    string t2 = s2.substr(0, n);
    int m1 = (s[0]!=t1[0]), m2 = (s[0]!=t2[0]);
    for (int i=1; i<n; i++) {
        if (s[i]!=t1[i] && s[i-1]==t1[i-1]) m1++;
        if (s[i]!=t2[i] && s[i-1]==t2[i-1]) m2++;
    } return (m1==1 || m2==1) ? "YES": "NO";
}
int main() {
    for (int i=1; i<N; i+=2) {
        s1[i]='b'; s2[i]='a';
    } int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    } return 0;
}