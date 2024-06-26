typedef long long ll;
typedef pair<ll, ll> P;
class Solution {
public:
    vector<int> dijkstra(unordered_map<int, vector<P>>& g, int src, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        dist[src] = 0;
        pq.push({0 , src});
        while (!pq.empty()) {
            int currN = pq.top().second;
            ll currW = pq.top().first;
            pq.pop();
            if(vis[currN] == true) continue;
            for (auto child : g[currN]) {
                int nextN = child.first;
                ll nextW = child.second;
                if (dist[nextN] > currW + nextW) {
                    dist[nextN] = currW + nextW;
                    pq.push({dist[nextN], nextN}); 
                }
            }
            vis[currN] = true;
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> g;
        for (auto edge : edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> fromS = dijkstra(g, 0, n);
        vector<int> fromD = dijkstra(g, n - 1, n);
        vector<bool> res(edges.size(), false);
        for (int i = 0; i < edges.size(); ++i) {
            auto& edge = edges[i];
            ll distFromS = fromS[edge[0]];
            ll distFromD = fromD[edge[1]];
            if (distFromS + edge[2] + distFromD == fromS[n - 1]) res[i] = true;
            distFromS = fromS[edge[1]];
            distFromD = fromD[edge[0]];
            if (distFromS + edge[2] + distFromD == fromS[n - 1]) res[i] = true;
        }
        return res;
    }
};