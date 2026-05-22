//1802. Maximum Value at a Given Index in a Bounded Array
//Algorithm: Binary Search
//Time Complexity: O(logn)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll cal_sum(ll x, ll index, ll n) {
        ll left_count = index + 1;
        ll left = (x >= left_count) 
            ? (x * left_count - (left_count*(left_count-1))/2)  
            : (x*(x+1))/2 + (left_count - x);                  

        ll right_count = n - index;
        ll right = (x >= right_count)
            ? (x * right_count - (right_count*(right_count-1))/2)
            : (x*(x+1))/2 + (right_count - x);

        return left + right - x;
    }
    ll maxValue(ll n, ll index, ll maxSum) {
        ll x = 1;
        ll start=1; ll end = maxSum;
        while (start<end) {
            ll mid = start+(end-start+1)/2;
            if (cal_sum(mid, index, n)<=maxSum) start=mid;
            else end = mid-1;
        }return start;
    }
};