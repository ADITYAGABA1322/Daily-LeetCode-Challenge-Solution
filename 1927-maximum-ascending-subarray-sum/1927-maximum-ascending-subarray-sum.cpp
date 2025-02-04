class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0] , curSum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) curSum += nums[i];
            else {
                maxi = max(maxi , curSum);
                curSum = nums[i];
            }
        }
        maxi = max(maxi , curSum);
        return maxi;
    }
};