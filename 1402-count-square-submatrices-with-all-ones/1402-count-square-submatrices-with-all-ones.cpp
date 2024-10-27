class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // If the cell lies outside the grid, return 0.
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        // If we have already visited this cell, return the memoized value.
        if (dp[i][j] != -1) return dp[i][j];

        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, grid, dp);
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, grid, dp);
        // Find the answer for the cell below the current cell.
        int below = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + min(right, min(diagonal, below));
    }

    int countSquares(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += solve(i, j, grid, dp);
            }
        }
        return ans;
    }
};