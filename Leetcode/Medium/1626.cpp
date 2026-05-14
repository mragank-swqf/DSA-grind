//1626. Best Teams with No Conflicts

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(); vector<pair<int, int>> combined(n);
        for (int i=0; i<n; i++) combined[i] = {ages[i], scores[i]};
        sort(combined.begin(), combined.end());
        vector<int> dp(n); dp[0] = combined[0].second;
        for (int i=0; i<n; i++) {
            dp[i] = combined[i].second;
            for (int j=0; j<i; j++) 
                if (combined[j].second<=combined[i].second) dp[i] = max(dp[i], combined[i].second+dp[j]);
        } int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};