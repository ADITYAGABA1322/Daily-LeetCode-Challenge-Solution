class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][r] = number of paths to (i,j) with sum % k = r
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));
        
        // Base case: starting position
        dp[0][0][grid[0][0] % k] = 1;
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            for (int r = 0; r < k; r++) {
                int newRemainder = (r + grid[0][j]) % k;
                dp[0][j][newRemainder] = (dp[0][j][newRemainder] + dp[0][j-1][r]) % MOD;
            }
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            for (int r = 0; r < k; r++) {
                int newRemainder = (r + grid[i][0]) % k;
                dp[i][0][newRemainder] = (dp[i][0][newRemainder] + dp[i-1][0][r]) % MOD;
            }
        }
        
        // Fill rest of the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    // New remainder after adding current cell
                    int newRemainder = (r + grid[i][j]) % k;
                    
                    // Paths coming from top
                    dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i-1][j][r]) % MOD;
                    
                    // Paths coming from left
                    dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i][j-1][r]) % MOD;
                }
            }
        }
        
        return dp[m-1][n-1][0];
    }
};