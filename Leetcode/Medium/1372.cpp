//Problem 1372: Longest ZigZag Path in a Binary Tree
//Approach: DP + Depth First Search

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
    int ans = 0;
    int solve(TreeNode* root, int right) {
        if (!root) return 0;
        auto left = solve(root->left, 0); auto rght = solve(root->right, 1);
        if (right) {
            ans = max(1+left, ans);
            return 1+left;
        } ans = max(1+rght, ans);
        return 1+rght;
    }
    int longestZigZag(TreeNode* root) {
        auto left = solve(root->left, 0);
        auto rght = solve(root->right, 1);
        return ans;
    }
};