class Solution {
public:
    vector<int> dp;
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n , -1);
        return solve(0  , n , costs);
    }
    int solve(int i , int n , vector<int>& costs){
        int ans = INT_MAX;
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
            for(int j=i+1; j<=min(i+3 , n); j++){
                int cost = costs[j-1] + (j-i)*(j-i) +  solve(j , n , costs);
                ans = min(ans , cost);
        }
        return dp[i] = ans;
    }
};