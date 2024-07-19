class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n= nums.length;
        HashMap<Integer , Integer> m = new HashMap<>();
        for(int i=0; i<n; i++){
            if(m.containsKey(nums[i])){
                return new int[] {m.get(nums[i]) , i};
            }
            m.put(target - nums[i] , i);
        }
        return new int[]{};
    }
}