class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_cnt = 0 , desc_cnt = 0;
        for(int i=1; i<n; i++){
            asc_cnt += (nums[i] == (nums[i-1]+1) % n);
            desc_cnt += (nums[i-1] == (nums[i] + 1)%n);
        }
        if(asc_cnt == n-1 && nums[0] == 0) return 0;
        if(asc_cnt == n-1){
            int leftR = n - nums[0];
            int rightR = 1 + (nums.back()+1) + 1;
            return min(leftR , rightR);
        }
        if(desc_cnt == n-1){
            int leftR = n - nums.back() + 1;
            int rightR = (nums[0]+1)%n + 1;
            return min(leftR , rightR);
        }
        return -1;
    }
};