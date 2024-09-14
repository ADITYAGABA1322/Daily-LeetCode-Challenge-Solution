#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& arr) {
        if (arr.empty()) return 0; // Handle empty array case

        // Find the maximum element
        int maxElement = *std::max_element(arr.begin(), arr.end());

        // Find the longest contiguous subarray of the maximum element
        int maxLength = 0;
        int currentLength = 0;

        for (int num : arr) {
            if (num == maxElement) {
                currentLength++;
                maxLength = std::max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }

        return maxLength;
    }
};