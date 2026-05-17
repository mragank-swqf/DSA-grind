//154. Search in Rotated Sorted Array -II
//Approach: Binary Search
//Time complexity: O(logn); Memory: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while (start<end) {
            int mid = start + (end-start)/2;
            if(nums[mid]>nums[end]) start = mid+1;
            else if (nums[mid]==nums[end]) end--;
            else end = mid;
        } return nums[start];
    }
};