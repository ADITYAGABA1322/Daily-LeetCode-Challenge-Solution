class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> res(m-k+1 , vector<int>(n-k+1 , 0));
        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                set<int> val;
                for(int r=i; r<=i+k-1; r++){
                    for(int c=j; c<=j+k-1; c++){
                        val.insert(grid[r][c]);
                    }
                }
                if(val.size() == 1){
                    res[i][j] = 0;
                    continue;
                }
                int minDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);
                while(curr != val.end()){
                    minDiff = min(minDiff , *curr - *prev);
                    prev = curr;
                    curr++;
                }
                res[i][j] = minDiff;
            }
        }
        return res;
    }
};