class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size() , cnt = 0;
        vector<vector<int>> cumX(m , vector<int>(n, 0)) , cumY(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cumX[i][j] = (grid[i][j] == 'X');
                cumY[i][j] = (grid[i][j] == 'Y');
                if(i-1 >= 0){
                     cumX[i][j] += cumX[i-1][j];
                     cumY[i][j] += cumY[i-1][j];
                }
                if(j-1 >= 0){
                    cumX[i][j] += cumX[i][j-1];
                    cumY[i][j] += cumY[i][j-1];
                }

                if(i-1>=0 && j-1>= 0){
                    cumX[i][j] -= cumX[i-1][j-1];
                    cumY[i][j] -= cumY[i-1][j-1];
                }   
                
                if(cumX[i][j] == cumY[i][j] && cumX[i][j] > 0)
                    cnt++;

             }
        }
        return cnt;
    }
};