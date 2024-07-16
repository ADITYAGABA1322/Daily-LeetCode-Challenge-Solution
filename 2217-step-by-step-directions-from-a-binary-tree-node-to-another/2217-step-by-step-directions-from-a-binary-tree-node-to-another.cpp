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
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) return root;
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if (left && right) return root;
        return left ? left : right;
    }

    bool generatePath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        path.push_back('L');
        if (generatePath(root->left, value, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (generatePath(root->right, value, path)) return true;
        path.pop_back();
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        string pathToStart, pathToDest;
        generatePath(lca, startValue, pathToStart);
        generatePath(lca, destValue, pathToDest);
        
        for (char& c : pathToStart) c = 'U'; // Convert path to start into 'U's
        return pathToStart + pathToDest;
    }
};