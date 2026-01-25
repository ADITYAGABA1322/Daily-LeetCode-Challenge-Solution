class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;
        int i = 0;
        for (int j = k - 1; j < n; j++) {
            minDiff = min(minDiff, nums[j] - nums[i]);
            i++;
        }
        return minDiff;
    }
};