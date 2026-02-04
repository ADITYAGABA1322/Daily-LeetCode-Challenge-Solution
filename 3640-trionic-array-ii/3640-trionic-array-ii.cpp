class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int p, q, j;
        long long max_sum, sum, res;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;
            // first segment
            for (; j < n && nums[j - 1] < nums[j]; j++);
            p = j - 1;
            if (p == i) {
                continue;
            }
            // second segment
            res += nums[p] + nums[p - 1];
            for (; j < n && nums[j - 1] > nums[j]; j++) {
                res += nums[j];
            }
            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }
            // third segment
            res += nums[q + 1];
            // find the maximum sum of the third segment
            max_sum = 0;
            sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            // find the maximum sum of the first segment
            max_sum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            // update answer
            ans = max(ans, res);
            i = q - 1;
        }
        return ans;
    }
};