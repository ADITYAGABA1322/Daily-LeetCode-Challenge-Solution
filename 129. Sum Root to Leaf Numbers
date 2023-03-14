129. Sum Root to Leaf Numbers



14 March 2023


Medium



C++:



// Time Complexity : O(n) where n is the number of nodes in the tree and space complexity is O(h) where h is the height of the tree



class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL){  // if the root is null
            return 0;  // return 0
        }
        return helper(root, 0);  // return the result
    }
    int helper(TreeNode* root, int sum){  // function to calculate the sum of all the root to leaf paths
        if(root == NULL){  // if the root is null
            return 0;  // return 0
        }
        if(root->left == NULL && root->right == NULL){  // if both the nodes are null
            return sum * 10 + root->val;  // return the sum
        }
        return helper(root->left, sum * 10 + root->val) + helper(root->right, sum * 10 + root->val);  // return the result
    }
};




Java:



// Time Complexity : O(n) where n is the number of nodes in the tree and space complexity is O(h) where h is the height of the tree





class Solution {
    public int sumNumbers(TreeNode root) {
        if(root == null){  // if the root is null
            return 0;  // return 0
        }
        return helper(root, 0);  // return the result
    }
    public int helper(TreeNode root, int sum){  // function to calculate the sum of all the root to leaf paths
        if(root == null){  // if the root is null
            return 0;  // return 0
        }
        if(root.left == null && root.right == null){  // if both the nodes are null
            return sum * 10 + root.val;  // return the sum
        }
        return helper(root.left, sum * 10 + root.val) + helper(root.right, sum * 10 + root.val);  // return the result
    }
}
