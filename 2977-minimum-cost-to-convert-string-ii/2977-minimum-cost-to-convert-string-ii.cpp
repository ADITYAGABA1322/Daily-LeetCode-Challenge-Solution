class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> index;
        for(auto o : original){
            if(!index.count(o)) index[o] = index.size();
        }
        for(auto c : changed){
            if(!index.count(c)) index[c] = index.size();
        }
        int n = index.size();
        vector<vector<long>> dis(n , vector<long>(n , LONG_MAX));
        for(int i=0; i<cost.size(); i++){
         dis[index[original[i]]][index[changed[i]]] = min( dis[index[original[i]]][index[changed[i]]],(long)cost[i]);
        }
        // floyds
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
              if(dis[i][k] < LONG_MAX){
                for(int j=0; j<n; j++){
                    if(dis[k][j] < LONG_MAX){
                        dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
                    }
                }
              }
            }
        } 
        unordered_set<int> substrLen;
        for(auto o : original){
            substrLen.insert(o.length());
        }
        vector<long> dp(target.length()+1 , LONG_MAX);
        dp[0] = 0;
        for(int i=0; i<target.length(); i++){
            if(dp[i] == LONG_MAX) continue;
            if(target[i] == source[i]) dp[i+1] = min(dp[i+1] , dp[i]);
            for(auto t: substrLen){
                if(i+t >= dp.size()) continue;
                string subSource = source.substr(i , t);
                string subTarget = target.substr(i , t);
                int c1 = index.count(subSource) ? index[subSource] : -1;
                int c2 = index.count(subTarget) ? index[subTarget] : -1;
                if(c1 >=0 && c2 >=0 && dis[c1][c2] < LONG_MAX){
                    dp[i+t] = min(dp[i+t] , dp[i] + dis[c1][c2]);
                }
            }
        }
        return dp[dp.size()-1] == LONG_MAX ? -1L : dp[dp.size()-1];
    }
};