class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() , diff = 0;
        sort(nums.begin() , nums.end());
        int median = nums[nums.size()/2];
        for(int i=0; i<nums.size()/2; i++) //diff += abs(nums[i] - median);
        diff += nums[n-1-i] - nums[i];
        return diff;
    }
};