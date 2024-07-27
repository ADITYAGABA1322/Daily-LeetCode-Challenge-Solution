#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        int dp[26][26];
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                dp[i][j] = 1e9+10;
            } 
            dp[i][i] = 0;
        }
        for(int i=0; i<cost.size(); i++){
            dp[original[i]-'a'][changed[i]-'a'] = min(dp[original[i]-'a'][changed[i]-'a'] , cost[i]);
        }
        //vector<vector<long long>> dp(26 , vector<long long>(26 , INT_MAX));
        // initialize the dp
        // for(int i=0; i<original.size(); i++){
        //     int s = original[i] - 'a' , t = changed[i] - 'a';
        //     dp[s][t] = dp[s][t] == 0 ? cost[i] : min(dp[s][t] , (long long)cost[i]);
        // }
        // floyds algo start
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
                }
            }
        }
        // check condition
        for(int i=0; i<source.size(); i++){
            if(source[i] == target[i]) continue;
            int s = source[i] - 'a' , t =  target[i] - 'a';
            if(dp[s][t] > 1e9) return -1;
            res += dp[s][t];
        }
        return res;
    }
};