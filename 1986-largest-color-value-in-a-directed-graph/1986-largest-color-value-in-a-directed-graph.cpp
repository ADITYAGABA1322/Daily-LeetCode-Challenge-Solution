class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for(auto e: edges){
            g[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<vector<int>> cnt(n , vector<int>(26));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int ans = 0 , nodeSeen = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans = max(ans , ++cnt[node][colors[node] - 'a']);
            nodeSeen++;
            for(auto nei : g[node]){
                for(int i=0; i<26; i++){
                cnt[nei][i] = max(cnt[nei][i] , cnt[node][i]);
            }
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei); 
            }
            
        }
        return nodeSeen < n ? -1 : ans;
    }
};