class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>> originalMat = mat;
        for(int i=0; i<m; i++){
            if(i%2 == 0){
                leftCyclicShift(mat[i] , k , n);
            } else{
                rightCyclicShift(mat[i] , k , n);
            }
        }
        return mat == originalMat;
    }

    void leftCyclicShift(vector<int>& row , int k , int n){
        k %= n;
        reverse(row.begin() , row.begin() + k);
        reverse(row.begin()+k , row.end());
        reverse(row.begin() , row.end());
    }

    void rightCyclicShift(vector<int>& row , int k , int n){
        k %= n;
        reverse(row.begin() , row.end());
        reverse(row.begin() , row.begin() + n - k);
        reverse(row.begin() + n - k , row.end());
    }
};