class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for(int i=0; i<n-1; i++) g[i].push_back(i+1);
        auto bfs = [&](int st , int end){
            vector<int> dist(n , INT_MAX);
            queue<int> q;
            dist[st] = 0;
            q.push(st);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : g[u]){
                    if(dist[u] + 1 < dist[v]){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                
            }
            return dist[end];
        };
        vector<int> res;
        for(auto q : queries){
            int u = q[0];
            int v = q[1];
            g[u].push_back(v);
            res.push_back(bfs(0 , n-1));
        }
        return res;
    }
};