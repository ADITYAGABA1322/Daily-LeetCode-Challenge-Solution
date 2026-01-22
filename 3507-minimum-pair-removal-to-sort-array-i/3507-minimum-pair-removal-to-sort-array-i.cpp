class Solution {
public:
    int minPairSum(vector<int>& nums){
        int minSum = INT_MAX;
        int index = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] < minSum){
                index = i;
                minSum = nums[i] + nums[i+1];
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        while(!is_sorted(nums.begin() , nums.end())){
            int index = minPairSum(nums);
            nums[index] = nums[index] + nums[index+1];
            nums.erase(nums.begin() + index + 1);
            op++;
        }
        return op;
    }
};