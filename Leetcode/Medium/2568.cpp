//2568: Minimum possible OR
//Approach: unordered set+linear search
//Time complexity: O(logn)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end()); int p=0;
        while (s.count(1<<p)) p++;
        return (1<<p);
    }
};