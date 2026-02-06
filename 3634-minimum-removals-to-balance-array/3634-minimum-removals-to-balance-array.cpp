class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        if(n == 1) return 0;
        if(nums[n-1] <= (long long) nums[0] * k) return 0;
        int left = 0 , maxLen = 0;
        for(int right =0; right < n; right++){
            while(left <= right && nums[right] > (long long) nums[left] * k) left++;
            maxLen = max(maxLen , right - left + 1);
        }
        return n - maxLen;
    }
};