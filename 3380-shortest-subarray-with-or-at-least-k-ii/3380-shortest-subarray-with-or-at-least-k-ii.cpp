class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1;
        int right = nums.size();
        int minLength = -1;

        // Binary search on the length of subarray
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasValidSubarray(nums, k, mid)) {
                minLength = mid;
                right = mid - 1;  // Try to find smaller length
            } else {
                left = mid + 1;  // Try larger length
            }
        }

        return minLength;
    }

private:
    // Checks if there exists a subarray of given length whose bitwise OR is >=
    // k
    bool hasValidSubarray(vector<int>& nums, int targetSum, int windowSize) {
        int arrayLength = nums.size();
        vector<int> bitCounts(32,
                              0);  // Tracks count of set bits at each position

        // Sliding window approach
        for (int right = 0; right < arrayLength; right++) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[right], 1);

            // Remove leftmost number if window exceeds size
            if (right >= windowSize) {
                updateBitCounts(bitCounts, nums[right - windowSize], -1);
            }

            // Check if current window is valid
            if (right >= windowSize - 1 &&
                convertBitCountsToNumber(bitCounts) >= targetSum) {
                return true;
            }
        }
        return false;
    }

    // Updates bit count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if (((number >> bitPosition) & 1) != 0) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    int convertBitCountsToNumber(vector<int>& bitCounts) {
        int number = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                number |= 1 << bitPosition;
            }
        }
        return number;
    }
};