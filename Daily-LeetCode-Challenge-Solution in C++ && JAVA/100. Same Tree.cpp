# Daily-LeetCode-Challenge-Solution


10 Jan 2023
    

    

Easy

    
    
C++:




Same tree in c++ best solution  // time complexity O(N) and space complexity O(N)




class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {     // p is the root of the first binary tree and q is the root of the second binary tree
        if(p==NULL && q==NULL) return true;      // if both the trees are null then return true
        if(p==NULL || q==NULL) return false;     // if one of the trees is null and the other is not null then return false
        if(p->val!=q->val) return false;        // if the value of the root of the first tree is not equal to the value of the root of the second tree then return false
        bool left = isSameTree(p->left,q->left);        // left is true if the left subtree of the first tree is equal to the left subtree of the second tree and false otherwise
        bool right = isSameTree(p->right,q->right);     // right is true if the right subtree of the first tree is equal to the right subtree of the second tree and false otherwise
        return left && right;       // return left && right
    }
};


Java:

Same tree in java best solution  // time complexity O(N) and space complexity O(N)
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {     // p is the root of the first binary tree and q is the root of the second binary tree
        if(p==null && q==null) return true;      // if both the trees are null then return true
        if(p==null || q==null) return false;     // if one of the trees is null and the other is not null then return false
        if(p.val!=q.val) return false;      // if the value of the root of the first tree is not equal to the value of the root of the second tree then return false
        boolean left = isSameTree(p.left,q.left);        // left is true if the left subtree of the first tree is equal to the left subtree of the second tree and false otherwise
        boolean right = isSameTree(p.right,q.right);     // right is true if the right subtree of the first tree is equal to the right subtree of the second tree and false otherwise
        return left && right;       // return left && right
    }
};
