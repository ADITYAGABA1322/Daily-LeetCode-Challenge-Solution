class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int best = INT_MAX;

        for (int len = l; len <= r; len++) {
            for (int i = 0; i + len <= n; i++) {
                int sum = 0;
                for (int k = i; k < i + len; k++)
                    sum += nums[k];
                if (sum > 0 && sum < best) best = sum;
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};