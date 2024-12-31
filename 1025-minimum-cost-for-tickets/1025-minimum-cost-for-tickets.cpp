class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = min(dp[i] , dp[i-1]) + costs[0];
            int j = i-1;
            while(j>=0 && days[i-1] - days[j] < 7){
                dp[i] = min(dp[i] , dp[j] + costs[1]);
                j--;
            }
            j = i-1;
            while(j>=0 && days[i-1] - days[j] < 30){
                dp[i] = min(dp[i] , dp[j] + costs[2]);
                j--;
            }
        }
        return dp[n];
    }
};