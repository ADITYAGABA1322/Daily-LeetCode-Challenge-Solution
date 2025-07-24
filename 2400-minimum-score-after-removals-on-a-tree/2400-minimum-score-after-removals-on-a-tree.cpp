// class Solution {
// public:
//     int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//         Hi, in today's problem when I am analyzed this problem, the approach which is coming on by analyzing this problem is that they are given the edges and the numbs according to the edges and no it's perfectly aligned to the graph and in the graph there is a possibility of using the TFS or FS which we know how to use that but there is a concept of a Zorro operator according to the Zo operator we want to select that n which edge have a max weight and which edge have a mean weight like a component only and we won't get a difference of that like if we break down the steps first you trade the edges over the numbs using DFS for second step find the largest component means first component, and according to that more component and take the max and mean, but before that use the Zorro operator, we need to create a function for that or using in build function for that after that we get a minimum score after removal on a tree that's a basic approach
//     }
// };

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> xorSubtree(n), in(n), out(n), parent(n, -1);
        int time = 0;

        // DFS to compute subtree XORs and in/out times for ancestor checks
        function<void(int, int)> dfs = [&](int u, int p) {
            xorSubtree[u] = nums[u];
            in[u] = time++;
            for (int v : tree[u]) {
                if (v == p) continue;
                parent[v] = u;
                dfs(v, u);
                xorSubtree[u] ^= xorSubtree[v];
            }
            out[u] = time++;
        };
        dfs(0, -1);

        // Helper to check if u is ancestor of v
        auto isAncestor = [&](int u, int v) {
            return in[u] <= in[v] && out[v] <= out[u];
        };

        int res = INT_MAX;
        // Try all pairs of edges (represented by their child nodes)
        vector<pair<int,int>> candidates;
        for (int i = 1; i < n; ++i) {
            candidates.push_back({i, parent[i]});
        }
        int totalXor = xorSubtree[0];
        for (int i = 0; i < candidates.size(); ++i) {
            int a = candidates[i].first;
            for (int j = i+1; j < candidates.size(); ++j) {
                int b = candidates[j].first;
                int x = 0, y = 0, z = 0;
                if (isAncestor(a, b)) {
                    x = xorSubtree[b];
                    y = xorSubtree[a] ^ xorSubtree[b];
                    z = totalXor ^ xorSubtree[a];
                } else if (isAncestor(b, a)) {
                    x = xorSubtree[a];
                    y = xorSubtree[b] ^ xorSubtree[a];
                    z = totalXor ^ xorSubtree[b];
                } else {
                    x = xorSubtree[a];
                    y = xorSubtree[b];
                    z = totalXor ^ xorSubtree[a] ^ xorSubtree[b];
                }
                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
};