//2415. Reverse Odd Levels of Binary Search Tree
#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root); int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> currentlvl;
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front(); q.pop();
                currentlvl.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } if (lvl%2 == 1) {
                int left = 0, right = currentlvl.size()-1;
                while (left<right) {
                    int temp = currentlvl[left]->val;
                    currentlvl[left]->val = currentlvl[right]->val;
                    currentlvl[right]->val = temp; 
                    left++; right--;
                } 
            } lvl++;
        } return root;
    }
};