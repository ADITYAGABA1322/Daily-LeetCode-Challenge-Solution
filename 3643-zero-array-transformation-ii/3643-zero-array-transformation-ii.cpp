class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();

        // Zero array isn't formed after all queries are processed
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        // Return earliest query that zero array can be formed
        return left;
    }

private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries,
                          int k) {
        int n = nums.size(), sum = 0;
        vector<int> differenceArray(n + 1);

        // Process query
        for (int queryIndex = 0; queryIndex < k; queryIndex++) {
            int start = queries[queryIndex][0], end = queries[queryIndex][1],
                val = queries[queryIndex][2];

            // Process start and end of range
            differenceArray[start] += val;
            differenceArray[end + 1] -= val;
        }

        // Check if zero array can be formed
        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex]) return false;
        }
        return true;
    }
};