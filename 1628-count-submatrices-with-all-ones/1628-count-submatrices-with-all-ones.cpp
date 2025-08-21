class Solution {
public:
    int helper(vector<vector<int>>& mat , int a , int b){
        int n = mat.size() , m = mat[0].size() , cnt = 0;
        for(int i=a; i<n; i++){
            for(int j=b; j<m; j++){
                if(mat[i][j]) cnt += 1;
                else m = j;
            }
        }
        return cnt;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() , cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++) cnt += helper(mat , i , j);
        }
        return cnt;
    }
};