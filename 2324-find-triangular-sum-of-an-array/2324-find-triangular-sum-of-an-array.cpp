class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1){
            vector<int> res;
            for(int i=0; i<nums.size() - 1; i++){
                res.push_back((nums[i] + nums[i+1]) % 10);
            }
            nums = move(res);
        }
        return nums[0];
    }
};