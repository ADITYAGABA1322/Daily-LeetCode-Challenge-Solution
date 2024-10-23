/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        int previousLevelSum = root->val;
        while (!q.empty()) {
            int levelSize = q.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                // Update the current node's value to the "cousin sum"
                int originalValue = currentNode->val;
                currentNode->val = previousLevelSum - originalValue;

                // Calculate the "sibling sum"
                int siblingSum = 0;
                if (currentNode->left)
                    siblingSum += currentNode->left->val;
                if (currentNode->right)
                    siblingSum += currentNode->right->val;

                // Process the left child
                if (currentNode->left) {
                    currentLevelSum += currentNode->left->val;
                    currentNode->left->val = siblingSum;
                    q.push(currentNode->left);
                }

                // Process the right child
                if (currentNode->right) {
                    currentLevelSum += currentNode->right->val;
                    currentNode->right->val = siblingSum;
                    q.push(currentNode->right);
                }
            }

            // Update previousLevelSum to the sum of the current level's values
            previousLevelSum = currentLevelSum;
        }

        return root;
    }
};