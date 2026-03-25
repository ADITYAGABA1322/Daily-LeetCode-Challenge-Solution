class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        long long total = 0;
        vector<long long> rSum(m , 0) , cSum(n , 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total += grid[i][j];
                rSum[i] += grid[i][j];
                cSum[j] += grid[i][j];
            }
        }
        if(total % 2 != 0) return false;
        // Horizontal Cut
        long long upper = 0;
        for(int i=0; i<m-1; i++){
            upper += rSum[i];
            if(total - upper == upper) return true;
        }

        // Vertical Split
        long long left = 0;
        for(int j=0; j<n-1; j++){
            left += cSum[j];
            if(total - left == left) return true;
        }
        return false;
    }
};