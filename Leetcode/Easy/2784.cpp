//2784. Check if Array is Good

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n);
        for (int num:nums) {
            if (num>n-1) return false;
            freq[num]++;
            if (num==n-1 && freq[num]>2) return false;
            else if (num<n-1 && freq[num]>1) return false;
        } return true;
    }
};