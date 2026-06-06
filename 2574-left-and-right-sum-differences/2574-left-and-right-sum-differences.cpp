class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end(), 0);
        vector<int> res(n);
        int curr =  0;
        for(int i=0; i<n; i++){
            int leftSum = curr;
            curr += nums[i];      
            int rightSum = sum - curr;
            res[i] = abs(rightSum - leftSum);
        }
        return res;
    }
};