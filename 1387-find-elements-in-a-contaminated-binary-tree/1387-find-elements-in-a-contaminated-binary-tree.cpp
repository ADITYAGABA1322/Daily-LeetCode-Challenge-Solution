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
class FindElements {
public:
    // use hashset to find the target or treenode.val ok and using dfs to iterate in the tree Approach what i think in outer varivble or in private function take hashset ok and for dfs we use recursive function how it does not means we create any funciton we use the fuciton in recursive call in left and right tree but how like we check this condition root.val == 0
// For any treeNode:
// If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2  and after running this in dfs awe get and in find elelments we create a tree like we first create a tree and then fillw the condition and check in the bool target if it is or not simple ok
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        if(root) recover(root , 0);
    }
    void recover(TreeNode* node , int val){
        if(!node) return;
        node->val = val;
        st.insert(val);
        if(node->left){
            recover(node->left  , 2*val+1);
        }
        if(node->right){
            recover(node->right , 2*val +2);
        }
    }
    bool find(int target) {
        return st.find(target) != st.end();   
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */