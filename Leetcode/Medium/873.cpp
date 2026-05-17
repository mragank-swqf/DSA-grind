//873. Length of Longest Fibonacci Subsequence
//Approach: nested loop DP approach with hash set to search elements and map to store DP
//Time complexity: O(n^2)
//Space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end()); int n = arr.size();
        map<pair<int, int>, int> dp; int ans = 0;
        for (int i=2; i<n; i++) {
            for (int j=1; j<i; j++) {
                int diff = arr[i]-arr[j];
                if (diff<arr[j] && st.count(diff)) {
                    dp[{arr[j], arr[i]}] = dp[{diff, arr[j]}]+1;
                    ans = max(ans, dp[{arr[j], arr[i]}]+2);
                }
            }
        } return ans;
    }
};