class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return 1LL * (nums[n - 1] - nums[0]) * k;
    }
};