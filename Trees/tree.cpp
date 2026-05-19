//Morris Traversal Algorithm

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();
        if (i < nodes.size()) { curr->left  = new TreeNode(nodes[i++]); q.push(curr->left);  }
        if (i < nodes.size()) { curr->right = new TreeNode(nodes[i++]); q.push(curr->right); }
    }
    return root;
}

vector<int> getInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) { inorder.push_back(curr->val); curr = curr->right;}
        else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right!=curr) 
                prev = prev->right;
            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    } return inorder;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> nodes(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);
    vector<int> ino = getInorder(root);
    for (int x:ino) cout << x << " ";
    cout << endl;
    return 0;
}
