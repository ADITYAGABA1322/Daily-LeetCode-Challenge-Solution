101. Symmetric Tree
    
    
    

    
13 March 2023

    
    
    
Easy
    


C++:


// Time Complexity : O(n) where n is the number of nodes in the tree and space complexity is O(h) where h is the height of the tree





class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){  // if the root is null
            return true;  // return true
        }
        return helper(root->left, root->right);  // return the result
    }
    bool helper(TreeNode* left, TreeNode* right){  // function to check if the tree is symmetric
        if(left == NULL && right == NULL){  // if both the nodes are null
            return true;  // return true
        }
        if(left == NULL || right == NULL){  // if one of the nodes is null
            return false;  // return false
        }
        if(left->val != right->val){  // if the values are not equal
            return false;  // return false
        }
        return helper(left->left, right->right) && helper(left->right, right->left);  // return the result
    }
};




Java:


// Time Complexity : O(n) where n is the number of nodes in the tree and space complexity is O(h) where h is the height of the tree





class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null){  // if the root is null
            return true;  // return true
        }
        return helper(root.left, root.right);  // return the result
    }
    public boolean helper(TreeNode left, TreeNode right){  // function to check if the tree is symmetric
        if(left == null && right == null){  // if both the nodes are null
            return true;  // return true
        }
        if(left == null || right == null){  // if one of the nodes is null
            return false;  // return false
        }
        if(left.val != right.val){  // if the values are not equal
            return false;  // return false
        }
        return helper(left.left, right.right) && helper(left.right, right.left);  // return the result
    }
}   
