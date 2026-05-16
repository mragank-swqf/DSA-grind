//Leetcode 814: Binary Tree pruning
//Approach: Depth First Search

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
    int sum(TreeNode* root) {
        if (root==nullptr) return 0;
        auto lft = sum(root->left); auto rgt = sum(root->right);
        if (lft==0) root->left = nullptr;
        if (rgt==0) root->right = nullptr;
        return root->val + lft + rgt;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int sm = sum(root);
        if (root->val==0 && !root->left && !root->right) return nullptr;
        return root;
    }
};