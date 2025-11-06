class DSU {
public:
    vector<int> parent;
    DSU(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void join(int u, int v) { parent[find(v)] = find(u); }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c + 1);

        for (auto& p : connections) {
            dsu.join(p[0], p[1]);
        }

        vector<bool> online(c + 1, true);
        vector<int> offlineCounts(c + 1, 0);
        unordered_map<int, int> minimumOnlineStations;

        for (auto& q : queries) {
            int op = q[0], x = q[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minimumOnlineStations.count(root)) {
                minimumOnlineStations[root] = -1;
            }

            int station = minimumOnlineStations[root];
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations[root] = i;
                }
            }
        }

        vector<int> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.find(x);
            int station = minimumOnlineStations[root];

            if (op == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    ans.push_back(station);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    online[x] = true;
                    if (station == -1 || station > x) {
                        minimumOnlineStations[root] = x;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};