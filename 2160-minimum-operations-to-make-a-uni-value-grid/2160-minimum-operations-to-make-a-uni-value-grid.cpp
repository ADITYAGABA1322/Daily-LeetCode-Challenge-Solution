class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // now what we want know we want o use the median to find the value to make it them them to target and another hting if we find that val we need to make whole no simlar to either plus or either  that times tomake to eqaul to them ok. s how shoudlwe either check another no is big or smal fomr that no and how many no req to amke it eqaul that our oeraito count to return it ok fomr every no which comes in res ok
        int m = grid.size() , n = grid[0].size();
        int total = m*n; 
        vector<int> nums;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                nums.push_back(grid[i][j]);
            }
        }

        int rem = nums[0]%x;
        for(auto n : nums){
            if(n%x != rem) return -1;
        }

        sort(nums.begin() , nums.end());
        int med = nums[total/2];
        int op = 0;
        for(auto n : nums){
            op += abs(n - med)/x;
        }
        return op;
    }
};