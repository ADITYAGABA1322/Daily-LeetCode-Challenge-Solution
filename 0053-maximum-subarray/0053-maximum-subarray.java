class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int res = nums[0] , curr = nums[0];
        for(int i=1; i<n; i++){
            curr = Math.max(nums[i]  , curr+nums[i]);
            res = Math.max(res , curr);
        }
        return res;
    }
}