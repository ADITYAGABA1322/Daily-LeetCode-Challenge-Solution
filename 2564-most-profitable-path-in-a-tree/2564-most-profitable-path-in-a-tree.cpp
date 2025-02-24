class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        n = amount.size();
        g.resize(n, vector<int>());
        for (vector<int> e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        disBob.resize(n);
        return dfs(0, 0, 0, bob, amount);
    }

private:
    int n;
    vector<int> disBob;
    vector<vector<int>> g;

    int dfs(int node, int parent, int time, int bob, vector<int>& amount) {
        int maxInc = 0, maxChild = INT_MIN;
        if (node == bob)
            disBob[node] = 0;
        else
            disBob[node] = n;
        for (auto nei : g[node]) {
            if (nei != parent) {
                maxChild = max(maxChild, dfs(nei, node, time + 1, bob, amount));
                disBob[node] = min(disBob[node], disBob[nei] + 1);
            }
        }
        if (disBob[node] > time)
            maxInc += amount[node];
        else if (disBob[node] == time)
            maxInc += amount[node] / 2;
        if (maxChild == INT_MIN)
            return maxInc;
        else
            return maxInc + maxChild;
    }
};