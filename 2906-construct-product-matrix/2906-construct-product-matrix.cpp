class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int mod = 12345;
        vector<vector<int>> p(m , vector<int>(n , 1));
        long long prefix = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                p[i][j] = (p[i][j] * prefix) % mod; 
                prefix = (prefix * grid[i][j]) % mod;
            }
        }

        long long suffix = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                p[i][j] = (p[i][j] * suffix) % mod;
                suffix = (suffix * grid[i][j]) % mod;
            }
        }
        return p;
    }
};