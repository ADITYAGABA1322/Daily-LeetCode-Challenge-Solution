class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() , diff = 0;
        sort(nums.begin() , nums.end());
        for(int i=0; i<nums.size(); i++) diff += nums[i] - nums[0];
        return diff; 
    }
};