class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // Stores the current index of each list
        vector<int> indices(k, 0);
        // To track the smallest range
        vector<int> range = {0, INT_MAX};

        while (true) {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

            // Find the current minimum and maximum values across the lists
            for (int i = 0; i < k; i++) {
                int currentElement = nums[i][indices[i]];

                // Update the current minimum
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }

                // Update the current maximum
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }

            // Update the range if a smaller one is found
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            // Move to the next element in the list that had the minimum value
            if (++indices[minListIndex] == nums[minListIndex].size()) break;
        }

        return range;
    }
};