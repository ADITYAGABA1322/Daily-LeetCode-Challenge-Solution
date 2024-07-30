/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node* , Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* clone = new Node(node->val);
        mp[node] = clone;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto nei : curr->neighbors){
                if(mp.find(nei) == mp.end()){
                    Node *clonenei = new Node(nei->val);
                    mp[nei] = clonenei;
                    q.push(nei);
                }
                mp[curr]->neighbors.push_back(mp[nei]);
            }
        }
        return clone;
    }
};