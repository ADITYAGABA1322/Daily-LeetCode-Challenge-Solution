class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sum = 0;
        for(int i : nums) sum += i;
        int start = 0 , curr = 0 , maxLen = 0 ;
        int target = sum - x;
        boolean found = false;
        for(int end = 0 ; end < n ; end++){
            curr += nums[end];
            while(start <= end &&  curr > target){
                curr -= nums[start];
                start += 1;
            }
            if(curr == target){
                found =  true;
                maxLen = Math.max(maxLen , end - start + 1);
            }
        }
        return found ? n-maxLen : -1;
    }
}