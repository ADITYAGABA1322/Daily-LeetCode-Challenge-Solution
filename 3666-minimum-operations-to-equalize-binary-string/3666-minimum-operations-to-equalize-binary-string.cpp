class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size(), m = 0;
        vector<int> dist(n + 1, INT_MAX);
        vector<set<int>> nodeSets(2);
        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].insert(i);
            if (i < n && s[i] == '0') {
                m++;
            }
        }
        queue<int> q;
        q.push(m);
        dist[m] = 0;
        nodeSets[m % 2].erase(m);
        while (!q.empty()) {
            m = q.front();
            q.pop();
            int c1 = max(k - n + m, 0), c2 = min(m, k);
            int lnode = m + k - 2 * c2, rnode = m + k - 2 * c1;
            auto& nodeSet = nodeSets[lnode % 2];
            for (auto iter = nodeSet.lower_bound(lnode);
                 iter != nodeSet.end() && *iter <= rnode;) {
                int m2 = *iter;
                dist[m2] = dist[m] + 1;
                q.push(m2);
                iter = next(iter);
                nodeSet.erase(m2);
            }
        }
        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};