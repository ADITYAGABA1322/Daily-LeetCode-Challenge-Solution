class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
// Given an undirected tree with nodes and a 2D array `edges` of length n-1, where edges[i] = [ai, bi] represents an edge between nodes ai and bi.
// Also given an array `values` of length n, where values[i] is the value associated with the ith node, and an integer k.
// A valid split of the tree is obtained by removing edges such that the resulting components all have values divisible by k.
// The value of a connected component is the sum of the values of its nodes.
// Return the maximum number of components in a valid split.

// Approach:
// 1. We need to split the tree by performing operations to maximize the number of components where the sum of node values is divisible by k.
// 2. Use Depth-First Search (DFS) to traverse the tree and calculate the sum of node values for each component.
// 3. Initialize a graph using the given edges and traverse it using DFS.
// 4. Maintain a visited array to track visited nodes.
// 5. In the DFS helper function, calculate the sum of node values for each component.
// 6. If the sum is divisible by k, increment the component count.
// 7. Return the count of the maximum number of components in a valid split.

        vector<vector<int>> g(n);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n , false);
        int res = 0;

        function<long long(int)> dfs = [&](int node){
            vis[node] = true;
            long long sum = values[node];
            for(auto nei : g[node]){
                if(!vis[nei]){
                    sum += dfs(nei);
                }
            }
            if(sum%k == 0){
                res++;
                return 0LL;
            }
            return sum;
        };
        dfs(0);
        return res;
    }
};