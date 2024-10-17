class Solution {
public:
    int maximumSwap(int num) {
        string numStr =
            to_string(num);  // Convert num to string for easy manipulation
        int n = numStr.size();
        int maxNum = num;  // Track the maximum number found

        // Try all possible swaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(numStr[i], numStr[j]);  // Swap digits at index i and j
                maxNum = max(
                    maxNum,
                    stoi(numStr));  // Update maxNum if the new number is larger
                swap(numStr[i],
                     numStr[j]);  // Swap back to restore the original string
            }
        }

        return maxNum;  // Return the largest number after all possible swaps
    }
};