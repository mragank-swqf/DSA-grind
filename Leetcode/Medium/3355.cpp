//3355: Zero Array Transformations I
//Approach: Difference Array
//Time complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); vector<int> diff(n+1);
        for (auto &query:queries) {diff[query[0]] += 1; diff[query[1]+1] -= 1;}
        int dec = 0;
        for (int i=0; i<n; i++) {
            dec += diff[i];
            if (nums[i]-dec>0) return false;
        } return true;
    }
};