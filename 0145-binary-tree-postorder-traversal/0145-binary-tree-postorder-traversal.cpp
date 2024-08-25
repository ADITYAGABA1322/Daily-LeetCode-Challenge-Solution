/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& res) {
        if (node == NULL) return;
        postorderHelper(node->left, res);  // Traverse left subtree
        postorderHelper(node->right, res); // Traverse right subtree
        res.push_back(node->val);          // Visit root node
    }
};