104. Maximum Depth of Binary Tree



    
16 Feb 2023

    

    

Easy

    
    

C++:

// Time Complexity : O(n) where n is the length of the string and space complexity is O(n)


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;   // if condition is true
        return 1 + max(maxDepth(root->left), maxDepth(root->right));   // return 1+max(maxDepth(root->left),maxDepth(root->right))
    }
};



Java:


// Time Complexity : O(n) where n is the length of the string and space complexity is O(n)


class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;   // if condition is true
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));   // return 1+Math.max(maxDepth(root.left),maxDepth(root.right))
    }
};
