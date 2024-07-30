class Solution {
public:
    int dp[101][101]{};
    int uniquePaths(int m, int n , int i=0 , int j = 0) {
        if(i>=m || j>=n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = uniquePaths(m , n , i+1, j) + uniquePaths(m , n , i , j+1);
    }
};