class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0 , sum2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0 && nums[i] <= 9) sum1 += nums[i];
            else if(nums[i] >= 10 && nums[i] <= 99) sum2 += nums[i];
        }
        return sum1>sum2 || sum2>sum1;
    }
};