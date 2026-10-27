class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));

        for(int i=0;i<n;i++){
            grid[0][i]='.';
        }
        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        return grid;
    }
};