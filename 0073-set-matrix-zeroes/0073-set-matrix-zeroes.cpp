class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        // isRow and isCol two thing used when we find 0 means acc to zero we need to this isRow to 0 and isCol to 0 ok 
        bool isRow = false , isCol = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) isRow = true; 
                    if(j == 0) isCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(isRow){
            for(int i=0; i<n; i++) matrix[0][i] = 0;
        }
        if(isCol){
            for(int j=0; j<m; j++) matrix[j][0] = 0;
        }
    }
};