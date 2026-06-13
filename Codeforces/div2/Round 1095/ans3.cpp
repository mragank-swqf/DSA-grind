#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
    vector<int> res(n, 0); int ans = 0;
    for (int x:arr) 
        res[x%n]++;
    int supply = 0; int need = 0;
    for (int i=0; i<n; i++) {
        if (res[i]==0) { need++; ans = i;} 
        else if (res[i]>1) {supply = (res[i]-1);}
    }
}