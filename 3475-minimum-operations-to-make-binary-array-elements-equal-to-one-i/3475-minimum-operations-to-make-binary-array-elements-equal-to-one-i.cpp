class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() , res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                if(i+2 < n){
                    nums[i] = 1;
                    nums[i+1] = nums[i+1] ? 0 : 1;
                    nums[i+2] = nums[i+2] ? 0 : 1;
                    res++;
                }
                else{
                    return -1;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] == 0) return -1;
        }
        return res;
    }
};