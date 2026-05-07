class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> lMax(n) , rMin(n);
        lMax[0] = nums[0];
        rMin[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            lMax[i] = max(nums[i] , lMax[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            rMin[i] = min(nums[i] , rMin[i+1]);
        }
        vector<int> ans(n);
        ans[n-1] = lMax[n-1];
        for(int i=n-2; i>=0; i--){
            if(lMax[i] <= rMin[i+1]) ans[i] = lMax[i];
            else ans[i] = ans[i+1];
        }
        return ans;
    }
};