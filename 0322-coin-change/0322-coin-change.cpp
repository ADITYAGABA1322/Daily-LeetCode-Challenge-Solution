class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1 , 1e9);
        // dp[0] = 0;  
        // for(int coin : coins){
        //      for(int i=coin; i<=amount; i++){
        //         dp[i] = min(dp[i] , dp[i-coin] + 1);
        //     }
        // }
        // return dp[amount]== 1e9 ? -1 : dp[amount];
        vector<int> dp(amount+1 , 1e9);
        dp[0] = 0;
        for(auto c : coins){
            for(int i=c; i<=amount; i++){
                dp[i] = min(dp[i] , dp[i-c] + 1);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};