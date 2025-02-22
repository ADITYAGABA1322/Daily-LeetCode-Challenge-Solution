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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0;
        while (i < traversal.size()) {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }
            int value = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(value);
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }
            if (!st.empty()) {
                if (!st.top().first->left) {
                    st.top().first->left = node;
                } else {
                    st.top().first->right = node;
                }
            }
            st.push({node, depth});
        }
        while (st.size() > 1) {
            st.pop();
        }
        return st.top().first;
    }
};