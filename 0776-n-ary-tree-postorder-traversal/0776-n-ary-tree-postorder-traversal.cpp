/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        traversePostorder(root, result);
        return result;
    }

private:
    void traversePostorder(Node* currentNode, vector<int>& postorderList) {
        if (currentNode == nullptr) {
            return;
        }

        // First, visit all children
        for (Node* childNode : currentNode->children) {
            traversePostorder(childNode, postorderList);
        }

        // Then, add the current node's value
        postorderList.push_back(currentNode->val);
    }
};