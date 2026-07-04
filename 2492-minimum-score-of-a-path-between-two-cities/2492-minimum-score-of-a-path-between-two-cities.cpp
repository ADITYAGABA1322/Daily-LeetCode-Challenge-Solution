// bfs
// class Solution {
// public:
//     int bfs(int n , vector<vector<pair<int , int>>>& g){
//         vector<bool> vis(n+1);
//         queue<int> q;
//         int ans = INT_MAX;
//         q.push(1);
//         vis[1] = true;
//         while(!q.empty()){
//             auto node = q.front();
//             q.pop();
//             for(auto child : g[node]){
//                 ans = min(ans , child.second);
//                 if(!vis[child.first]){
//                     vis[child.first] = true;
//                     q.push(child.first);
//                 }
//             }
//         }
//         return ans;
//     }
//     int minScore(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int , int>>> g(n+1);
//         for(auto r : roads){
//             g[r[0]].push_back({r[1] , r[2]});
//             g[r[1]].push_back({r[0] , r[2]});
//         }
//         return bfs(n , g);
//     }
// };

// dfs
class Solution {
public:
    void dfs(int u , vector<bool>& vis , unordered_map<int , vector<pair<int , int>>>& adj ,  int& res){
        vis[u] = true;
        for(auto p: adj[u]){
            int v = p.first , d = p.second;
            res = min(res , d);
            if(!vis[v]) dfs(v , vis , adj , res);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int , int>>> adj;
        for(auto r:  roads){
            int u = r[0] , v = r[1] , d = r[2];
            adj[u].push_back({v , d});
            adj[v].push_back({u , d});
        }
        vector<bool> vis(n , false);
        int res = INT_MAX;
        dfs(1 , vis , adj , res);
        return res;
    }
};