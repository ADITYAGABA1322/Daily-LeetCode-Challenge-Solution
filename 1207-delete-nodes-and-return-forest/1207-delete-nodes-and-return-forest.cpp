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
   vector<TreeNode*> res;
    TreeNode* removeNode(TreeNode*root  , unordered_set<int> &toDeleteSet ,  vector<TreeNode*>& res){
        if(root == NULL) return NULL;
        root->left = removeNode(root->left , toDeleteSet , res);
        root->right = removeNode(root->right , toDeleteSet , res);
        if(toDeleteSet.find(root->val) != toDeleteSet.end()){
            if(root->left != NULL) res.push_back(root->left);
            if(root->right != NULL) res.push_back(root->right);
            return NULL;  
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        root = removeNode(root , toDeleteSet , res);
        if(root != NULL) res.push_back(root);
        return res;
    }
};