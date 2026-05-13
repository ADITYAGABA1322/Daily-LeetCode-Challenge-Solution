class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int target = a + b;

            // default: 2 moves for all sums [2, 2*limit]
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 1 move for sums [low, high]
            diff[low] -= 1;
            diff[high + 1] += 1;

            // 0 moves for exact sum target
            diff[target] -= 1;
            diff[target + 1] += 1;
        }

        int res = INT_MAX;
        int curr = 0;

        for (int sum = 2; sum <= 2 * limit; sum++) {
            curr += diff[sum];
            res = min(res, curr);
        }

        return res;
    }
};