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
    int minimumOperations(TreeNode* root) {
        // the question is simple root unique val ok return min no of op need to make the val at each level sorted in str inc order lev of node no of edges along path b.w is and root node we leve; order iusing bfs is good option in that we level by and chek how much op to make it sort by ising inbui;d fimciton swap ok and return it  and just start using queue and traverse and check it ok 
        if(!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> lvl;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res += cntSort(lvl);
        }
        return res;
    }

    int cntSort(vector<int>& arr){
        int n = arr.size();
        vector<pair<int , int>> arrPos(n);
        for(int i=0;i<n; i++) arrPos[i] = {arr[i] , i};
        sort(arrPos.begin() , arrPos.end());
        vector<bool> vis(n , false);
        int swaps = 0;
        for(int i=0; i<n; i++){
            if(vis[i] || arrPos[i].second == i) continue;
            int cycle = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = arrPos[j].second;
                cycle++;
            }
            if(cycle > 0) swaps += (cycle - 1);
        }
        return swaps;
    }
};