class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix.size();
        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++)  swap(matrix[i][j] , matrix[j][i]);
        }
        for(int i=0; i<m; i++) reverse(matrix[i].begin() , matrix[i].end());
    }
};