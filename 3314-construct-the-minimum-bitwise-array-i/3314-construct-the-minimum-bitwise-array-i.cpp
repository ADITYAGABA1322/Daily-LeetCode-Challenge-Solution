class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            for(int j=1; j<curr; j++){
                if((j | (j+1)) == nums[i]){
                    nums[i] = j;
                    break;
                }
            }
            if(nums[i] == curr) nums[i] = -1;
        }
        return nums;
    }
};