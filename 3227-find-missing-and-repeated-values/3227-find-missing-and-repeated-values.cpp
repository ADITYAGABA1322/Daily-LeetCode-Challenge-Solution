class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<int> res(n*n + 1 , 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[grid[i][j]]++;
            }
        }
        int a = 0 , b = 0;
        for(int i=1; i<=n*n; i++){
            if(res[i] == 2) a = i;
            else if (res[i] == 0) b = i;
        }
        return {a , b};
    }
};