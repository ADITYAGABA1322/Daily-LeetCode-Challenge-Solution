class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        int sz = m*n;
        k = k % sz;
        if(k == 0) return grid;
        auto reverse = [&](int i , int j){
            while(i <j){
                swap(grid[i/n][i%n] , grid[j/n][j%n]);
                i++;
                j--;
            }
        };
        reverse(0 , sz-1);
        reverse(0 , k-1);
        reverse(k , sz-1);
        return grid;
    }
};