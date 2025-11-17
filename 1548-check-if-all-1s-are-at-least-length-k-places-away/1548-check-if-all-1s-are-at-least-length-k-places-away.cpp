class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev_one = -k-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                if (i - prev_one <= k) return false;
                prev_one = i;
            }
        }
        return true;
    }
};