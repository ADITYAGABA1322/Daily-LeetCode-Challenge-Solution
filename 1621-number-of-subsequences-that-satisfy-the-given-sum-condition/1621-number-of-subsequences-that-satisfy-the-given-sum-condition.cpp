class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int cnt = 0 , MOD = 1e9+7;
        int left = 0 , right = nums.size() - 1;
        vector<long long> pow2(nums.size());
        pow2[0] = 1;
        for(int i=1; i<nums.size(); i++) pow2[i] = (pow2[i-1] * 2) % MOD;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                cnt = (cnt + pow2[right - left]) % MOD;
                left++;
            }else{
                right --;
            }            
        }
        return cnt;
    }
};