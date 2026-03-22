class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size() , n = mat[0].size();
        // Only rotate 4 times
        for(int i=0; i<4; i++){
            if(isEqual(mat , target)) return true;
            rotate(mat);
        }
        return false;
    }

    void rotate(vector<vector<int>>& mat){
        int m = mat.size();
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
        for(int i=0; i<m; i++){
            reverse(mat[i].begin() , mat[i].end());
        }
    }

    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b){
        return a == b;
    }
};