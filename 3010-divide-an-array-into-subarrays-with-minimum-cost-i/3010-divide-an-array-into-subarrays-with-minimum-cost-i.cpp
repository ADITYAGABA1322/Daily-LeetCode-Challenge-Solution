class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for(int i = 1; i < n; i++){
            if(nums[i] < firstMin){
                secondMin = firstMin;       // push old first down to second
                firstMin = nums[i];
            }
            else if(nums[i] < secondMin){
                secondMin = nums[i];
            }
        }
        return nums[0] + firstMin + secondMin;
    }
};