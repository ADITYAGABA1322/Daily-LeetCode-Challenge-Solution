class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt = 0 , m = grid.size() , n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1 >= 0) grid[i][j] += grid[i-1][j];
                if(j-1 >= 0) grid[i][j] += grid[i][j-1];
                if(i-1 >= 0  && j-1 >= 0) grid[i][j] -= grid[i-1][j-1];
                if(grid[i][j] <= k) cnt++;
            }
        }
        return cnt;
    }
};