class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , 0));
        for(int j=n-2; j>=0; j--){
            for(int i=0;i<m; i++){
                if(grid[i][j] < grid[i][j+1]) dp[i][j]=max(dp[i][j] , dp[i][j+1] + 1);
                if(i>0 && grid[i][j] < grid[i-1][j+1])  dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                if(i<m-1 && grid[i][j] <  grid[i+1][j+1])   dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
            } 
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            cnt = max(cnt , dp[i][0]);
        }
        return cnt;
    }
};