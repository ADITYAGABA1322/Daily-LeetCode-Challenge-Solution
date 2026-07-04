class Solution {
public:
    int bfs(int n , vector<vector<pair<int , int>>>& g){
        vector<bool> vis(n+1);
        queue<int> q;
        int ans = INT_MAX;
        q.push(1);
        vis[1] = true;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto child : g[node]){
                ans = min(ans , child.second);
                if(!vis[child.first]){
                    vis[child.first] = true;
                    q.push(child.first);
                }
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> g(n+1);
        for(auto r : roads){
            g[r[0]].push_back({r[1] , r[2]});
            g[r[1]].push_back({r[0] , r[2]});
        }
        return bfs(n , g);
    }
};