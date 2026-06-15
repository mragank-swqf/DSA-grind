//1768. Merge Strings Alternately
//Approach: Single pass O(n) 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size(); string res = "";
        int mx = max(m, n);
        for (int i=0; i<mx; i++) {
            if (i<m) res += word1[i];
            if (i<n) res += word2[i];
        } return res;
    }
};