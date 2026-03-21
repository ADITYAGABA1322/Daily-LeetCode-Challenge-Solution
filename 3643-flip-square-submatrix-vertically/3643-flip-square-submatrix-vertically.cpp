class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startRow = x , endRow = x+k-1;
        int startCol = y , endCol = y+k-1;
        for(int i=startRow; i<=endRow; i++){
            for(int j=startCol; j<=endCol; j++){
                swap(grid[i][j] , grid[endRow][j]);
            }
            endRow--;
        }
        return grid;
    }
};