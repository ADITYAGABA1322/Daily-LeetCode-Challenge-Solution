class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() , n = grid[0].size();
        int res = 0;
        vector<int> num;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 num.push_back(grid[i][j]);
            }
        }
        int sz = num.size();
        sort(begin(num) , end(num));
        int target = num[sz/2];
        for(auto n : num){
            if(n%x != target%x) return -1;
            res += abs(target - n) / x;
        }
        return res;
    }
};