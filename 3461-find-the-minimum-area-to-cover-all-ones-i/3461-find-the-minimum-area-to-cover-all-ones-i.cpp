class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int min_i = m , max_i = 0 , min_j = n,  max_j = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 ){
                    min_i = min(min_i , i);
                    max_i = max(max_i , i);
                    min_j = min(min_j , j);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i +1) * (max_j  - min_j + 1);
    }
};