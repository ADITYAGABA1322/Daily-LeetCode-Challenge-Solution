class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        // Initialize parent and rank arrays
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Find parent of node x. Use Path Compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        // Unite two nodes x and y, if they are not already united
        int px = find(x);
        int py = find(y);
        if (px != py) {
            // Union by Rank Heuristic
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        // Check if two nodes x and y are connected or not
        return find(x) == find(y);
    }

    void reset(int x) {
        // Reset the initial properties of node x
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // Sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        // Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }

        // Create graph
        UnionFind graph(n);
        graph.unite(firstPerson, 0);

        // Process in increasing order of time
        for (auto& [t, meetings] : sameTimeMeetings) {
            // Unite two persons taking part in a meeting
            for (auto& [x, y] : meetings) {
                graph.unite(x, y);
            }

            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for (auto& [x, y] : meetings) {
                if (!graph.connected(x, 0)) {
                    // No need to check for y since x and y were united
                    graph.reset(x);
                    graph.reset(y);
                }
            }
        }

        // Al those who are connected to 0 will know the secret
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (graph.connected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};