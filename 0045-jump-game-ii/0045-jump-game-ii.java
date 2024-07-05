class Solution {
    public int jump(int[] nums) {
        int jump = 0;
        int curr = 0;
        int maxIndex = 0;
        for (int i = 0; i < nums.length-1; i++) {
            maxIndex = Math.max(maxIndex, i + nums[i]);
            if (curr == i) {
                jump++;
                curr = maxIndex;
            }
        }
        return jump;
    }
}