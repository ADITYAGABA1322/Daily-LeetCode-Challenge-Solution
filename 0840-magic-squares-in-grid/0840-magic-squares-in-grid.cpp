class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int row, int col) {
        vector<int> count(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
        
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; ++i) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum) return false;
            if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum) return false;
        }
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) return false;
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                if (isMagic(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};