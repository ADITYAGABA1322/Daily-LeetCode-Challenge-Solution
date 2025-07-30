class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin() , nums.end());
        int max_len = 0 , curr_len = 0;
        for(auto num : nums){
            if(num == maxEle){
                curr_len++;
                max_len = max(max_len , curr_len);
            }
            else curr_len = 0;
        }
        return max_len;
    }
};