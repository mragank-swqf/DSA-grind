//POTD 08th June 2026
//2161: Partition Array According to Given Pivot
//Approach: Two pass with two stacks

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stack<int> st1, st2; int j = nums.size()-1; int temp = 0;
        for (int num:nums) {
            if (num<pivot) st1.push(num);
            else if (num>pivot) st2.push(num);
            else temp++;
        } while (!st2.empty() && j>=0) {nums[j]=st2.top(); st2.pop(); j--;}
        while (temp-- && j>=0) {nums[j]=pivot; j--;}
        while (!st1.empty() && j>=0) {nums[j]=st1.top(); st1.pop(); j--;}
        return nums;
    }
};