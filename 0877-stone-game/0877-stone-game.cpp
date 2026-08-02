class Solution {
public:
    // int dp[501][501];
    // bool stoneGame(vector<int>& piles) {
    //     int n = piles.size();
    //     memset(dp , -1 , sizeof(dp));
    //     return solve(0 , n-1 , piles);
    // }
    // int solve(int i , int j, vector<int>& piles){
    //     if(i>j) return 0;
    //     if(i == j) return piles[i];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int take_i = piles[i] + solve(i+1 , j , piles); 
    //     int take_j = piles[j] + solve(i , j-1, piles);
    //     return dp[i][j] = max(take_i, take_j);
    // }

    //  bool stoneGame(vector<int>& piles) {
    //     int n = piles.size();
    //     vector<vector<int>> dp(n , vector<int>(n , 0));
    //     for(int i=n-1; i>=0; i--){
    //         dp[i][i] = piles[i];
    //         for(int j=i+1; j<n; j++){
    //             dp[i][j] = max(piles[i] - dp[i+1][j] , piles[j] - dp[i][j-1]);
    //         }
    //     }
    //     return dp[0][n-1] >= 0;
    //  }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for(int i=n-1; i>=0; i--){
            dp[i] = piles[i];
            for(int j=i+1; j<n; j++){
                dp[j] = max(piles[i] - dp[j] , piles[j] - dp[j-1]);
            }
        }
        return dp[n-1] > 0;
    }
};