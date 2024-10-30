class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);

        // Calculate LIS for each element
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Calculate LDS for each element
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Find the minimum removals to make the array a mountain array
        int minRemovals = n;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                int mountainLength = lis[i] + lds[i] - 1;
                minRemovals = min(minRemovals, n - mountainLength);
            }
        }

        return minRemovals;
    }
};
