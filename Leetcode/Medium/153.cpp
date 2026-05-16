//Leetcode Problem of the Day 15th May 2026: Search in Rotated Sorted Array
//Approach: Binary Search; Time Complexity: O(logn)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while (start<end) {
            int mid = start + (end-start)/2;
            if (nums[mid]>nums[end]) start = mid+1;
            else end = mid;
        } return nums[start];
    }
};