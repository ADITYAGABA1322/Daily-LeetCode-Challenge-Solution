class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int , int >>> g(n);
        for(auto e: edges){
            g[e[0]].push_back({e[1] , e[2]});
        }
        vector dis(n, vector<long long>(k + 1, INT_MAX));
        priority_queue<tuple<long long ,int , int> , vector<tuple<long long , int , int>> , greater<>> pq;
        dis[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d , u , run] = pq.top();
            pq.pop();
            if(d > dis[u][run]) continue;
            if(u == n-1) return d;
            for(auto [v,w]  : g[u]){
                int new_run = labels[v] == labels[u] ? run + 1 : 1;
                if(new_run > k)  continue;
                long long nd = d + w;
                if(nd < dis[v][new_run]){
                    dis[v][new_run] = nd;
                    pq.push({nd , v , new_run});
                }
            }
        } 
        return -1;
    }
};