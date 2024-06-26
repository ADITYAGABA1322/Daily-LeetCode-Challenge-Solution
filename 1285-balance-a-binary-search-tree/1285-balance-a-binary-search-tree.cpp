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
#include <vector>

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> elements;
        inOrderTraversal(root, elements); // Step 1: Perform in-order traversal to get sorted elements
        return constructBalancedBST(elements, 0, elements.size() - 1); // Step 2: Reconstruct the BST
    }

private:
    void inOrderTraversal(TreeNode* node, std::vector<int>& elements) {
        if (node == NULL) return;
        inOrderTraversal(node->left, elements);
        elements.push_back(node->val);
        inOrderTraversal(node->right, elements);
    }

    TreeNode* constructBalancedBST(const std::vector<int>& elements, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = constructBalancedBST(elements, start, mid - 1);
        node->right = constructBalancedBST(elements, mid + 1, end);
        return node;
    }
};