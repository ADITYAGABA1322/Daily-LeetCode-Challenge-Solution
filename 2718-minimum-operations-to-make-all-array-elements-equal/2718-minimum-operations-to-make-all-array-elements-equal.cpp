#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // Sort nums to efficiently calculate operations needed for each query
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<long long> prefixSum(n + 1, 0);
        vector<long long> result(m, 0);

        // Calculate prefix sum for nums to use in operations calculation
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // For each query, calculate the minimum operations required
        for (int i = 0; i < m; ++i) {
            int query = queries[i];
            // Binary search to find the first element in nums not less than the query
            int pos = lower_bound(nums.begin(), nums.end(), query) - nums.begin();
            // Calculate operations needed for elements less than the query
            long long opsLeft = 1LL * query * pos - prefixSum[pos];
            // Calculate operations needed for elements greater than or equal to the query
            long long opsRight = (prefixSum[n] - prefixSum[pos]) - 1LL * query * (n - pos);
            result[i] = opsLeft + opsRight;
        }

        return result;
    }
};