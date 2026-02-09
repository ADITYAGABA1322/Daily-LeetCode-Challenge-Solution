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
    TreeNode* balanceBST(TreeNode* root) {
       vector<int> ans;
       inOrderTraversal(root , ans);
       return constructBalancedBST(ans , 0 , ans.size() - 1);
    }
private:
    void inOrderTraversal(TreeNode* node , vector<int>& ans){
        if(node == NULL) return;
        inOrderTraversal(node->left , ans);
        ans.push_back(node->val);
        inOrderTraversal(node->right , ans);
    }

    TreeNode* constructBalancedBST(vector<int>& ans , int start , int end){
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(ans[mid]);
        node->left = constructBalancedBST(ans , start , mid - 1);
        node->right = constructBalancedBST(ans , mid+1 , end);
        return node;
    }
};