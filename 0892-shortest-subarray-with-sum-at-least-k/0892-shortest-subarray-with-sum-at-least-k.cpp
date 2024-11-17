class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Initialize result to the maximum possible integer value
        int shortestSubarrayLength = INT_MAX;

        long long cumulativeSum = 0;

        // Min-heap to store cumulative sum and its corresponding index
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            prefixSumHeap;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            cumulativeSum += nums[i];

            // If cumulative sum is already >= k, update shortest length
            if (cumulativeSum >= k) {
                shortestSubarrayLength = min(shortestSubarrayLength, i + 1);
            }

            // Remove subarrays from heap that can form a valid subarray
            while (!prefixSumHeap.empty() &&
                   cumulativeSum - prefixSumHeap.top().first >= k) {
                // Update shortest subarray length
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }

            // Add current cumulative sum and index to heap
            prefixSumHeap.emplace(cumulativeSum, i);
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};