class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<int> rowCnt(m , 0) , colCnt(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1 && rowCnt[i] == 1 && colCnt[j] == 1) res++;
            }
        }
        return res;
    }
};