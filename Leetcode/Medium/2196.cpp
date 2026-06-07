//Problem of the day: 8th June
//2196: Create binary tree from descriptions
//Approach: Two pass solution with a  hash table and a hash set

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> isChild; unordered_map<int, TreeNode*> mp;
        for (const auto& desc:descriptions) {
            int p = desc[0], c = desc[1];
            if (!mp.count(p)) mp[p] = new TreeNode(p);
            if (!mp.count(c)) mp[c] = new TreeNode(c);
            if (desc[2]==1) mp[p]->left = mp[c];
            else mp[p]->right = mp[c];
            isChild.insert(c);
        } for (const auto& desc:descriptions) {
            if (!isChild.count(desc[0])) return mp[desc[0]];
        } return nullptr;
    }
};