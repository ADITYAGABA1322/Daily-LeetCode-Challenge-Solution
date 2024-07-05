class Solution {
    public boolean canJump(int[] nums) {
        int n  = nums.length;
        int maxReach  = 0;
        for(int i=0; i<n; i++){
            if(i>maxReach) return false;
            maxReach = Math.max(maxReach , i+nums[i]);
        }
        return true;
    }
}