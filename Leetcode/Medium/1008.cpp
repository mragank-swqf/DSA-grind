//1008. Construct Binary Search Tree from Preorder Traversal
//Approach: Stack+single pass
//Time complexity: O(n^2) {Worst case}
//Space complexity: O(n) {Worst case}

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st; int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for (int i=1; i<n; i++) {
            TreeNode* curr = new TreeNode(preorder[i]); TreeNode* tp = st.top();
            if (preorder[i]<tp->val) tp->left = curr;
            else if (preorder[i]>tp->val) {
                TreeNode* parent = nullptr;
                while (!st.empty() && st.top()->val<preorder[i]) {
                    parent = st.top(); st.pop();
                } parent->right = curr;
            } st.push(curr);
        } return root;
    }
};